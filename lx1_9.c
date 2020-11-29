//编写一个将输入复制到输出的程序，并将其中连续的多个空格用一个空格代替
/*
#include<stdio.h>
main()
{
	int c,flag;
	flag = 1;
	while((c = getchar()) != EOF)
	{
		if((c == ' ')&&(flag==1))
		{
			putchar(' ');
			flag = 0;
		}
		else if(c != ' ')
			{
			putchar(c); 
			flag = 1;
				}
 }
}
*/
/*
#include<stdio.h>
#define NONBLANK 'a'
main()
{
	int c,lastc;
	while((c = getchar()) != EOF)
	{
		if(c != ' ')
			putchar(c);
		if(c == ' ')
			if(lastc != ' ')
				putchar(c);
		lastc = c;
	}
}
*/
/*
#include<stdio.h>
#define NONBLANK 'a'
main()
{
	int c,lastc;
	while((c = getchar()) != EOF)
	{
		if(c != ' ')
			putchar(c);
		else if(lastc != ' ')
			putchar(c);
		lastc = c;
	}
}
*/
#include<stdio.h>
#define NONBLANK 'a'
main()
{
	int c,lastc;
	while((c = getchar()) != EOF)
	{
		if(c != ' ' || lastc != ' ')
			putchar(c);
		lastc = c;
	}
}
