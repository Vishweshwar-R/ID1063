#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "libs/matfun.h"
int main()
{
int m;
printf("Enter length of vector:");
scanf("%d",&m);
double **A = createMat(m,1);
A=loadMat("str1.dat",m,1);
double **B = createMat(m,1);
B=loadMat("str2.dat",m,1);
double **c_ab=Matmul(transposeMat(B,m,1),A, 1, m, 1);
printf("A:\n");
printMat(A,m,1);
printf("B:\n");
printMat(B,m,1);
printf("Dot product:\n");
printMat(c_ab,1,1);
freeMat(A,m);
freeMat(B,m);
freeMat(c_ab,1);
}
