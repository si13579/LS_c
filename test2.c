/*
 * @Date: 2020-08-02 23:18:16
 */
#include<stdio.h>
int atoi(char s[])
{
    int i,n;
    n = 0;
    for ( i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = n * 10 + (s[i] - '0');
    printf("%d",n);
}
int main()
{
    char s[]="1234";
    atoi(s);
}