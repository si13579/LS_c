#include<stdio.h>
struct abc
{
    int len;
    char *str;
} p[] = {
    1,"abc",
    2,"uuooi"
};
main()
{   
    printf("%c",*(p)->str++);
    printf("%c",*p->str);
    return 0;
}