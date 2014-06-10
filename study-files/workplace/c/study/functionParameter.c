#include "stdio.h"

float add (float x, float y) {
    return x + y;
}

float subtract (float x, float y) {
    return x - y;
}

float doMath (float (*mathop) (float, float), float x, float y) {
    return (*mathop)(x, y);
}

int main(int argc, char *argv[])
{
    float a = doMath(add, 10, 2);
    printf ("add test : %f\n", a);
    float b = doMath(subtract, 10, 2);
    printf ("subtract test : %f\n",b);
    return 0;
}
