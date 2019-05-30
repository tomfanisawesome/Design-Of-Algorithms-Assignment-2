/*
 * Problem 2 in Assignment 2
 * COMP20007 Design of Algorithms
 * Semester 1 2019
 *
 * Written by: [ YOUR NAME HERE ]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* --- DO NOT CHANGE THE CODE BELOW THIS LINE --- */

void problem_2_a();
void problem_2_b();
void print_usage_and_exit(char **argv);

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    print_usage_and_exit(argv);
  }

  /* If the argument provided is "a" then run problem_2_a(),
   * run problem_2_b() for "b", and fail otherwise. */
  if (strcmp(argv[1], "a") == 0)
  {
    problem_2_a();
  }
  else if (strcmp(argv[1], "b") == 0)
  {
    problem_2_b();
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

/* --- DO NOT CHANGE THE CODE ABOVE THIS LINE --- */

/* TODO: Implement your solution to Problem 2.a. in this function. */
void problem_2_a()
{
  int num_nodes, i, j, node_out_degree;
  int INFI = 999;
  //scan for the number of nodes from first line
  scanf("%d", &num_nodes);
  //create an array to track the shortest distance from node 0 to node destination
  int distance[num_nodes];
  int counter=0;
  int path[num_nodes];
  
  // set the distance of all vertices to Infinity
  for (i = 1; i < num_nodes; i++)
  {
    distance[i] = INFI;
  }

  // set the distance of source node to 0
  distance[0] = 0;

  // for each vertex scan for the weight of neighbour of each node
  for (i = 0; i < num_nodes; i++)
  {
    scanf("%d", &node_out_degree);
    int size = 2 * node_out_degree;
    int adj[size];
    //store the neighbouring nodes and its path weight into a new array
    for (j = 0; j < node_out_degree; j++)
    {
      int node;
      int weight;
      scanf("%d%d", &node, &weight);
      adj[2 * j] = node;
      adj[2 * j + 1] = weight;
    }

    for (j = 0; j < node_out_degree; j++)
    {
      if (distance[adj[2 * j]] > distance[i] + adj[2 * j + 1])
      {
        distance[adj[2 * j]] = distance[i] + adj[2 * j + 1];
        path[j]=adj[2*j];
      }
    }
  }
  if (distance[num_nodes - 1] == INFI)
  {
    printf("NO PATH");
  }
  else
  {
    printf("%d\n", distance[num_nodes - 1]);
  }
  printf("%d\n",0);
  for(i=0;i<num_nodes;i++){
    printf("%d\n",path[i]);
  }
}

/* TODO: Implement your solution to Problem 2.b. in this function. */
void problem_2_b()
{
}
