#include "stdio.h"

void sayHello () {
    printf ("Hello world!\n");
}

int main(int argc, char *argv[])
{
    // void show that you create a function pointer,and the funciton return void
    // the name of the function is helloworld,function pointers must have parentheses around them
    // the parameter list is void
    void *helloworld = NULL; // declear a pointer
    helloworld = sayHello; // point to a function 
    // dereference and call the function
    // void (*) ()  is the function
    // (void (*) ())helloworld   change helloworld to the function type
    // finally * dereference the pointer ,and add parameter list
    (* (void (*) ()) helloworld)();
    return 0;
}
