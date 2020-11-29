/*重新编写将大写字母转换为小写字母的函数lower，
并用表达式替代其中的if-else结构*/
int lower(int c)
{
    return c >= 'A' && c <= 'Z' ? c + 'a'-'A' : c;
}