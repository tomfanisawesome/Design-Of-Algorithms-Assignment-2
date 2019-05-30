/*
 * Problem 3 in Assignment 2
 * COMP20007 Design of Algorithms
 * Semester 1 2019
 *
 * Written by: [ YOUR NAME HERE ]
 */

/* --- DO NOT CHANGE THE CODE BELOW THIS LINE --- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// a binary search tree structure taken from
// www.programiz.com/dsa/tree-traversal

struct node
{
  int data;
  struct node *left;
  struct node *right;
};
void printGivenLevel(struct node* root, int level); 

struct node *newNode(value){
  struct node *node = malloc(sizeof(struct node));
  node->data = value;
  node->left = NULL;
  node->right = NULL;

  return node;
}

struct node *insert(struct node *root, int data)
{
  if (root == NULL)
    return newNode(data);

  if (data < root->data)
    root->left = insert(root->left, data);
  else if (data > root->data)
    root->right = insert(root->right, data);

  return root;
}
// a  function to find the height of a BST taken from
// https://stackoverflow.com/questions/2597637/finding-height-in-binary-search-tree
int height(struct node *tree)
{
  if (tree == NULL)
  {
    return -1;
  }
  int left = height(tree->left);
  int right = height(tree->right);
  if (left > right)
  {
    return left + 1;
  }
  else
  {
    return right + 1;
  }
}

void swap(int *xp, int *yp)
{
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
  int i, j;
  for (i = 0; i < n - 1; i++)
    for (j = 0; j < n - i - 1; j++)
      if (arr[j] > arr[j + 1])
        swap(&arr[j], &arr[j + 1]);
}

/* A function that constructs Balanced Binary Search Tree from a sorted array
from https://www.geeksforgeeks.org/sorted-array-to-balanced-bst/ */

struct node *sortedArrayToBST(int arr[], int start, int end)
{
  /* Base Case */
  if (start > end)
    return NULL;

  /* Get the middle element and make it root */
  int mid = (start + end) / 2;
  struct node *root = newNode(arr[mid]);

  /* Recursively construct the left subtree and make it 
       left child of root */
  root->left = sortedArrayToBST(arr, start, mid - 1);

  /* Recursively construct the right subtree and make it 
       right child of root */
  root->right = sortedArrayToBST(arr, mid + 1, end);

  return root;
}

/*int AddToArray(struct node *node, int arr[], int i,int count)
{
    int j;
    for(j=0;j<count;j++){
     if(node == NULL){
          arr[i]=-1;
     }else{
        arr[i] = node->data;
     }
     i++;
     
        i = AddToArray(node->left, arr, i,count);
        i = AddToArray(node->right, arr, i,count);
      }
    
    return i;
}*/


/*UTILITY FUNCTIONS*/




void problem_3();
int remove_duplicates(int arr[], int n);
int main(int argc, char **argv)
{
  problem_3();
  return 0;
}

/* --- DO NOT CHANGE THE CODE ABOVE THIS LINE --- */

/* TODO: Implement your solution to Problem 3 in this function. */
int remove_duplicates(int arr[], int n)
{
  int i, j, k;
  for (i = 0; i < n; i++)
  {
    for (j = i + 1; j < n; j++)
    {
      if (arr[i] == arr[j])
      {
        for (k = j; k < n; k++)
        {
          arr[k] = arr[k + 1];
        }
        n--;
        j--;
      }
    }
  }
  return n;
}
void problem_3()
{
  int i;
  int n;
  scanf("%d", &n);
  int arr[n];
  for (i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  //remove duplicates in the arrays n is the number of nodes
  n = remove_duplicates(arr, n);
  //node *root =getBST(arr,n);
  printf("%d\n", n);
  struct node *root = NULL;
  root = insert(root, arr[0]);
  for (i = 1; i < n; i++)
  {
    insert(root, arr[i]);
  }
  int h = height(root) + 1;
  printf("%d\n", h);
  bubbleSort(arr, n);
  struct node *balancedTree = sortedArrayToBST(arr, 0, n - 1);
  int treeH=height(balancedTree)+1;
  int count=(pow(2,treeH))-1;
  printf("%d\n",count);
  int array[count];
  //AddToArray(balancedTree,array,0,count);
}
