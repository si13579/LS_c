#include<stdio.h>
#include<ctype.h>
#define MAXLINE 100
#define NUMBER '0'
int getlines(char line[],int limit);
int li = 0; //input line index
char line [MAXLINE];    //
int getop(char s[])
{
    int c,i;
    if (line[li] == '\0')
        if (getlines(line,MAXLINE) == 0)
            return EOF;
        else 
            li = 0;
    while ((s[0] = c = line[li++]) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;
	i = 0;
	if (isdigit(c))
		while (isdigit(s[++i] = c = line[li++]))
			;
	if (c == '.')
		while (isdigit(s[++i] = c = line[li++]))
			;
	s[i] = '\0';
	li--;
	return NUMBER;
}

int getlines(char s[],int lim)
{
	int c,i,j=0;
	for(i=0;(c = getchar()) != EOF && c != '\n';i++){
		if(i<lim-2){
			s[j]=c;
			j++; 
		}
	}
	if(c == '\n'){
		s[j]=c;
		i++;
		j++;
	}
	s[j]='\0';
	return i;
}
