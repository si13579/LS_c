#include<stdio.h>
#include<unistd.h>
#undef getchar
int getchar(void)
{
    char c;
    return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}
int main()
{
    int a;
    while ((a = getchar()) != EOF)
    {
        putchar(a);
        a++;
    }
    return 0;
}