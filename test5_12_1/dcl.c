#include "abc.h"
//dcl函数：对一个声明符进行语法分析
void dcl(void)
{
    int ns;
    for (ns = 0;gettoken() == '*'; )
        ns++;
    dirdcl();
    while (ns-- > 0)
        strcat(out, " pointer to");
}
//dirdcl函数：分析一个直接声明
void dirdcl(void)
{
    int type;
    if (tokentype == '(') {
        dcl();
        if (tokentype != ')')
            printf("error: missing )\n");
    } else if (tokentype == NAME)
        strcpy(name, token);
    else 
        printf("error: expected name or (dcl)\n");
    while ((type=gettoken()) == PARENS || type == BARCKETS)
        if (type == PARENS)
            strcat(out, " function returning");
        else {
            strcat(out," array");
            strcat(out, token);
            strcat(out, " of");
        }
}