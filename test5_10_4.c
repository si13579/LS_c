#include<stdio.h>
#include<string.h>
#define MAXLINE 1000
int getline(char *line,int max);
int getline(char s[],int lim)
{
    int c,i;
    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if ( c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}
//find函数：打印所有与第一个参数指定的模式相匹配的行
main(int argc,char *argv[])
{
    char line[MAXLINE];
    long lineno = 0;
    int c,except = 0,number = 0,found = 0;

    while (--argc > 0 && (*++argv)[0] == '-')
        while ( c = *++argv[0])
            switch (c) {
                case 'x':
                    except = 1;
                    break;
                case 'n':
                    number = 1;
                    break;
                default:
                    printf("find: illegal option %c\n",c);
                    argc = 0;
                    found = -1;
                    break;
            }
    if (argc != 1)
        printf("Usage: find -x -n pattern\n");
    else 
        while (getline(line,MAXLINE) > 0) {
            lineno++;
            if ((strstr(line,*argv) != NULL) != except) {
                if (number)
                    printf("%ld:",lineno);
                printf("%s",line);
                found++;
            } 
        }
    return found;
}
