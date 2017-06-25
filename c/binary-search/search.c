#include <stdlib.h>
#include <stdio.h>
#include "array.h"

extern int verbose_flag;

int binary_search(int *array, size_t size, int n)
{
  int res;
  int *tmp = array;
  size_t size_mod;
  static size_t i = 0;

  i++;
  if (verbose_flag)
  {
    printf("Iteration %zu\n", i);
    printf("Array has a size of %zu\n", size);
    display_array(array, size);
    printf("--------------------------\n");
  }
  if (array[size / 2] == n)
    res = size / 2;
  else if (size <= 1)
    res = -1;
  else
  {
    size_mod = 0;
    if (n > array[size / 2])
    {
      tmp += size / 2 + 1;
      size_mod = (size % 2 ? 0 : 1);
    }
    res = binary_search(tmp, size / 2 - size_mod, n);
    res += (res == -1 || n < array[size / 2] ? 0 : size / 2 + 1);
  }
  return (res);
}