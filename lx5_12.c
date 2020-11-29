/*
对程序entab和detab做一些扩充，以接受下列缩写的命令：
entab -m +n
表示制表符从第m列开始，每隔n列停止。选择（对使用者而言）比较方便的默认行为。
*/
#include<stdio.h>
#define MAXLINE 100
#define TABINC 8
#define YES 1
#define NO 0
void esettab(int argc,char *argv[],char *tab);
void entab(char *tab);
void detab(char *tab);
int tabpos(int pos,char *tab);
main(int argc,char *argv[])
{
    char tab[MAXLINE+1];
    esettab(argc,argv,tab);
    //entab(tab);
    detab(tab);
    return 0;
}
void esettab(int argc,char *argv[],char *tab)
{
    int i,inc,pos;
    if (argc <= 1)
        for (i = 1; i <= MAXLINE; i++)
            if (i % TABINC == 0)
                tab[i] = YES;
            else 
                tab[i] = NO;
    else if (argc == 3 && *argv[1] == '-' && *argv[2] == '+'){
        pos = atoi(&(*++argv)[1]);
        inc = atoi(&(*++argv)[1]);
        for ( i = 1; i < MAXLINE; i++)
            if (i !=pos)
                tab[i] = NO;
            else {
                tab[i] = YES;
                pos += inc;
            } 
    }
    else {
        for (i = 1; i <= MAXLINE; i++)
            tab[i] = NO; 
        while (--argc > 0) {
            pos = atoi(*++argv);
            if (pos > 0 && pos <= MAXLINE)
                tab[pos] = YES;
        }
    }
    }
void entab(char *tab)
{
    int c,pos;
    int nb = 0;
    int nt = 0;
    for (pos = 1; (c=getchar()) != EOF;pos++){
        if (c == ' '){
            if (tabpos(pos,tab) == NO)
                ++nb;
            else {  
                nb = 0;
                ++nt; 
            }
        } 
        else {
            for ( ; nt > 0; nt--)
                putchar('\t');
            if (c == '\t')
                nb = 0;
            else 
                for ( ; nb > 0; nb--)
                    putchar(' ');
            putchar(c);
            if (c == '\n')  
                pos = 0;
            else if (c == '\t')
                while (tabpos(pos,tab) != YES)
                    ++pos;
        }
    }
}
void detab(char *tab)
{
    int c,pos = 1;
    while ( (c = getchar()) != EOF)
        if ( c == '\t') {
            do 
                putchar(' ');
            while (tabpos(pos++,tab) != YES);
        } else if (c == '\n') {
            putchar(c);
            pos = 1;
        } else {
            putchar(c);
            ++pos;
        }
}
int tabpos(int pos,char *tab)
{
    if (pos > MAXLINE)
        return YES;
    else 
        return tab[pos];
}