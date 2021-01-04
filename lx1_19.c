 // 编写函数reverse(s),将字符串s中的字符顺序颠倒过来，使用该函数编写一个程序，每次颠倒一个输入行中得字符顺序
 #include<stdio.h>
 #define MAXLINE 1000
 int getline(char line[],int lim);
 void reverse(char s[]);
 int main()
 {
	 char line[MAXLINE];
	 while(getline(line,MAXLINE) > 0){
		 reverse(line);
		 printf("%s",line);
	 }
	 //return 0;
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
void reverse(char s[])
{
	int i,j;
	i = 0;
	char temp;
	while(s[i] != '\0')
		i++;
	i--;
	if(s[i] == '\n')
		i--;
	j = 0;
	while(j<i){
		temp = s[j];
		s[j] = s[i];
		s[i] = temp;
		i--;
		j++;
	}
}
	