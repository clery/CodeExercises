#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int display_array(int *arr, size_t size) {
  char nb1[13];
  char nb2[13];

  for (size_t i = 0; i < size; ++i) {
    printf("%d", arr[i]);
    if (i % 5 == 4)
      printf("\n");
    else {
      sprintf(nb1, "%d", arr[size - 1]);
      sprintf(nb2, "%d", arr[i]);
      if (strlen(nb1) > 7 && strlen(nb2) <= 7)
        printf("\t");
      printf("\t");
    }
  }
  printf("\n");
}

int *generate_array(size_t size, int min, size_t gap) {
  int *arr;

  if ((arr = malloc(sizeof(int) * size)) == NULL)
    return (NULL);
  for (size_t i = 0; i < size; ++i) {
    arr[i] = min;
    min += rand() % gap + 1;
    if (i && arr[i] < arr[i - 1]) {
      fprintf(stderr, "Gap is too large.\n");
      return (NULL);
    }
  }
  return (arr);
}
