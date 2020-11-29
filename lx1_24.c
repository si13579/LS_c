/*
 * @Date: 2020-07-29 01:34:56
编写一个程序，查找C语言程序中的基本语法错误，如圆括号、方括号以及花括号不配对等。
要正确处理引号（包括单引号和双引号）、转义字符序列与注释。
 */  
#include<stdio.h>
int brace,brack,paren;//花括号，方括号，圆括号
void in_quote(int c);//在引号里
void in_comment(void);//在注释内部
void search(int c);
//rudimentary syntax checker for C programs
//c程序的基本语法检查器
main()
{
    int c;
    extern int brace,brack,paren;
    while((c =getchar()) != EOF)
    {
        if(c == '/'){
            if(( c = getchar()) == '*')
                in_comment();
            else
                search(c);
        }
        else if (c == '\'' || c == '"')
            in_quote(c);
        else 
            search(c);
        
        if (brace < 0)
        {
            printf("Unbalanced braces\n");
            brace = 0;
        }
        else if (brack < 0)
        {
            printf("Unbalanced brackets\n");
            brack = 0;
        }
        else if (paren < 0){
            printf("Unbalanced parentheses \n");
            paren = 0;
        }
    }
    if (brace > 0)
        printf("Unbalanced braces\n");
    if (brack > 0)
        printf("Unbalanced brackets\n");
    if (paren > 0)
        printf("Unbalanced parentheses\n");
}
//search:search for rudimentary syntax errors
//寻找基本的语法错误
void search(int c)
{
    extern int brace,brack,paren;
    if (c == '{')
        ++brace;
    else if (c == '}')
        --brace;
    else if (c == '[')
        ++brack;
    else if (c == ']')
        --brack;
    else if (c == '(')
        ++paren;
    else if (c == ')') 
        --paren;  
}
//in_comment: inside of a valid comment
//在有效注释内
void in_comment(void)
{
    int c,d;
    c = getchar();
    d = getchar();
    while (c != '*' || d != '/'){
        c = d;
        d = getchar();
    }
}
//in_quote:inside quote
//在引号内
void in_quote(int c)
{
    int d;
    while ((d = getchar()) != c)
        if (d == '\\')
            getchar();
}