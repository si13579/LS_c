/*
#include<ctype.h>
//auti函数，将s转换为整数型
int auti(char s[])
{
    int i, n, sign;
    for ( i = 0; isspace(s[i]);i++ )
        ;
    sign = (s[i]== '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for ( n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');
    return sign * n;
}
*/
//shellsort函数：按递增顺序对v[0]...v[n-1]进行排序
/*
#include<stdio.h>
void shellsort(int v[],int n)
{
    int gap, i, j, temp;
    for (gap = n/2; gap > 0; gap /= 2)
        for ( i = gap; i < n; i++)
            for ( j = i - gap; j >= 0 && v[j]>v[j+gap]; j -= gap){
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
}
int main()
{
    int v[]={1,5,3,2,8,7};
    int n = 6;
    shellsort(v,n);
}
*/
#include<string.h>
//reverse函数:倒置字符串s中各个字符的位置
void reverse(char s[])
{
    int c, i, j;
    for ( i = 0,j = strlen(s) - 1; i< j ; i++,j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}