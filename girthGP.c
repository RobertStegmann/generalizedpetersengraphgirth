#include "girthGP.h"

/*
*   Robert Stegmann
*   2022-03-10
*
*   The formula used is based on original research on the girth of the generalized Petersen graph
*
*/

int main() {
    for (int i = MINGIRTH; i <= LARGESTGP; i++) {
        for (int j = 1; 2*j < i; j++) {
            girthGP(i, j);
        }
    }
    return 0;
}

void girthGP(int n, int k) {    
    printf("The girth of ");
    printf("GP(%d,%d),GP(%d,%d) ",n,k,n,n-k);

    int girth = n;

    if (girth > k + 3) {
        girth = k + 3;
    }

    if ((n % k) == 0) {
        int innerCycle = n / k;
        if (innerCycle != 2 && innerCycle < girth) {
            girth = innerCycle;
        }
    } else {
        girth = partialInnerCycleGirth(n, k, girth);
    }
    
    if (girth > 8) {
        girth = 8;
    }

    printf("is %d\n",girth);
}

int partialInnerCycleGirth(int n, int k, int girth) {
    int minGirth = girth;
    int partialInnerCycle = 0;
    for (int i = 1; i < girth - 4; i++) {
        for (int j = 2; j < girth - i - 2; i++) {
            if (j * k == n - i || j * k == n + i) {
                partialInnerCycle = i + j + 2;
                if (partialInnerCycle < minGirth) {
                    minGirth = partialInnerCycle;
                }
            }
        }
    }
    return minGirth;
}