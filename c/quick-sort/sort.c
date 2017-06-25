#include <stdlib.h>
#include <stdio.h>

extern int verbose_flag;

static void swap(int *a, int *b)
{
  int c;

  c = *a;
  *a = *b;
  *b = c;
}

void quick_sort(int *arr, size_t size)
{
  size_t li;
  size_t ri;
  size_t pivot;

  pivot = size / 2;
  li = 0;
  ri = size - 1;
  if (verbose_flag)
  {
    printf("\nQuick sorting:\n");
    display_array(arr, size);
  }
  while (li < ri)
  {
    if (verbose_flag)
    {
      printf("---------------------\n");
      printf("Pivot index is %zu, value is %d\n", pivot, arr[pivot]);
      printf("Left index is %zu, value is %d\n", li, arr[li]);
      printf("Right index is %zu, value is %d\n", ri, arr[ri]);
    }
    if (arr[li] >= arr[pivot] && arr[ri] <= arr[pivot])
    {
      if (verbose_flag)
        printf("!!!-----SWAP------!!!\n");
      swap(arr + li, arr + ri);
      if (verbose_flag)
        display_array(arr, size);
      if (li == pivot)
        pivot = ri;
      else if (ri == pivot)
        pivot = li;
    }
    if (arr[li] < arr[pivot])
      ++li;
    if (arr[ri] > arr[pivot])
      --ri;
  }
  if (pivot > 1)
  {
    quick_sort(arr, pivot);
    if (verbose_flag)
    {
      printf("\nResult of quick sorting:\n");
      display_array(arr, size);
    }
  }
  if (size - pivot - 1 > 1)
  {
    quick_sort(arr + pivot + 1, size - pivot - 1);
    if (verbose_flag)
    {
      printf("\nResult of quick sorting:\n");
      display_array(arr, size);
    }
  }
}

// 1 2 1 1 1 3