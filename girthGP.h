#ifndef _GIRTHGP_H
#define _GIRTHGP_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define LARGESTGP 32
#define MINGIRTH 3

void girthGP(int n, int k);
void isomorphismGP(int n, int k, int girth, char ** girthFound);
void girthGP2(int n, int k, char ** girthFound);
int partialInnerCycleGirth(int n, int m, int girth);

#endif