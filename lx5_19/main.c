#include "abc.h"

extern char token[MAXTOKEN];
extern char name[MAXTOKEN];
char out[1000];
//extern int prevtoken;6
//extern int tokentype;
//extern char token[];
//extern char out[];

/*
extern int tokentype;
main()  //将声明转换为文字描述
{
    while (gettoken() != EOF) {     //该行的第一个记号是数据类型
        strcpy(datatype,token);
        out[0] = '\0';
        dcl();          //分析该行的其余部分
        if (tokentype != '\n')
            printf("syntax error\n");
        printf("%s: %s %s\n",name, out, datatype);
    }
    return 0;
} 
*/      

main()
{
    int type;
    char temp[MAXTOKEN];
    while (gettoken() != EOF) {
        strcpy(out, token);
        while ( ( type = gettoken()) != '\n')
            if (type == PARENS || type == BARCKETS)
                strcat(out, token);
            else if (type == '*') {
                if ((type = nexttoken()) == PARENS || type == BARCKETS)
                    sprintf(temp, "(*%s)", out);
                else 
                    sprintf(temp, "*%s", out);
                strcpy(out, temp);
            } else if (type == NAME) {
                sprintf(temp, "%s %s",token,out);
                strcpy(out,temp);
            } else 
                printf("invalid input at %s\n", token);
        printf("%s\n",out);
    }
}
