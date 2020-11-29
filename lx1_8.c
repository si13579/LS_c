//编写一个统计空格、制表符与换行符个数的程序
#include<stdio.h>
main()
{
	int c,ns,nt,nl;
	ns = nt = nl = 0;
	while((c = getchar())!= EOF)
	{
		if(c == ' ')
			++ns;
		else if(c == '\t')
			++nt;
		else if(c == '\n')
			++nl;
	}
	printf("ns %d nt%d nl%d",ns,nt,nl);
 } 
