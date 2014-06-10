#include <stdio.h>

void moveDish(int level, char from, char inter, char to) {
    if(level == 1)
        printf("Move the plant 1 from %c to %c\n", from, to);
    else {
        moveDish(level-1, from, to, inter);
        printf("Move the plant %d from %c to %c\n", level, from, to);
        moveDish(level-1, inter, from, to);
    }
}

int main()
{
    int nDishs = 3;
    moveDish(nDishs, 'A', 'B', 'C');
    return 0;
}
