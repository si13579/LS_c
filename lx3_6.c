/*修改itoa函数，使得该函数可以接受三个参数。其中，第三个参数为最小字段宽度。
为了保证转换所得的结果至少具有第三个参数指定的最小宽度，在必要时应在所得结果的左边填充一定的空格。*/
#define abs(x) ((x) < 0 ? -(x) : (x))
void itoa(int n,char s[], int w)
{
    int i, sign;
    void reverse(char s[]);
    sign = n;
    i = 0;
    do {
        s[i++] = abs(n % 10) + '0';
    }while ((n /= 10) != 0);
    if (sign < 0)
        s[i++] = '-';
    while ( i < w)
        s[i++] = ' ';
    s[i] = '\0';
    reverse(s);
}