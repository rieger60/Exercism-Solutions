#include "list_ops.h"

list_t *new_list(size_t length, list_element_t elements[])
{
	list_t *list = malloc(sizeof(list_t) + sizeof(list_element_t) * length);

	if (list == NULL)
		exit(EXIT_FAILURE);

	list->length = length;

	for (size_t i = 0; i < length; i++)
		list->elements[i] = elements[i];

	return list;
}

list_t *append_list(list_t *list1, list_t *list2)
{
	size_t length = list1->length + list2->length;
	list_t *list = malloc(sizeof(list_t) + sizeof(list_element_t) * length);

	if (list == NULL)
		exit(EXIT_FAILURE);

	list->length = length;

	for (size_t i = 0, count = 0; i < length; i++) {
		if (i < list1->length)
			list->elements[i] = list1->elements[i];
		else
			list->elements[i] = list2->elements[count++];
	}

	return list;
}

list_t *filter_list(list_t *list, bool (*filter)(list_element_t))
{
	size_t length = 0;
	list_t *f_list = malloc(sizeof(list_t) + sizeof(list_element_t) * length);
	f_list->length = length;

	if (f_list == NULL)
		exit(EXIT_FAILURE);

	for (size_t i = 0; i < list->length; i++) {
		if (filter(list->elements[i])) {
			length++;
			f_list = realloc(f_list, sizeof(list_t) + sizeof(list_element_t) * length);
			if (f_list == NULL)
				exit(EXIT_FAILURE);
			f_list->length = length;
			f_list->elements[length - 1] = list->elements[i];
		}
	}

	return f_list;
}

size_t length_list(list_t *list)
{
	return list->length;
}

list_t *map_list(list_t *list, list_element_t (*map)(list_element_t))
{
	list_t *m_list = malloc(sizeof(list_t) + sizeof(list_element_t) * length_list(list));

	if (m_list == NULL)
		exit(EXIT_FAILURE);

	m_list->length = length_list(list);

	for (size_t i = 0; i < length_list(list); i++) {
		m_list->elements[i] = map(list->elements[i]);
	}

	return m_list;
}

list_element_t foldl_list(list_t *list, list_element_t initial,
	list_element_t (*foldl)(list_element_t,
		list_element_t))
{
	list_element_t element = initial;
	for (size_t i = 0; i < length_list(list); i++) {
		element = foldl(list->elements[i], element);
	}

	return element;
}

list_element_t foldr_list(list_t *list, list_element_t initial,
	list_element_t (*foldr)(list_element_t,
		list_element_t))
{
	list_element_t element = initial;
	for (size_t i = length_list(list); i > 0; i--) {
		element = foldr(list->elements[i-1], element);
	}

	return element;
}

list_t *reverse_list(list_t *list)
{
	list_t *r_list = malloc(sizeof(list_t) + sizeof(list_element_t) * length_list(list));

	if (r_list == NULL)
		exit(EXIT_FAILURE);

	r_list->length = length_list(list);
	size_t last = length_list(list) - 1;
	for (size_t i = 0; i < length_list(list); i++) {
		r_list->elements[last--] = list->elements[i];
	}

	return r_list;


}

void delete_list(list_t *list)
{
	free(list);
}