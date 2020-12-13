#include "abc.h"
int tokentype;
char token[MAXTOKEN];
//extern char name[MAXTOKEN];
//extern char out[1000];
//extern int prevtoken;
int prevtoken = NO;
int gettoken(void)  //返回下一个标记
{
    int c,getch(void);
    void ungetch(int);
    char *p = token;
    if (prevtoken == YES) {
        prevtoken = NO;
        return tokentype;
    }
    while ((c = getch()) == ' ' || c == '\t')
        ;
    if (c == '(') {
        if ((c = getch()) == ')') {
            strcpy(token,"()");
            return tokentype = PARENS;
        } else {
            ungetch(c);
            return tokentype = '(';
        }
    } else if (c == '[') {
        for (*p++ = c; (*p++ = getch()) != ']'; )
            ;
        *p = '\0';
        return tokentype = BARCKETS;
    } else if (isalpha(c)) {
        for (*p++ = c; isalnum(c = getch()); )
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    } else 
        return tokentype = c;
}