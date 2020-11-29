//用指针方式实现第二章中的函数stract.函数strcat(s,t)将t指向的字符串复制到s指向的字符串的尾部。
void stract(char *s,char *t)
{
    while (*s)
        s++;
    while (*s++ = *t++)
        ;
}