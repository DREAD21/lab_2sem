#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct _Row
{
  char _key[81];
  char _str[81];
} Row;
void printTable (Row * arr, const int size);
int binSearch (const Row * arr, const int size, const char *key);
printTable (Row * arr, const int size) P P5QP0QQQP0P1P;P8QQ
binSearch (const Row * arr, const int size, const char *key) P P8P=P0Q P=QP9P?P>P8QP:P2QP0P1P;P8QP5P?P>P:P;QQQ
sort (Row * arr, const int size) P !P>Q QP8Q P>P2P:P0
scramble (Row * arr, const int size) P P5Q P5P<P5QP8P2P0P=P8P5
reverse (Row * arr, const int size) P  P5P2P5Q Q
swapRows (Row * r1, Row * r2) P !P4P2P8P3Q
P;P5P<P5P=QP0
      void sort (Row * arr, const int size);
     void scramble (Row * arr, const int size);
     void reverse (Row * arr, const int size);
     void swapRows (Row * r1, Row * r2);
     int randomAB (const int a, const int b);
     int isSorted (const Row * a, const int size);
     void getRow (FILE * stream, char *str, const int size);

     int main (void)
{
  const int N = 50;
  int i, cnt, action;
  char key[] = { '\0' };
  char ch;
  Row arr[N];
  FILE *file = fopen ("input.txt", "r");
  if (file == NULL)
    {
      printf ("PQP8P1P:P0 P?Q P8 P>QP:Q QQP8P8 QP0P9P;P0\n");
      return 0;
    }

  i = 0;

  while (i < N && fscanf (file, "%s", arr[i]._key) == 1)
    {
      fscanf (file, "%c", &ch);

       getRow (file, arr[i]._str, sizeof (arr[i]._str));

      i++;
    }

  fclose (file);

  cnt = i;

  do
    {
      printf ("PP5P=Q\n");
      printf ("1) PP5QP0QQ\n");
      printf ("2) PP2P>P8QP=QP9 P?P>P8QP:\n");
      printf ("3) P!P>Q QP8Q P>P2P:P0\n");
      printf ("4) PP5Q P5P<P5QP8P2P0P=P8P5\n");
      printf ("5) P P5P2P5Q Q\n");
      printf ("6) PQQP>P4\n");
      printf ("PQP1P5Q P8QP5 P4P5P9QQP2P8P5\n");
      scanf ("%d", &action);

      switch (action)
	{
	case 1:
	  {
	    printTable (arr, cnt);
	    break;
	  }

    case 2:
	  {
	    if (!isSorted (arr, cnt))
	      printf
		("PQP8P1P:P0. P"P0P1P;P8QP0 P=P5 P>QQP>Q QP8Q P>P2P0P=P0\n");
	    else
	      {
		printf ("PP2P5P4P8QP5 P:P;QQ: ");
		scanf ("%s", key);

		i = binSearch (arr, cnt, key);

		if (i > -1)
		  printf ("PP0P9P4P5P=P0 QQQ P>P:P0: %s\n", arr[i]._str);
		else
		  printf ("P!QQ P>P:P0 Q QP0P:P8P< P:P;QQP>P< P=P5

P=P0P9P4P5P=P0\n");

	      }

	    break;
	  }

	case 3:
	  {
	    sort (arr, cnt);

	    break;
	  }

	case 4:
	  {
	    scramble (arr, cnt);

	    break;
	  }

	case 5:
	  {
	    reverse (arr, cnt);

	    break;
	  }

	case 6:
	  break;

	default:
	  {
	    printf ("PQP8P1P:P0. P"P0P:P>P3P> P?QP=P:QP0 P<P5P=Q P=P5

QQQ	P5QQP2QP5Q\n");

	    break;
	  }
	}
    }
  while (action != 6);

  return 0;
}

void
printTable (Row * arr, const int size)
{
  int i;

  printf ("\n");
  printf ("PP;QQ PP=P0QP5P=P8P5 \n");
  printf ("\n");

  for (i = 0; i < size; i++)
    printf ("%s %60s\n", arr[i]._key, arr[i]._str);

  printf ("\n");
}

int
binSearch (const Row * arr, const int size, const char *key)
{
  int start = 0, end = size - 1, mid;

  if (size <= 0)
    return -1;

  while (start < end)

    
    {
      mid = start + (end - start) / 2;

      if (strcmp (arr[mid]._key, key) == 0)
	return mid;
      else if (strcmp (arr[mid]._key, key) < 0)
	start = mid + 1;
      else
	end = mid;

    }

  if (strcmp (arr[end]._key, key) == 0)
    return end;

  return -1;
}

void
sort (Row * arr, const int size)
{
  int left, right, i;
  left = 0;
  right = size - 1;
  while (left <= right)
    {
      for (i = right; i >= left; i--)
	{
	  if (strcmp (arr[i - 1]._key, arr[i]._key) > 0)
	    {
	      swapRows (&arr[i - 1], &arr[i]);

	    }
	}
      left++;
      for (i = left; i <= right; i++)
	{
	  if (strcmp (arr[i - 1]._key, arr[i]._key) > 0)
	    {
	      swapRows (&arr[i - 1], &arr[i]);
	    }
	}
      right--;
    }
}

void
scramble (Row * arr, const int size)
{
  int i, j, k;

  srand ((unsigned int) time (0));

  for (k = 0; k < size; k++)
    {
      i = randomAB (0, size - 1);
      j = randomAB (0, size - 1);

      swapRows (&arr[i], &arr[j]);
    }
}

void
reverse (Row * arr, const int size)
{
  int i, j;

  for (i = 0, j = size - 1; i < j; i++, j--)
    swapRows (&arr[i], &arr[j]);

}

void
swapRows (Row * r1, Row * r2)
{
  Row tmp;

  tmp = *r1;
  *r1 = *r2;
  *r2 = tmp;
}

int
randomAB (const int a, const int b)
{
  return a + rand () % (b - a + 1);
}

int
isSorted (const Row * a, const int size)
{

  int i;

  for (i = 0; i < size - 1; i++)
    if (a[i]._key > a[i + 1]._key)
      return 0;

  return 1;
}

void
getRow (FILE * stream, char *str, const int size)
{
  int cnt = 0, ch;

  while ((ch = getc (stream)) != '\n' && cnt < size - 1)
    str[cnt++] = ch;

  str[cnt] = '\0';
}
