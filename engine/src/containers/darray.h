#pragma once

#include "defines.h"

/*
Memory layout
u64 capacity = number of elements that can be held
u64 length = numbber of elements currently contained
u64 stride = size of each element in bytes
void* elements
*/

enum {
    DARRAY_CAPACITY,
    DARRAY_LENGTH,
    DARRAY_STRIDE,
    DARRAY_FIELD_LENGTH,
};

AAPI void* _darray_create(u64 length, u64 stride);
AAPI void _darray_destroy(void* darray);

AAPI u64 _darray_field_get(void* darray, u64 field);
AAPI void _darray_field_set(void* darray, u64 field, u64 value);

AAPI void* _darray_resize(void* array);

AAPI void* _darray_push(void* array, const void* value_ptr);
AAPI void _darray_pop(void* array, void* dest);

AAPI void* _darray_pop_at(void* array, u64 index, void* dest);
AAPI void* _darray_insert_at(void* array, u64 index, void* value_ptr);

#define DARRAY_DEFAULT_CAPACITY 1
#define DARRAY_RESIZE_FACTOR 2

#define darray_create(type) \
    _darray_create(DARRAY_DEFAULT_CAPACITY, sizeof(type))

#define darray_reserve(type, capacity) \
    _darray_create(capacity, sizeof(type))

#define darray_destroy(array) _darray_destroy(array)

#define darray_push(array, value) {     \
    typeof(value) temp = value;         \
    array = _darray_push(array, &temp); \
}
// NOTE: could use the __auto_type for temp above, but intellisense
// for VSCode flags it as an unknown type. typeof() seems to
// work just fine, though. Both are GNU extensions.

#define darray_pop(array, value_ptr) _darray_pop(array, value_ptr)

#define darray_insert_at(array, index, value) {     \
    typeof(value) temp = value;                     \
    array = _darray_insert_at(array, index, &temp); \
}

#define darray_pop_at(array, index, value_ptr) _darray_pop_at(array, index, value_ptr)

#define darray_clear(array) \
    _darray_field_set(array, DARRAY_LENGTH, 0)

#define darray_capacity(array) \
    _darray_field_get(array, DARRAY_CAPACITY)

#define darray_length(array) \
    _darray_field_get(array, DARRAY_LENGTH)

#define darray_stride(array) \
    _darray_field_get(array, DARRAY_STRIDE)

#define darray_length_set(array, value) \
    _darray_field_set(array, DARRAY_LENGTH, value)