/*
 * @Date: 2020-08-02 21:37:34
 */
#include<stdio.h>
int main()
{
    int lim = 10;
    char b[lim];
    int i = 0;
    int c;
    enum loop {NO,YES};
    enum loop okloop = YES;
    while (okloop == YES)
    {
        if (i >= lim - 1)
            okloop = NO;
        else if ( (c = getchar()) == '\n' )
            okloop = NO;
        else if ( c == EOF)
            okloop = NO;
        else {
            b[i] = c;
            i++;
        }
    //return i;
    }
    for (int a = 0;a < i; a++)
    {
        printf("%c\n",b[a]);
    }
    return 0;

}
