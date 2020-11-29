#include<stdio.h>
#define MAXLINE 1000
#define LONGINE 10
int getline(char line[],int maxvalue);
int main()
{
	int len;
	char line[MAXLINE];
	while((len = getline(line,MAXLINE))>0){
		if(len > LONGINE)
			printf("%s",line);
	}
	return 0;
}
int getline(char s[],int lim)
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
