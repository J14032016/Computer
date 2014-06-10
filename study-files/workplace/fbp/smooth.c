#include "stdio.h"
#define N 5

void smooth (int* a, int len, float *b) {
    int i, j;
    for (i=0; i<(N-1)/2; ++i) b[i] = (float)a[i];
    for (i=(N-1)/2; i<len-(N-1)/2; ++i) {
        for (j=i-(N-1)/2; j<i+(N+1)/2; ++j) b[i] += (float)a[j];
        b[i] /= N;
    }
    for (i=len-(N-1)/2; i<len; ++i) b[i] = (float)a[i];
}

int main(int argc, char *argv[])
{
    float b[10] = {0};
    int a[10] = {2,2,3,5,5,6,1,8,9,10};
    int i;
    printf ("The original array is \n");
    for (i=0; i<10; ++i)
        printf ("%d\t",a[i]);
    
    smooth(a,10,b);
    printf ("\nThe smooth array is : \n");
    for (i=0; i<10; ++i)
        printf ("%f\t",b[i]);
    
    return 0;
}
