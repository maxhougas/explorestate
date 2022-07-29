#include <stdio.h>
#include <./headers/hougasconsts.h>

#define WIDTH 4

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

int nextEx(int* depthDone, int* vec, unsigned int width, unsigned int fin)
{
 int ret = SUCCESS;
 *depthDone = 0;

 if(!(vec && depthDone))
 {
  ret = NULL_STRUCTURE;
 }
 else if(width < 0 || fin < 0 || fin >= width || vec[fin] == 0)
 {
  ret = INVALID_VALUE;
 }
 else if(fin == width-1)
 {
  depthDone = 1;
  
 }
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
