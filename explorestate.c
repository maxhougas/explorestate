#include <stdio.h>
#include <./hougasconsts.h>

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

int recursiveExplore(int* vec, int depth, int fin)
{
 int ret = SUCCESS;

 if

}
