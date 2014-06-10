#include <stdio.h>
#include <stdlib.h>

struct ord {
	int x, y;
} dt[2]={1,2,3,4}; // 这么定义则x y都为同一值

int main()
{
	struct ord *p = dt;
	printf("%d, %d\n", ++p->x, ++p->y);
	return EXIT_SUCCESS;
}
