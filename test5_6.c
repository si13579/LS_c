#include<stdio.h>
#include<string.h>
#define MAXLINES 5000  //进行排序的最大文本行数
char *lineptr[MAXLINES]; //指向文本行的指针数组
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[],int nlines);
void qsort(char *lineptr[],int left,int right);
//对输入的文本行进行排序
main()
{
    int nlines; //读取的输入行数目
    if ((nlines = readlines(lineptr,MAXLINES)) >= 0){
        qsort(lineptr,0,nlines-1);
        writelines(lineptr,nlines);
        return 0;
    }
    else {
        printf("error: input too big to sort\n");
        return 1;
    }
} 
#define MAXLEN 1000 //每个输入文本行的最大长度

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
//readline函数: 读取输入行
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
        }
    return nlines;
}

//writelines函数：写输出行
/*
void writelines(char *lineptr[],int nlines)
{
    int i;
    for(i = 0;i < nlines;i++)
        printf("%s\n",lineptr[i]);
}
*/
void writelines(char *lineptr[],int nlines)
{
    while(nlines-- > 0)
        printf("%s\n",*lineptr++);
}
//qsort函数：按递增顺序对v[left]...v[right]进行排序
void swap(char *v[],int i,int j);
void qsort(char *v[],int left,int right)
{
    int i,last;
    if (left >= right)
        return;
    swap(v,left,(left + right)/2);
    last = left;
    for ( i = left + 1; i <= right;i++)
        if (strcmp(v[i],v[left]) < 0)
            swap(v,++last,i);
    swap(v,left,last);
    qsort(v,left,last-1);
    qsort(v,last+1,right);
}
//swap函数：交换v[i]和v[j]
void swap(char *v[],int i,int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}