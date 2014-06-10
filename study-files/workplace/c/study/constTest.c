/* const is just read-only , the const varible is not
   when const is used in the pointer, it will not work
 */
#include <stdio.h>

int main(int argc, char **argv)
{
    const int limit = 10;
    const int * limitp = &limit;
    int i = 27;
    printf("The value of limitp is %d\n", *limitp);
    limitp = &i;
    printf("The value of limitp is %d\n", *limitp);

    return 0;
}
