/*
编写程序tail,将其输入中的最后n行打印出来。默认情况下，n的值为10，但可通过一个可选参数改变n的值，因此命令
tail -n
将打印其输入的最后n行。无论输入或n的值是否合理，该程序都应该能正常运行。
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DEFLINES    10
#define LINES       100
#define MAXLEN      100
void error(char *);
int getline(char *,int);
main(int argc,char *argv[])
{
    char *p;
    char *buf;              //pointer to large buffer
    char *bufend;           //end of the buffer
    char line[MAXLEN];      //current input line
    char *lineptr[LINES];   //pointers to lines read
    int first,i,last,len,n,nlines;
    if(argc == 1)
        n = DEFLINES;
    else if (argc == 2 && (*++argv)[0] == '-')
        n = atoi(argv[0]+1);
    else 
        error("usage: tail [-n]");
    if (n < 1 || n > LINES)
        n = LINES;
    for (i = 0; i < LINES; i++)
        lineptr[i] = NULL;
    if (( p = buf = malloc(LINES * MAXLEN)) == NULL)
        error("tail:cannot allocate buf");
    bufend = buf + LINES * MAXLEN;
    last = 0;
    nlines = 0;
    while ((len = getline(line,MAXLEN)) > 0) {
        if ( p + len + 1 >= bufend)
            p = buf;
        lineptr[last] = p;
        strcpy(lineptr[last],line);
        if (++last >= LINES)
            last = 0;
        p += len + 1;
        nlines++;
    }
    if (n > nlines)
        n = nlines;
    first = last - n;
    if (first < 0)
        first += LINES;
    for (i = first; n-- > 0; i = (i+1)%LINES)
        printf("%s",lineptr[i]);
    return 0;
}
void error(char *s)
{
    printf("%s\n",s);
    exit(1);
}
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