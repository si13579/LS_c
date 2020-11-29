/*编写一个函数escape(s,t),将字符串t复制到字符串s中，并在复制过程中将换行符、制表符等不可见字符分别转换为\n、\t等相应的可见的转义字符序列。
要求使用switch语句。再编写一个具有相反功能的函数，在复制过程中将转义字符序列转换为实际字符。*/

/*
//1
void escape(char s[],char t[])
{
    int i,j;
    for (i = j = 0; t[i] != '\0';i++){
        switch (t[i]){
            case ('\n'):
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case ('\t'):
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = t[i];
                break;
        }
        s[j] = '\0';
    }
}
*/
//2.1
/*
#include<stdio.h>
void unescape(char s[], char t[])
{
    int i,j;
    for ( i = j = 0; t[i] != '\0';i++)
        if (t[i] != '\\')
            s[j++] = t[i];
        else 
            switch (t[++i]){
                case 'n':
                    s[j++] = '\n';
                    break;
                case 't':
                    s[j++] = '\t';
                    break;
                default:
                    //s[j++] = '\\';
                    s[j++] = t[--i];
                    break;
            }
        s[j] = '\0';
    }
int main()
{
    int i;
    char t[]={'a','b','c'};
    char r[3];
    unescape(r,t);
    for (i=0;i<3;i++)
        printf("%c\n",r[i]);
}
*/
//2.2
void unescape(char s[],char t[])
{
    int i,j;
    for (i = j = 0; t[i] != '\0';i++)
        switch (t[i]){
        case '\\':
            switch (t[++i]){
            case 'n':
                s[j++] = '\n';
                break;
            case 't':
                s[j++] = '\t';
                break;
            default:
                s[j++] = '\\';
                s[j++] = t[i];
                break;
            }
            break;
        default:
            s[j++] = t[i];
            break;
        }
        s[j] = '\0';
}