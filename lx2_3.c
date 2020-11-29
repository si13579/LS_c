/*
 * @Date: 2020-08-03 23:16:45
编写函数htoi(s),把由十六进制数字组成的字符串（包含可选的前缀0x或0X)转换为
与之等价的整型值。字符串中允许的数字包括:0~9,a~f,以及A~F.
 */
#include<stdio.h>
#define YES 1
#define NO  0
//hoti:convert hecadecimal string s to integer
int htoi(char s[])
{
    int hexdigit,i,inhex,n;
    i = 0;
    if (s[i] == '0'){
        ++i;
        if (s[i] =='x' || s[i] == 'X')
            ++i;
    }
n = 0;
inhex = YES;
for ( ; inhex == YES; ++i){
    if (s[i] >= '0' && s[i] <= '9')
        hexdigit = s[i] - '0';
    else if (s[i] >= 'a' && s[i] <= 'f')
        hexdigit = s[i] - 'a' + 10;
    else if (s[i] >= 'A' && s[i] <= 'F')
        hexdigit = s[i] - 'A' + 10;
    else 
        inhex = NO;
    if (inhex == YES)
        n = 16 * n + hexdigit;
}
    //return n;
    printf("%d\n",n);
}
int main()
{
    char s[4];
    int c,i;
    for (i=0; (c = getchar()) != EOF && i<4; i++)
        s[i] = c;
    htoi(s);

    
}