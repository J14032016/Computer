/* better not use break to jump out from loop
   you will directly jump out the switch
 */
#include <stdio.h>

int main(int argc, char **argv)
{
    int a;
    a = 2, 3; // a is 2, not 3!

    switch (a) {
    case 1 : printf("ERROR from 1 !\n");
    case 2 : printf("ERROR from 2 !\n");
    case 3 :
        if (a > 1) {
            printf("switch error!\n");
            break; // this break mean to jump out from the if loop
        }
        printf("switch right!\n"); // if it is right , this will be printed
    default : break;
    } // but the break jumps here ! So break in switch is wrong

    printf("This is a test of switch\n");
    return 0;
}
