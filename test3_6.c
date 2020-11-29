//itca函数:将数字n转换为字符串并保存到s中
void itca(int n,char s[])
{
    int i, sign;
    if ( (sign = n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    }while ( (n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

