#include<stdio.h>
#include<string.h>
#define MAXLINES 5000
#define MAXLEN 1000
char *lineptr[MAXLINES];
int readlines(char *lineptr[],int nlines);
void writelines(char *lineptr[],int nlines);
void qsort(void *lineptr[],int left,int right,int (*comp)(void *,void *));
int numcmp(char *,char *);
/*
int mystrcmp(char *s,char *t)
{
    int i;
    for(i = 0;s[i] == t[i];i++)
        if(s[i] == '\0')
            return 0;
    return s[i] - t[i];
}
*/
int mystrcmp(char *s,char *t)
{
    for(; *s == *t;s++,t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}

main(int argc,char *argv[])
{
    int nlines;
    int numeric = 0;
    if (argc > 1 && mystrcmp(argv[1],"-n") == 0)
        numeric = 1;
    if ((nlines = readlines(lineptr,MAXLINES)) >= 0 ){
        qsort((void **)lineptr, 0, nlines-1,
          (int (*)(void *,void *))(numeric ? numcmp : mystrcmp));
        writelines(lineptr,nlines);
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }
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
            printf("v[i]--%s\n",v[i]);
            printf("v[left]--%s\n",v[left]);
            swaps(v,++last,i);
        }
    int a = 1;
    printf("ceng %d\n",a);
    printf("last %d\n",last);
    a++;
    swaps(v,left,last);
    qsort(v,left,last-1,comp);
    qsort(v,last+1,right,comp);
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
void writelines(char *lineptr[],int nlines)
{
    while(nlines-- > 0)
        printf("%s\n",*lineptr++);
}