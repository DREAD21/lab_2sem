

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <signal.h>
typedef int T;
#define CMP_EQ(a, b) ((a) == (b))
#define CMP_LT(a, b) ((a) < (b))
#define CMP_GT(a, b) ((a) > (b))
typedef struct Node
{
  T data;
  struct Node *left;
  struct Node *right;
  struct Node *parent;
} Node;

Node *
getFreeNode (T value, Node * parent)
{
  Node *tmp = (Node *) malloc (sizeof (Node));
  tmp->left = tmp->right = NULL;
  tmp->data = value;
  tmp->parent = parent;
  return tmp;
}

Node *
getNodeByValue (Node * root, T value)
{			
  while (root)
    {
      if (CMP_GT (root->data, value))
	{
	  root = root->left;
	  continue;
	}
      else if (CMP_LT (root->data, value))
	{
	  root = root->right;
	  continue;
	}
      else
	{
	  return root;
	}
    }
  return NULL;
}

void
insert (Node ** head, int value)
{				
  Node *tmp = NULL;
  Node *ins = NULL;
  if (*head == NULL)
    {
      *head = getFreeNode (value, NULL);
      return;
    }

  tmp = *head;
  while (tmp)
    {
      if (CMP_GT (value, tmp->data))
	{
	  if (tmp->right)
	    {
	      tmp = tmp->right;
	      continue;
	    }
	  else
	    {
	      tmp->right = getFreeNode (value, tmp);
	      return;
	    }
	}
      else if (CMP_LT (value, tmp->data))
	{
	  if (tmp->left)
	    {
	      tmp = tmp->left;
	      continue;
	    }
	  else
	    {
	      tmp->left = getFreeNode (value, tmp);
	      return;
	    }
	}
      else
	{
	  exit (2);
	}
    }
}

Node *
findMaxNode (Node * root)
{
  while (root->right)
    {
      root = root->right;
    }
  return root;
}

void
removeNodeByPtr (Node * target)
{				
  if (target->left && target->right)
    {
      Node *localMax = findMaxNode (target->left);
      target->data = localMax->data;
      removeNodeByPtr (localMax);
      return;
    }
  else if (target->left)
    {
      if (target == target->parent->left)
	{
	  target->parent->left = target->left;
	}
      else
	{
	  target->parent->right = target->left;
	}
    }
  else if (target->right)
    {
      if (target == target->parent->right)
	{
	  target->parent->right = target->right;
	}
      else
	{
	  target->parent->left = target->right;
	}
    }
  else
    {
      if (target == target->parent->left)
	{

	  target->parent->left = NULL;
	}
      else
	{
	  target->parent->right = NULL;
	}
    }
  free (target);
}

void
deleteValue (Node * root, T value)
{
  Node *target = getNodeByValue (root, value);
  removeNodeByPtr (target);
}

bool
checkUtil (struct Node *root, int level, int *leafLevel)
{
  if (root == NULL)
    return true;
  if (root->left == NULL && root->right == NULL)
    {
      if (*leafLevel == 0)
	{
	  *leafLevel = level;
	  return true;
	}
      return (level == *leafLevel);
    }
  return checkUtil (root->left, level + 1, leafLevel) &&
    checkUtil (root->right, level + 1, leafLevel);

}

bool
check (struct Node * root)
{
  int level = 0, leafLevel = 0;
  return checkUtil (root, level, &leafLevel);
}

void
printTree (Node * root, int i)
{
  if (root)
    {
      int a = i;
      if (root->right != NULL)
	printTree (root->right, i + 1);
      while (a > 0)
	{
	  printf (" ");
	  a--;
	}
      printf ("%d \n", root->data);
      if (root->left != NULL)
	printTree (root->left, i + 1);
    }

}

void
main ()
{				

  Node *root = NULL;
  int a, b = 0, g = 1;
  while (g == 1)
    {
      printf
	("1.research 2.print Tree 3. Create tree 4.Add node 5.Delete 6.Exit\n");
      scanf ("%d", &a);
      switch (a)
	{
	case 1:
	  if (check (root) == 1)

	    printf ("Leaves are at same level\n");

	  else
	    printf ("Leaves are not at same level\n");

	  break;

	case 2:
	  printTree (root, 0);
	  break;

	case 3:
	  printf ("enter add node:");
	  scanf ("%d", &b);
	  insert (&root, b);
	  break;

	case 4:
	  printf ("enter add node:");
	  scanf ("%d", &b);
	  insert (&root, b);
	  break;

	case 5:
	  printf ("enter delete node:");
	  scanf ("%d", &b);
	  deleteValue (root, b);
	  break;
	case 6:
	  printf ("exit");
	  g = 0;
	  break;
	}
    }
}
