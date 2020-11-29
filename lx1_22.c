/*编写一个程序，把较长的输入行“折”成短一些的两行或多行，折行的位置在输入行的第n列之前的最后一个非空格之后，
要保证程序能够智能地处理输入行很长以及在指定的列前没有空格或制表符的情况*/
#include<stdio.h>
#define MAXCDL 10
#define TABINC 8
char line[MAXCDL];
int exptab(int pos);	//将制表符展开为空格
int findblnk(int pos);	//找到空白的位置
int newpos(int pos);	//重新排列行与新的位置
void printl(int pos);	//打印行直到pos列
main()
{
	int c,pos;
	pos = 0;
	while( (c = getchar()) != EOF){
		line[pos] = c;
		if( c == '\t')
				pos = exptab(pos);
		else if(c == '\n'){
			printl(pos);
			pos = 0;
		}
		else if(++pos >= MAXCDL){
			pos = findblnk(pos);
			printl(pos);
			pos = newpos(pos);
		}
	}
}
void printl(int pos)
{
	int i;
	for(i=0;i<pos;++i)
		putchar(line[i]);
	if(pos>0)
		putchar('\n');
}
int exptab(int pos)
{
	line[pos] = ' ';
	for(++pos;pos<MAXCDL && pos%TABINC !=0;++pos)
		line[pos]= ' ';
	if(pos<MAXCDL)
		return pos;
	else{
		printl(pos);
		return 0;
	}
}
int findblnk(int pos)
{
	while(pos>0 && line[pos] != ' ')
		--pos;
	if(pos == 0)
		return MAXCDL;
	else return pos+1;
}
int newpos(int pos)
{
	int i,j;
	if(pos<=0 || pos >= MAXCDL)
		return 0;
	else{
		i = 0;
		for(j=pos;j<MAXCDL;++j){
			line[i]=line[j];
			++i;
		}
		return i;
	}
}