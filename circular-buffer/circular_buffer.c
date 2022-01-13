#include "circular_buffer.h"

circular_buffer_t *new_circular_buffer(size_t capacity)
{
	static circular_buffer_t buffer;

	buffer.capacity = capacity + RESERVED_SPACE;
	buffer.array = malloc(sizeof(buffer.array) * (buffer.capacity));
	buffer.head = 0;
	buffer.tail = 0;

	if (buffer.array == NULL)
		exit(EXIT_FAILURE);


	return &buffer;
}
int16_t read(circular_buffer_t *buffer, buffer_value_t *read_value)
{
	size_t next;

	if (buffer->head == buffer->tail) {
		errno = ENODATA;
		return EXIT_FAILURE;
	}

	next = buffer->tail + 1;
	if (next >= buffer->capacity)
		next = 0;

	*read_value = buffer->array[buffer->tail];
	buffer->tail = next;

	return 0;
}
int16_t write(circular_buffer_t *buffer, buffer_value_t value)
{
	size_t next;

	next = buffer->head + 1;
	if (next >= buffer->capacity)
		next = 0;

	if (next == buffer->tail) {
		errno = ENOBUFS;
		return EXIT_FAILURE;
	}

	buffer->array[buffer->head] = value;
	buffer->head = next;

	return 0;
}
int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value)
{
	size_t next;

	next = buffer->head + 1;
	if (next >= buffer->capacity)
		next = 0;

	if (next != buffer->tail) {
		write(buffer, value);

	} else {
		buffer_value_t read_value;
		read(buffer, &read_value);
		write(buffer, value);
	}

	return 0;
}
void clear_buffer(circular_buffer_t *buffer)
{
	buffer->head = 0;
	buffer->tail = 0;
}
void delete_buffer(circular_buffer_t *buffer)
{
	free(buffer->array);
	buffer = NULL;
}