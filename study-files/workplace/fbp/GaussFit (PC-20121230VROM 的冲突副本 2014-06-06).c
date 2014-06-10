#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void nlinfit (float* x, float* y, float* b0, float* b);
double Gauss (float x, float b1, float b2, float b3);

int main(int argc, char *argv[])
{
    float x[6] = {50, 25, 13, 6, 3, 0.5};
    float y[6] = {1.5, 11, 30, 55, 70, 88};
    float b0[2] = {0,1};
    float b[2] = {0,0};
    
    nlinfit(x,y,b0,b);
    printf ("The fit result is : \n");
    printf ("b : %f\t%f\n",b[0], b[1]);
    
    return 0;
}

double Gauss (float x,float b1, float b2, float b3) {
    return b1*exp(-(x-b2)*(x-b2)/(b3*b3));
}

void nlinfit (float* x, float* y, float* b0, float* b) {
    
}
