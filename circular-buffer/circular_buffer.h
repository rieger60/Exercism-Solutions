#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#define RESERVED_SPACE 1

#include <stdlib.h>
#include <stdint.h>
#include <errno.h>

typedef int buffer_value_t;

typedef struct {
	buffer_value_t *array;
	size_t capacity;
	size_t head;
	size_t tail;
} circular_buffer_t;


circular_buffer_t *new_circular_buffer(size_t capacity);
int16_t read(circular_buffer_t *buffer, buffer_value_t *read_value);
int16_t write(circular_buffer_t *buffer, buffer_value_t value);
int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value);
void clear_buffer(circular_buffer_t *buffer);
void delete_buffer(circular_buffer_t *buffer);

#endif
