#include "stdio.h"
#define EPS 1e-4

float fun (float a, float x) {
    return a * x * x;
}

float derivative (float (*mathop)(float,float), float a, float x) {
    return ((*mathop)(a, x+EPS) - (*mathop)(a, x))/EPS;
}

int main(int argc, char *argv[])
{
    float x, y;
    x = 3;
    float a = 2;
    y = derivative(fun, a, x);
    printf ("The derivative of fun is %f\n", y);
    return 0;
}
