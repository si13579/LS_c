#include<stdio.h>
//回显程序命令行参数，版本2
main(int argc,char *argv[])
{
    while(--argc > 0)
        printf((argc > 1) ? "%s " : "%s", *++argv);
        //printf("%s%s",*++argv,(argc > 1) ? " " : "");
    printf("\n");
    return 0;
}
