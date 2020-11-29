#include<stdio.h>
#define MAXLINE 1000	//允许输入的最大行的最大长度 
int getline(char line[],int maxline);
void copy(char to[],char from[]);
//打印最长的输入行 
int main()
{
	int len;	//当前行的长度 
	int max;	//目前为之发现的最长行的长度 
	char line[MAXLINE];		//当前的输入行 
	char longest[MAXLINE];	//用于保存最长的行
	max = 0;
	while((len = getline(line,MAXLINE)) > 0)
		if(len > max){
			max = len;
			copy(longest,line);
		} 
	if(max > 0)
		printf("%s",longest);
	return 0;
}
int getline(char s[],int lim)
{
	int c,i;
	static int nc = 0;
	for(i=0;i<lim-1 && ((c = getchar())!=EOF) && c != '\n';++i)
		s[i] = c;
	if(c == '\n'){
		s[i] = c;
		++i;
		nc++;
		printf("%d\n",nc);
		 
	}
	s[i] = '\0';
	return i;
	}
void copy(char to[],char from[])
{
	int i;
	i = 0;
	while((to[i] = from[i]) !='\0')
		++i;
}
