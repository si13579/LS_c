#include<stdio.h>
#include<stdlib.h>
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
/*
main()
{
    double sum, v;
    
    sum = 0;
    while (scanf("%lf", &v) == 1)
        printf("\t%.2f\n", sum += v);
    return 0;
}
*/
char line[100];
int day,year,month;
char monthname[20];
main()
{
    while (getline(line, sizeof(line)) > 0) {
        if (sscanf(line, "%d %s %d", &day, monthname, &year) == 3)
            printf("valid: %s\n",line);
        else if (sscanf(line, "%d/%d/%d", &month, &day, &year) == 3)
            printf("valid: %s\n", line);
        else 
            printf("invalid: %s\n", line);
    }
}

