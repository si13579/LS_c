#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAXTOKEN 100
#define BUFSIZE 100
enum { NAME, PARENS, BARCKETS };
enum { NO,  YES};
void dcl(void);
void dirdcl(void);
int gettoken(void);
int nexttoken(void);
void errmsg(char *);

//int tokentype;              //最后一个记号的类型
//char token[MAXTOKEN];       //最后一个记号字符串
//char name[MAXTOKEN];        //标识符名
char datatype[MAXTOKEN];    //数据类型为char、int等
//char out[1000];             //输出字符串