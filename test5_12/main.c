#include "abc.h"
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