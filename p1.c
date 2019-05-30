/*
 * Problem 1 in Assignment 2
 * COMP20007 Design of Algorithms
 * Semester 1 2019
 *
 * Written by: [ YOUR NAME HERE ]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* --- DO NOT CHANGE THE CODE BELOW THIS LINE --- */

void problem_1_a();
void problem_1_b();
void print_usage_and_exit(char **argv);

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    print_usage_and_exit(argv);
  }

  /* If the argument provided is "a" then run problem_1_a(),
   * run problem_1_b() for "b", and fail otherwise. */
  if (strcmp(argv[1], "a") == 0)
  {
    problem_1_a();
  }
  else if (strcmp(argv[1], "b") == 0)
  {
    problem_1_b();
  }
  else
  {
    print_usage_and_exit(argv);
  }

  return 0;
}

/* Print the usage information and exit the program. */
void print_usage_and_exit(char **argv)
{
  fprintf(stderr, "usage: %s [ab]\n", argv[0]);
  exit(EXIT_FAILURE);
}

/* --- DO NOT CHANGE 
THE CODE ABOVE THIS LINE --- */

/* TODO: Implement your solution to Problem 1.a. in this function. */
void heap(int arr[], int n, int i)
{
  int left;
  int right;
  int max;
  int temp;
  left = 2 * i + 1;
  right = 2 * i + 2;
  if (left < n && arr[left] > arr[i])
  {
    max = left;
  }
  else
  {
    max = i;
  }
  if (right < n && arr[right] > arr[max])
  {
    max = right;
  }
  if (max != i)
  {
    temp = arr[i];
    arr[i] = arr[max];
    arr[max] = temp;
    heap(arr, n, max);
  }
  }



void problem_1_a()
{
  int i = 0;
  int n;
  // scan the number of inputs
  scanf("%d", &n);
  int arr[n];
  while (scanf("%d", &arr[i]) == true)
  {
    i++;
  }
  for (i = (n - 1) / 2; i >= 0; i--)
  {
    heap(arr, n, i);
  }
  // output the numbers that is put into a max heap structure
  for (i = 0; i < n; i++)
  {
    printf("%d\n", arr[i]);
  }
}

/* TODO: Implement your solution to Problem 1.b. in this function. */
void problem_1_b()
{
  int i = 0;
  int n;
  // scan the number of inputs
  scanf("%d", &n);
  int arr[n];
  while (scanf("%d", &arr[i]) == true)
  {
    i++;
  }
  for (i = (n - 1) / 2; i >= 0; i--)
  {
    heap(arr, n, i);
  }
  for (i = 0; i < n; i++)
  {
    printf("%d\n", arr[i]);
  }
}