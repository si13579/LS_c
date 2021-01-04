//删除每个输入行末尾的空格及制表符，并删除完全是空格的行
#include<stdio.h>
#define MAXLINE 1000
int getline(char s[],int lim);
int remove(char s[]);
int main()
{
	char line[MAXLINE];
	while(getline(line,MAXLINE) > 0){
		//printf("%d\n",getline(line,MAXLINE));
		if(remove(line) > 0)
			printf("%s",line);
	}
	return 0;
}
int getline(char s[],int lim)
{
	int c,i,j=0;
	for(i=0;(c = getchar()) != EOF && c != '\n';i++)
		if(i < lim-2)
			s[i]=c;
	if(c == '\n'){
		s[i]=c;
		i++;
	}
	s[i]='\0';
	printf("%d\n",i);
	return i;
}
		
int remove(char s[])
{
	int i = 0;
	while(s[i] != '\n')
		i++;
	i--; //1 
	while(i >= 0 && (s[i] == ' ' || s[i] == '\t'))
		i--;
	if(i >= 0){
		i++;
		s[i]='\n';
		i++;
		s[i]='\0';
	}
	return i;
}