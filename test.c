#include<stdio.h>
#define TABINC 8
int main()
{
	int c,nb;
	int pos = 0;
	while( (c = getchar()) !=EOF){
		if(c == '\t'){
			nb = TABINC - pos%TABINC;
			while(nb>0){
				putchar(' ');
				nb--;
				pos++;
			}
		}
		else if(c == '\n'){
			putchar(c);
			pos=0;
		}
		else{
			putchar(c);
			pos++;
		}
	}
}