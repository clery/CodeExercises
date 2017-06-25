#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "array.h"

int binary_search(int *array, size_t size, int n);

static size_t array_size = 20;
static int minimum_number = 0;
static size_t maximum_gap = 10;
int verbose_flag = 0;

static int display_usage()
{
  printf(
      "Usage : search [options]\n"
      "Search through an int array via binary search.\n"
      "Options\n"
      "  -s, --size=NUMBER\tdefines the size of the array\n"
      "  -m, --min=NUMBER\tdefines the minimum value of the array\n"
      "  -g, --gap=NUMBER\tdefines the maximum gap between two values of the array\n"
      "  -v, --verbose\tactivates verbose mode\n"
      "  -h, --help\t\tdisplays this usage and quit\n");
}

static int parse_options(int ac, char **av)
{
  char c;
  int opt_index = 0;
  struct option long_options[] =
      {
          /* These options set a flag. */
          {"verbose", no_argument, 0, 'v'},
          {"size", required_argument, 0, 's'},
          {"min", required_argument, 0, 'm'},
          {"gap", required_argument, 0, 'g'},
          {"help", no_argument, 0, 'h'},
          {0, 0, 0, 0}};

  while ((c = getopt_long(ac, av, "s:m:g:vh?", long_options, &opt_index)) != -1)
  {
    switch (c)
    {
    case 's':
      for (int i = 0; optarg[i]; ++i)
        if (!isdigit(optarg[i]) && (optarg[i] != '-' || i == 0))
        {
          fprintf(stderr, "Option -s requires a positive number.\n");
          return (1);
        }
      array_size = atoi(optarg);
      break;
    case 'm':
      for (int i = 0; optarg[i]; ++i)
        if (!isdigit(optarg[i]) && (optarg[i] != '-' && i == 0))
        {
          fprintf(stderr, "Option -m requires a number.\n");
          return (1);
        }
      minimum_number = atoi(optarg);
      break;
    case 'v':
      verbose_flag = 1;
      break;
    case 'g':
      for (int i = 0; optarg[i]; ++i)
        if (!isdigit(optarg[i]) && (optarg[i] != '-' || i == 0))
        {
          fprintf(stderr, "Option -g requires a positive number.\n");
          return (1);
        }
      maximum_gap = atoi(optarg);
      break;
    case '?':
    case 'h':
      display_usage();
      return (1);
    default:
      abort();
    }
  }
}

int main(int ac, char **av)
{
  int *arr;
  int x;

  if (parse_options(ac, av) == 1)
    return (0);
  srand(time(NULL));
  arr = generate_array(array_size, minimum_number, maximum_gap);
  if (arr == NULL)
    return (1);
  printf("Searching through an array of size %zu starting at %d\n",
         array_size, minimum_number);
  if (verbose_flag)
    display_array(arr, array_size);
  printf("What number would you like to search for ? ");
  scanf("%d", &x);
  printf("Index is %d\n", binary_search(arr, array_size, x));
  free(arr);
  return (0);
}