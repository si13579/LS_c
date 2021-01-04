//编写一个程序，打印输入单词长度的直方图
/* 
#include<stdio.h>
#define IN 1
#define OUT 0
int main()
{
	int c,state,night[10];
	int nc=0;
	state = OUT;
	for(int i=0;i<10;i++)
	{
		night[i]=0;
	}
	while((c = getchar()) != EOF)
	{
		if(c==' '||c=='\t'||c=='\n'||c=='\b')
		{
			state = OUT;
			night[nc]++;
		}
		else if(state == OUT)
		{
			state = IN;
			nc = 1;
		}
		else
			nc++;
	}
	for(int i=0;i<10;i++)
	{
		printf("%d %d\n",i,night[i]);
	}
 }
 */
 /*
 #include<stdio.h>
 #define MAXHIST 15		//直方图的最大长度
 #define MAXWORD 11		//一个单词的最大长度
 #define IN 1			//在单词内部
 #define OUT 0			//在单词外部
 main()
 {
 	int c,i,nc,state;	//单词的长度 
 	int len;			//杆长
	int maxvalue;		//单词长度的个数最大值
	int ovflow;			//溢出字数单词 实际长度大于指定单词长度 
	int wl[MAXWORD];	//字长计数器
	state = OUT;
	nc = 0;				//一个字的字符数 单词的长度
	ovflow = 0;
	for(i=0;i<MAXWORD;++i)
		wl[i] = 0;
	while( (c = getchar()) != EOF)
	{
		if(c == ' '||c == '\n'||c == '\t' )
		{
			state = OUT;
			if(nc > 0)
				if(nc < MAXWORD)
					++wl[nc];
				else
					++ovflow;
			nc = 0;
		}
		else if(state == OUT)
		{
			state = IN;
			nc = 1;
		}
		else
			++nc;
	}
	maxvalue = 0;
	for(i = 1;i < MAXWORD;++i)
	{
		if(wl[i] > maxvalue)
			maxvalue = wl[i];
	}
	for(i = 1;i < MAXWORD;++i)
	{
		printf("%5d - %5d : ",i,wl[i]);
		if(wl[i] > 0)
		{
			if((len = wl[i] * MAXHIST / maxvalue) <= 0)
				len = 1;
		}
		else
			len = 0;
		while(len > 0)
		{
			putchar('*');
			--len;
		}
		putchar('\n');
			
		}
	if(ovflow > 0)
		printf("There are %d words >= %d\n",ovflow,MAXWORD);
	}
	*/
#include<stdio.h>
#define MAXWORD 11
#define MAXHIST 15
#define OUT 0
#define IN 1
int main()
{
	int i,c,nc,state;
	nc = 0;
	int len = 0;
	int wl[MAXWORD];
	int ovflow = 0;
	state = OUT;
	for(i=0;i<MAXWORD;i++)
		wl[i] = 0;
	while((c = getchar()) != EOF)
	{
		if(c == ' ' || c =='\n' || c=='\t')
		{
			state = OUT;
			if(nc>0)
			{
				if(nc<MAXWORD)
					wl[nc]++;
				else
					ovflow++;
				}
			nc = 0;	
		}
		else if(state == OUT)
		{
			state = IN;
			nc = 1;
		}
		else
			nc++;
	}
	int maxvalue = 0;
	for(i = 1;i < MAXWORD;i++)
	{
		if(maxvalue < wl[i])
			maxvalue = wl[i];
	}
	for(i = 1;i < MAXWORD;i++)
	{
		printf("%5d - %5d",i,wl[i]);
		if(wl[i] > 0)
		{
			//if((len = wl[i]*MAXHIST/maxvalue)<0)
			//	len = 1;
			len = wl[i]*MAXHIST/maxvalue;
		}
		else
			len = 0;
	while(len>0)
	{
		putchar('*');
		len--;
	}
	putchar('\n');
	}
	if(ovflow>0)
	{
		printf("There are %d words >= %d\n",ovflow,MAXWORD);
	}

	
}
