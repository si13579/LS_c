/*
 * @Date: 2020-07-28 22:26:50
编写一个程序，删除C语言程序中所有的注释语句。要正确处理带引号的字符串与字符常量。在C语言程序中，注释不允许嵌套。
 */ 
#include<stdio.h>
void rcomment(int c);//read each character,remove the comments 阅读每个字符删除注释
void in_comment(void);//inside of a valid comment   在有效注释的内部
void echo_quote(int c); //echo characters within quotes 引号内的字符
// remove all comments from a valid c program
//从有效的C程序中删除所有注释
int main()
{
    int c,d;
    while ((c = getchar()) != EOF)
    {
        rcomment(c);
    }
    return 0;
    
}
void rcomment(int c)
{
    int d;
    if (c == '/')
    {
        if((d = getchar()) == '*')
            in_comment();
        else if(d == '/')
        {
            putchar(c);
            rcomment(d);
        }
        else
        {
            putchar(c);
            putchar(d);
        }
    }
    else if(c == '\'' || c == '"')
        echo_quote(c);
    else
        putchar(c);
}
 void in_comment(void)
 {
     int c,d;
     c = getchar();
     d = getchar();
     while(c != '*' || d != '/')
     {
         c = d;
         d = getchar();
     }
 }
 void echo_quote(int c)
 {
     int d;
     putchar(c);
     while((d = getchar()) != c)
     {
         putchar(d);
         if(d == '\\')
            putchar(getchar());
     }
     putchar(d);
 }