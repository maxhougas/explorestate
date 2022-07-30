#include <stdio.h>
#include <stdlib.h>
#include "../headers/hougasconsts.h"
#include "../headers/hougasvectors.h"

#define WIDTH 4
#define DEPTH 2

/*
for a 4 vector depth 1 the pattern should go
1 0 0 0
0 1 0 0
0 0 1 0
0 0 0 1

depth 2

2 0 0 0
1 1 0 0
1 0 1 0
1 0 0 1
1 1 0 0 SKIP
0 2 0 0
0 1 1 0
0 1 0 1
1 0 1 0 SKIP
0 1 1 0 SKIP
0 0 2 0
0 0 1 1
1 0 0 1 SKIP
0 1 0 1 SKIP
0 0 1 1 SKIP
0 0 0 2

2 0 0 0
1 1 0 0
1 0 1 0
1 0 0 1
SKIP
0 2 0 0
0 1 1 0
0 1 0 1
SKIP
0 0 2 0
0 0 1 1
SKIP
0 0 0 2

depth 3

3 0 0 0
2 1 0 0
2 0 1 0
2 0 0 1
SKIP
1 2 0 0
1 1 1 0
1 1 0 1
SKIP
1 0 2 0
1 0 1 1
SKIP
1 0 0 2
SKIP SKIP
0 3 0 0
0 2 1 0
0 2 0 1
SKIP
0 1 2 0
0 1 1 1
SKIP
0 1 0 2
SKIP SKIP
0 0 3 0
0 0 2 1
SKIP
0 0 1 2
SKIP SKIP
0 0 0 3

It seems like the original recursive design was the way to go.
*/

/*
this will behave strangely if vec is not [depth,0,...]
may fail if vec contains negative numbers
*/

int iterExploreStates(int* vec, int width, int fin)
{
 int ret = SUCCESS;

 if(!vec)
  ret = NULL_STRUCTURE;
 else if(width < 0 || fin < 0 || vec[fin] == 0)
  ret = INVALID_VALUE;
 else
 {
  int depth;
  vectorReduce(&depth,vec,width,ADD,INT);
  printf("%d\n",depth);
  
  while(vec[width-1] < depth)
  {
   if(fin != width-1)
   {
    vec[fin]--;
    fin++;
    vec[fin]++;
   }
   else
   {
    do
     fin--;
    while (vec[fin] == 0);

    vec[fin]--;
    fin++;
    vec[fin]++;

    if(fin != width-1)
    {
     vec[fin] += vec[width-1];
     vec[width-1] = 0;
    }
   }

   /*payload*/
   vectorPrint(vec,width,INT);
  }
  
 }

 return ret;
}

/*
int nextEx(int* depthDone, int* vec, unsigned int width, unsigned int fin)
{
 int ret = SUCCESS;
 *depthDone = 0;

 if(!(vec && depthDone))
  ret = NULL_STRUCTURE;
 else if(width < 0 || fin < 0 || fin >= width || vec[fin] == 0)
  ret = INVALID_VALUE;
 else if(fin == width-1)
  depthDone = 1;
 else
 {
  vec[fin] -= 1;
  fin++;
  vec[fin] += 1;
  nextEx(depthDone,vec,width,fin);
 }
}

int recursiveExplore(int* vec, unsigned int width, unsigned int fin)
{
 int ret = SUCCESS;

 if(!vec)
  ret = NULL_STRUCTURE;
 else if(width < 0 || fin < 0 || fin >= width || vec[fin] == 0)
  ret = INVALID_VALUE;
 else
 {
  if(nextEX())
 }

 return ret;
}
*/

int main(int argc, int argv)
{
 int* vec = (int*)malloc(sizeof(int));
 /*int i;
 for(i=0;i<WIDTH;i++)
  vec[i]=0;*/
 vectorPrint(vec,WIDTH,INT);
 vec[0] = DEPTH;

 iterExploreStates(vec,WIDTH,0);
 printf("done");
}
