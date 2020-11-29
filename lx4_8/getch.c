/*
#include<stdio.h>
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else 
        buf[bufp++] = c;
}
*/
#include<stdio.h>
char buf = 0;
//getch: get a (possibly pushed back) character
int getch(void)
{
    int c;
    if (buf != 0 )
        c = buf;
    else 
        c = getchar();
    buf = 0;
    return c;
}
//ungetch:push character back onto the input
void ungetch(int c)
{
    if (buf != 0)
        printf("ungetch: too manyt characters\n");
    else 
        buf = c;
}