 /*
增加字段处理功能，以使得排序程序可以根据行内的不同字段进行排序，每个字段按照一个单独的选项集合进行排序。
（在对英文原书索引进行排序时，索引条目使用了-df选项，而对页码排序时使用了-n选项。）
*/
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#define NUMERIC 1   //数值排序
#define DECR    2   //降序
#define FOLD    4   //不区分大小写
#define DIR     8   //目录排序（对字母、空格、数值排序)
#define LINES   100
#define MAXSTR  100 
int charcmp(char *,char *);
void error(char *);
int numcmp(char *,char *);
void readargs(int argc,char *argv[]);
int readlines(char *lineprt[],int maxlines);
void qsorts(void *v[],int left,int right,
            int (*comp)(void *,void *));
void writelines(char *lineptr[],int nlines,int order);
static char option = 0;
int pos1 = 0;
int pos2 = 0;
main(int argc,char *argv[])
{
    char *lineptr[LINES];
    int nlines;
    int rc = 0;

    readargs(argc,argv);     
    if ((nlines = readlines(lineptr,LINES)) > 0) {
        if (option & NUMERIC)
            qsorts((void **) lineptr, 0, nlines - 1,
                    (int (*) (void *,void *)) numcmp);
        else 
            qsorts((void **) lineptr, 0, nlines - 1,
                    (int (*) (void *,void *)) charcmp);
        writelines(lineptr,nlines,option & DECR);
    }
    else {
        printf("input too big to sort \n");
        rc = -1;
        }
    return rc;
}
void readargs(int argc,char *argv[])
{
    int c;
    //int atoi(char *);
    while (--argc > 0 && (c = (*++argv)[0]) == '-' || c == '+'){
        if ( c == '-' && !isdigit(*(argv[0]+1)))
            while (c = *++argv[0])
                switch (c) {
                case 'd':
                    option |= DIR;
                    break;
                case 'f':
                    option |= FOLD;
                    break;
                case 'n':
                    option |= NUMERIC;
                    break;
                case 'r':
                    option |= DECR;
                    break;
                default:
                    printf("sort: illegal option %c\n",c);
                    error("Usage: sirt -dfnr [+pos1] [-pos2]");
                    break;
            }
        else if (c == '-')
            pos2 = atoi(argv[0]+1);
        else if ((pos1 = atoi(argv[0]+1)) < 0)
            error("Usage: sort -dfnr [+pos1][-pos2]");
    }
    if (argc || pos1 > pos2 )
        error("Usage: sort -dfnr [+pos1][-pos2]");
}

void substr(char *t,char *s,int maxstr);
int numcmp(char *s1,char *s2)
{
    double v1,v2;
    char str[MAXSTR];
    substr(s1,str,MAXSTR);
    v1 = atof(str);
    substr(s2,str,MAXSTR);
    v2 = atof(str);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else 
        return 0;
}
void writelines(char *lineptr[],int nlines, int decr)
{
    int i;
    if (decr)
        for (i = nlines - 1;i >= 0;i--)
            printf("%s\n",lineptr[i]);
    else 
        for (i = 0; i < nlines; i++)
            printf("%s\n",lineptr[i]);
}
void swaps(void *v[],int i,int j)
{
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
int getliness(char *s,int lim)
{
    char *t = s;
    int c;
    while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if ( c == '\n')
        *s++ = c;
    *s = '\0';
    return s - t;
}
#define ALLOCSIZE 10000
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;
char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n){
        allocp += n;
        return allocp - n;
    }
    else 
        return NULL;
}

void afree(char *p)
{
    if (p >= allocp && p < allocbuf + ALLOCSIZE)
        allocp = p;
}
#define MAXLEN  1000
int readlines(char *lineptr[],int maxlines)
{
    int len,nlines;
    char *p,line[MAXLEN];
    nlines = 0;
    while ( (len = getliness(line,MAXLEN)) > 0)
        if ( nlines >= maxlines || ( p = alloc(len)) == NULL)
            return -1;
        else {
            line[len - 1]= '\0';
            strcpy(p,line);
            lineptr[nlines++] = p;
            //printf("nlines = %s \r\n", lineptr[nlines-1]);
        }
    return nlines;
}

int charcmp(char *s,char *t)
{
    char a,b;
    int i,j,endpos;
    extern char option;
    extern int pos1,pos2;
    int fold = (option & FOLD) ? 1 : 0;
    int dir = (option & DIR) ? 1 : 0;
    i = j = pos1;
    if (pos2 > 0)
        endpos = pos2;
    else if ((endpos = strlen(s)) > strlen(t))
        endpos = strlen(t);
    do {
        if (dir) {
            while ( i < endpos && !isalnum(s[i]) && s[i] != ' ' && s[i] != '\0')
                i++;
            while ( j < endpos && !isalnum(t[j]) && t[j] != ' ' && t[j] != '\0')
                j++;
        }
        if ( i < endpos && j < endpos) {
            a = fold ? tolower(s[i]) : s[i];
            i++;
            b = fold ? tolower(t[j]) : t[j];
            j++;
            if (a == b && a == '\0')
                return 0;
        }
    } while (a == b && i < endpos && j < endpos);
    return a - b;
}
void qsorts(void *v[],int left,int right,
        int (*comp)(void *,void *))
{
    int i,last;
    void swaps(void *v[],int,int);
    if (left >= right)
        return;
    swaps(v,left,(left+right)/2);
    last = left;
    for (i = left+1; i <= right;i++)
        if ((*comp)(v[i],v[left]) < 0)
        {   
            //printf("v[i]--%s\n",v[i]);
            //printf("v[left]--%s\n",v[left]);
            swaps(v,++last,i);
           }
    //int a = 1;
    //printf("ceng %d\n",a);
    //printf("last %d\n",last);
    //a++;
    swaps(v,left,last);
    qsorts(v,left,last-1,comp);
    qsorts(v,last+1,right,comp);
}
void error(char *s)
{
    printf("%s\n",s);
    exit(1);
}
void substr(char *s,char *str,int maxstr)
{
    int i,j,len;
    extern int pos1,pos2;
    len = strlen(s);
    if (pos2 > 0 && len > pos2)
        len = pos2;
    else if (pos2 >0 && len < pos2)
        error("substr: string too short");
    for(j = 0,i = pos1; i < len; i++,j++)
        str[j] = s[i];
    str[j] = '\0';
}