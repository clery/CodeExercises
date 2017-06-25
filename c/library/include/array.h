#ifndef ARRAY_H_
#define ARRAY_H_

#include <stdlib.h>

int display_array(int *arr, size_t size);
int *generate_array(size_t size, int min, size_t gap);
void shuffle_array(int *array, size_t n);
int *arrcat(int *arr1, size_t s1, int *arr2, size_t s2);

#endif /* ARRAY_H_ */