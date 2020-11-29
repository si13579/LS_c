//编写一个程序，以每行一个单词的形式打印其输入 
#include<stdio.h>
#define IN 0
#define OUT 1
main()
{
	int c,state;
	state = OUT;
	while((c = getchar()) != EOF)
	{
		if(c == ' ' || c == '\n'||c == '\b'||c=='\t')
		{
			if(state==IN)
			{
				putchar('\n');
				state = OUT;
			}
		}
		else if(state == OUT)
		{
			state = IN;
			putchar(c);
		}
		else
			putchar(c); 
	}
}
