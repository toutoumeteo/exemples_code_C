#include <stdio.h>

//http://www.cprogramming.com/tutorial/c/lesson6.html

int main()
{ 
    int x;            /* A normal integer*/
    int *p;           /* A pointer to an integer ("*p" is an integer, so p
                       must be a pointer to an integer) */
    int **pp;

    p = &x;           /* Read it, "assign the address of x to p" */
    printf( "%s","Enter an int:"); 
    scanf( "%d", &x );          /* Put a value in x, we could also use p here */
    printf( "%d\n", *p ); /* Note the use of the * to get the value */
    printf( "%s %p\n","Pointer p points to ", p ); /* To get the addresse */
    printf( "%s %p\n","Pointer p address is ", &p ); /* To get the addresse */
    pp=&p;
    printf( "%s %p\n","Pointer pp points to pointer p which is at ", pp );
}
