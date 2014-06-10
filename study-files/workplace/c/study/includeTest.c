/* #include "file.c" will insert a c file in current file */
#include <stdio.h>

int main()
{
#include "includeTest2.c"

  a = 3;
  printf("include file in the main function\n");
  printf("in file 1 a is %d\n", a);
  return 0;
}
  
