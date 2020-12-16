#include<stdlib.h>
#include "abc.h"
void dclspec(void);//声明规则
int typespec(void);
int typequal(void);
int compare(void **,void **);
extern int tokentype;
extern char token[];
extern char name[MAXTOKEN];
extern int prevtoken;
extern char out[1000];
void parmdcl(void) //解析参数声明符
{
    do {
        dclspec();
    } while (tokentype == ',');
    if (tokentype != ')')
        errmsg("missing ) in parameter declaration\n");
}
void dclspec(void)
{
    char temp[MAXTOKEN];
    temp[0] = '\0';
    gettoken();
    do {
        if (tokentype != NAME) {
            prevtoken = YES;
            dcl();
        } else if (typespec() == YES) {
            strcat(temp, " ");
            strcat(temp, token);
            gettoken();
        } else if (typequal() == YES) {
            strcat(temp, " ");
            strcat(temp, token);
            gettoken();
        } else 
            errmsg("unknown type in parameter list\n");
    } while (tokentype != ',' && tokentype != ')');
    strcat(out, temp);
    if (tokentype == ',')
        strcat(out, ",");
}
int typespec(void) //token是类型说明符
{
    static char *types[] = {
        "char",
        "int",
        "void"
    };
    char *pt = token;
    if (bsearch(&pt,types,sizeof(types)/sizeof(char *),
        sizeof(char *), compare) == NULL)
        return NO;
    else 
        return YES;
}
int typequal(void)
{
    static char *typeq[] = {
        "const",
        "volatile"
    };
    char *pt = token;
    if (bsearch(&pt,typeq,sizeof(typeq)/sizeof(char *),
        sizeof(char *), compare) == NULL)
        return NO;
    else 
        return YES;
}
int compare(void **s,void **t)
{
    return strcmp(*s, *t);
}