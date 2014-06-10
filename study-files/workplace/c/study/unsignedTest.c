/* better not use unsigned
   when minus is compared with the unsigned
   minus is automatically transformed into unsigned
   so minus become a very big number
*/
#include <stdio.h>

int main(int argc, char **argv)
{
    int d = -1;
    int array[] = {1, 2, 3, 4, 5, 6};
    // sizeof returns unsigned number
    //#define TOTAL_ELEMENT (sizeof(array)/sizeof(array[0]))

    unsigned int TOTAL_ELEMENT = (sizeof(array)/sizeof(array[0]));
    
    if (d < TOTAL_ELEMENT-3) // return 0 , for d is transformed into unsigned
        printf("%d\n", array[d+1]);
    else
        printf("ERROR!\n"); // the result print this line

    return 0;
}
