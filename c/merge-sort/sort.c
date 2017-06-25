#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "array.h"

int *merge(int *arr1, size_t s1, int *arr2, size_t s2)
{
  int *arr_cpy1;
  int *arr_cpy2;
  int *tmp;
  int *res;

  arr_cpy1 = arrcat(arr1, s1, 0, 0);
  arr_cpy2 = arrcat(arr2, s2, 0, 0);
  if (s1 == 0)
  {
    free(arr_cpy1);
    return (arr_cpy2);
  }
  else if (s2 == 0)
  {
    free(arr_cpy2);
    return (arr_cpy1);
  }
  if (arr1[0] <= arr2[0])
  {
    tmp = merge(arr_cpy1 + 1, s1 - 1, arr_cpy2, s2);
    res = arrcat(arr_cpy1, 1, tmp, s1 + s2 - 1);
  }
  else if (arr1[0] > arr2[0])
  {
    tmp = merge(arr_cpy2 + 1, s2 - 1, arr1, s1);
    res = arrcat(arr_cpy2, 1, tmp, s1 + s2 - 1);
  }
  free(arr_cpy1);
  free(arr_cpy2);
  free(tmp);
  return (res);
}

int *merge_sort(int *arr, size_t size)
{
  int *tmp1;
  int *tmp2;
  int *res;

  if (size <= 1)
    return (arrcat(arr, size, 0, 0));
  tmp1 = merge_sort(arr, size / 2);
  tmp2 = merge_sort(arr + size / 2, size - size / 2);
  res = merge(tmp1, size / 2, tmp2, size - size / 2);
  free(tmp1);
  free(tmp2);
  return (res);
}