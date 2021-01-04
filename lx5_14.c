/*
修改排序程序，使它能处理-r标记。该标记表明，以逆序(递减)方式排序。
要保证-r和-n能够组合在一起使用
*/
#include<stdio.h>
#include<string.h>
#define NUMERIC 1
#define DECR    2
#define LINES   100
int numcmp(char *,char *);
int readlines(char *lineprt[],int maxlines);
void qsort(void *v[],int left,int right,
            int (*comp)(void *,void *));
void writelines(char *lineptr[],int nlines,int decr);
static char option = 0;
main(int argc,char *argv[])
{
    char *lineptr[LINES];
    int nlines;
    int c,rc = 0;

    while (--argc > 0 && (*++argv)[0] == '-')
        while (c = *++argv[0])
            switch (c) {
                case 'n':
                    option |= NUMERIC;
                    break;
                case 'r':
                    option |= DECR;
                    break;
                default:
                    printf("sort: illegal option %c\n",c);
                    argc = 1;
                    rc = -1;
                    break;
            }
    if (argc)
        printf("Usage: sort -nr \n");
    else 
        if ((nlines = readlines(lineptr,LINES)) > 0) {
            if (option & NUMERIC)
                qsort((void **) lineptr, 0, nlines - 1,
                    (int (*) (void *,void *)) numcmp);
            else 
                qsort((void **) lineptr, 0, nlines - 1,
                    (int (*) (void *,void *)) strcmp);
            writelines(lineptr,nlines,option & DECR);
        }
        else {
            printf("input too big to sort \n");
            rc = -1;
        }
    return rc;
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
int numcmp(char *s1,char *s2)
{
    double v1,v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else 
        return 0;
}
void qsort(void *v[],int left,int right,
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
    qsort(v,left,last-1,comp);
    qsort(v,last+1,right,comp);
}