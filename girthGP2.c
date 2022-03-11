#include "girthGP.h"

/* 
*
*   Robert Stegmann
*   2022-03-10
*
*   The formula used in this program is based on the research of Daniela Ferrero and Sarah Hanusch on the girth of the generalized Petersen graph
*
*   Daniela Ferrero and Sarah Hanusch, Component connectivity of generalized
*   petersen graphs, International Journal of Computer Mathematics 91 (2014),
*   1940–1963
*
*/

int main() {
    //Allocate memory
    char ** girthFound = calloc(LARGESTGP-MINGIRTH+1,sizeof(char *));
    if (girthFound == NULL) {
        fprintf(stderr,"ERROR: malloc failed");
        return 1;
    } else {
        for (int i = 0; i < LARGESTGP-MINGIRTH+1; i++) {
            girthFound[i] = calloc(i+MINGIRTH,sizeof(char));
        }
    }

    for (int i = MINGIRTH; i <= LARGESTGP; i++) {
        for (int j = 1; 2*j < i; j++) {
            if (girthFound[i-MINGIRTH][j-1] == 0) {
                girthGP2(i, j,girthFound);
            }
        }
    }

    for (int i = 0; i < LARGESTGP-MINGIRTH+1; i++) {
        free(girthFound[i]);     
    }
    free(girthFound);
    return 0;
}

void girthGP2(int n, int k, char ** girthFound) {    
    printf("The girth of ");
    
    int girth = n;
    if (n % k == 0) {
        int innerCycle = n / k;
        if (innerCycle < girth) {
            girth = innerCycle;
        }
        if (girth > k + 3) {
            girth = k + 3;
        }
        if (girth > 8) {
            girth = 8;
        }
    } else if (n > 4) {
        if (k == 1) {
            girth = 4;
        } else if (k == 2) {
            girth = 5;
        } else if (k == 3 || 2*k+2 == n) {
            girth = 6;
        } else if (k == 4 || 2*k+3 == n || (k > 4 && (abs(3*k-n) == 2))) {
            girth = 7;
        } else {
            girth = 8;
        }
    }
    //Find all isomorphic generalized Petersen graphs      
    isomorphismGP(n, k,girth,girthFound);
    printf(" is %d\n",girth);
}

void isomorphismGP(int n, int k, int girth, char ** girthFound) {
    printf("GP(%d,%d),GP(%d,%d)",n,k,n,n-k);
    girthFound[n-MINGIRTH][k-1] = girth;
    girthFound[n-MINGIRTH][n-k-1] = girth;
    int temp = 0;
    for (int j = k+1; 2*j < n; j++) {
        temp = j*k;
        if (temp % n == 1 || temp % n == n-1) {
            printf(",GP(%d,%d),GP(%d,%d)",n,j,n,n-j);
            girthFound[n-MINGIRTH][j-1] = girth;
            girthFound[n-MINGIRTH][n-j-1] = girth;
        }
    }
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
