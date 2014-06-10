#include "stdio.h"
#include "stdlib.h"
#include "math.h"

double Gauss (float x,float b1, float b2, float b3) {
    return b1*exp(-(x-b2)*(x-b2)/(b3*b3));
}

int main(int argc, char *argv[])
{
    float x = 5;
    double sum = exp(x);
    double gsum = Gauss(0.1,0.2,0.3,1);
    printf ("sum is %lf\n",sum);
    printf ("gsum is %lf\n",gsum);
    return 0;
}
