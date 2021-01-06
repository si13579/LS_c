/*
#include<stdio.h>
#include<ctype.h>
#include "calc.h"
int getop(char s[])
{
    int i,c;
    while ( (s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if ( !isdigit(c) && c != '.')
        return c;
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c =='.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if ( c != EOF)
        ungetch(c);
    return NUMBER;
}
*/

#include<stdio.h>
#include<ctype.h>

#define NUMBER '0' //singal that a number was found

//getop: get next operator or numeric operand
int getop(char s[])
{
    static int c;
    int i, rc;
    static char lastc[] = " ";
    sscanf(lastc, "%c", &c);
    lastc[0] = ' ';
    while ((s[0] = c) == ' ' || c == '\t')
        if (scanf("%c", &c) == EOF)
            c = EOF;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    if (isdigit(c)) {
        do {
            rc = scanf("%c", &c);
            if (!isdigit(s[++i] = c))
                break;
        } while (rc != EOF);
    }
    if (c == '.')
        do {
             rc = scanf("%c", &c);
            if (!isdigit(s[++i] = c))
                break;
        } while (rc != EOF);
    s[i] = '\0';
    if (rc != EOF)
        lastc[0] = c;
    return NUMBER;
}