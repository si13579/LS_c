#include<stdio.h>
/*
void strncpy(char *s,char *t,int n)
{
    while (*t && n-- > 0)
        *s++ = *t++;
    while (n-- > 0)
        *s++ = '\0';
}
void strcpy(char *s,char *t)
{
    while (*s++ = *t++)
        ;
}
int strlen(char *s)
{
    char *p = s;
    while (*p != '\0')
        p++;
    return p - n;
}
void strncat(char *s,char *t,int n)
{
    void strncpy(char *s,char *t,int n);
    int strlen(char *s);
    strncpy(s+strlen(s),t,n);
}
*/
int strncmpa(char *s,char *t,int n)
{
    for ( ; *s == *t; s++,t++)
        if (*s == '\0' || --n <= 0)
            return 0;
    return *s - *t;
}
void main()
{
    //char pa[] = {'a','b'};
    //char *t = "fde";
    //strncpy(pa,t,3);
    //char s[] = "abc";
    //char *t = "dfg";
    //strcpy(s,t);
    char *s = "aaad";
    char *t = "abc";
    strncmpa(s,t,3);
}