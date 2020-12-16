#include<stdio.h>
char token[] = {"abc"};
char *pt = token;
main() 
{
    printf("%d\n",pt);
    printf("%d",*(&pt));
    return 0;
}