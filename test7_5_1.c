#include<stdio.h>
main(int argc,char *argv[])
{
    FILE *fp;
    FILE *fp1;
    void filecopy1(FILE *, FILE *);
    
    if (argc == 1)
        filecopy1(stdin, stdout);
    else 
        while (--argc > 0)
            if ((fp = fopen(*++argv, "r")) == NULL) {
                printf("cat: can't open %s\n", *argv);
                return 1;
            } else {
                printf("%s",*++argv);
                fp1 = fopen(argv[2], "w");
                
                filecopy1(fp, fp1);
                fclose(fp);
                fclose(fp1);
            }
    return 0;
}
void filecopy1(FILE *ifp, FILE *ofp)
{
    int c;
    while ((c = getc(ifp)) != EOF)
        putc(c, ofp);
}