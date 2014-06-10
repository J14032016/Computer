#include "stdio.h"

#define GET_ARRAY_LEN(array,len){len=(sizeof(array)/sizeof(array[0]));}

void polarValue(int *a, int len, int *max, int *min) {
    int i=0;
    *max = *min = a[0];
    for (i=0; i<len; ++i)
        if (a[i]>*max) *max = a[i];
    for (i=0; i<len; ++i)
        if (a[i]<*min) *min = a[i];
}


int main(int argc, char *argv[])
{
    int a[] = {9, 2, 3, 4, 5};
    int len = 0;
    GET_ARRAY_LEN(a,len);
    printf ("The length of the array is %d\n",len);

    int max,min;
    polarValue(a,len,&max,&min);
    printf ("The biggest value is %d\n",max);
    printf ("The smallest value is %d\n",min);
    
    return 0;
}

