/*
 * @Date: 2020-07-30 00:07:18
编写一个程序以确定分别由signed及unsigned限定的char,short,int与long类型变量的取值范围。
采用打印标准头文件中的相应值以及直接计算两种方式实现.
 */ 
#include<stdio.h>
#include<limits.h>
//determine ranges of types
//确定类型范围
main()
{
    //signed types
    printf("signed char min = %d\n",SCHAR_MIN);
    printf("signed char max = %d\n",SCHAR_MAX);
    printf("signed short min = %d\n",SHRT_MIN);
    printf("signed short max = %d\n",SHRT_MAX);
    printf("signed int min = %d\n",INT_MIN);
    printf("signed int max = %d\n",INT_MAX);
    printf("signed long min = %d\n",LONG_MIN);
    printf("signed long max = %d\n",LONG_MAX);
    //unsigned types
    printf("unsigned char max = %u\n",UCHAR_MAX);
    printf("unsigned short max = %u\n",USHRT_MAX);
    printf("unsigned int max = %u\n",UINT_MAX);
    printf("unsigned long max = %u\n",ULONG_MAX);
}