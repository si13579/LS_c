/*在数的二进制补码表示中，我们编写的itoa函数不能处理最大的负数，即n等于-(2的字长-1次幂)的情况。请解释其原因。
修改改函数，使它在任何机器上运行时都能打印出正确的值。*/
#define abs(x) ((x) < 0 ? (-x) : (x))
void itoa(int n,char s[])
{
    int i, sign;
    void reverse(char s[]);
    sign = n;
    i = 0;
    do{
        s[i++] = n % 10 + '0';
    }while((n /= 10) != 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}