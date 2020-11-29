/*
//getline: read a line into s,return length 
#include<stdio.h>
int getline(char *s,int lim)
{
    int c;
    char *t = s;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if ( c == '\n')
        *s++ = c;
    *s = '\0';
    return s - t;
}
*/
/*
#include<ctype.h>
//atoi:convert s to integer;pointer version 转换为整数
int atoi(char *s)
{
    int n,sign;
    for ( ; isspace(*s);s++)
        ;
    sign = ( *s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-')
        s++;
    for ( n = 0; isdigit(*s); s++)
        n = n * 10 + *s - '0';
    return n * sign;
}
*/

/*
void reverse(char *);
//itoa:convert n to characters in s;pointer version将n转换为s中的字符；指针版本
void itoa(int n,char *s)
{
    int sign;
    char *t = s;
    if ((sign = n) < 0)
        n = -n;
    do {
        *s++ = n % 10 + '0';
    }while ( n /= 10 > 0);
    if (sign < 0)
        *s++ = '-';
    *s = '\0';
    reverse(t);
} 
#include<string.h>
//reverse:reverse string s in place
void reverse(char *s)
{
    int c;
    char *t;
    for ( t = s + (strlen(s) - 1); s < t; s++,t--){
        c = *s;
        *s = *t;
        *t = c;
    }
}
*/

/*
//strindex:return index of t in s,-1 if none t在s中的返回索引，如果没有，则返回-1
int strindex(char *s,char *t)
{
    char *b = s;
    char *p,*r;
    for ( ; *s != '\0';s++){
        for ( p = s,r = t;*r != '\0' && *p == *r; p++,r++)
            ;
        if ( r > t && *r == '\0')
            return s - b;
    }
    return -1;
}
*/

/*
#include<ctype.h>
//atof: convert string s to double;pointer version
double atof(char *s)
{
    double val,power;
    int sign;
    for ( ; isspace(*s); s++)
        ;
    sign = (*s == '-') ? -1 : 1;
    if ( *s == '+' || *s == '-')
        s++;
    for ( val = 0.0; isdigit(*s);s++)
        val = 10.0*val + ( *s - '0');
    if ( *s == ',')
        s++;
    for ( power = 1.0;isdigit(*s); s++){
        val = 10.0 * val + ( *s - '0');
        power *= 10.0;
    }
    return sign*val/power;
}
*/


#include<stdio.h>
#include<ctype.h>

#define NUMBER '0'
int getch(void);
void ungetch(int);
//getop: get next operator or numeric poerand;pointer version
int getop(char *s)
{
    int c;
    while ( (*s = c = getch()) == ' '|| c == '\t')
        ;
    *(s+1) = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    if (isdigit(c))
        while ( isdigit(*++s = c = getch()))
            ;
    if ( c == '.')
        while ( isdigit(*++s = c = getch()))
            ;
    *s = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}
