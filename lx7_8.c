#include<stdio.h>
#include<stdlib.h>

#define MAXBOT 3    //页底最大行数
#define MAXHDR  5   //页首最大行数
#define MAXLINE 100 //每行最大长度
#define MAXPAGE 66  //每页最大行数

main(int argc, char *argv[])
{
    FILE *fp;
    void fileprint(FILE *fp, char *fname);
    if (argc == 1)
        fileprint(stdin, " ");
    else 
        while (--argc > 0)
            if ((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "printf: can't open %s\n", *argv);
                exit(1);
            } else {
                fileprint(fp, *argv);
                fclose(fp);
            }
    return 0;
    
}

void fileprint(FILE *fp, char *fname)
{
    int lineno, pageno = 1;
    char line[MAXLINE];
    int heading(char *fname, int pageno);
    lineno = heading(fname, pageno++);
    while (fgets(line, MAXLINE, fp) != NULL) {
        if (lineno == 1) {
            fprintf(stdout, "\f");
            lineno = heading(fname, pageno++);
        }
        fputs(line, stdout);
        if (++lineno > MAXPAGE - MAXBOT)
            lineno = 1;
    }
    fprintf(stdout, "\f");
}
int heading(char *fname, int pageno)
{
    int ln = 3;

    fprintf(stdout, "\n\n");
    fprintf(stdout, "%s     page %d\n", fname, pageno);
    while (ln++ < MAXHDR)
        fprintf(stdout, "\n");
    return ln;
}