/*
 * @Date: 2020-08-02 06:37:13
 */ 
#include<stdio.h>
int strb(char s[]);
int main()
{
    char s[] = "warinning";
    strb(s);
}
int strb(char s[])
{
    int i;
    i = 0;
    while (s[i] != '\0')
    {
        //printf("%d\n",s[i]);
        ++i;
    }
    //return i;
    printf("%d\n",i);
    
}