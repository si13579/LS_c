/*编写一个函数rightrot(x,n),该函数返回将x循环右移（即从最右端移出的位将从最左端移入)n(二进制)位后所得到的值*/
/* rigthrot:rotate x to the right by n positions 将x右旋转n个位置*/
//wordlength:computes word of the machine
int wordlength(void)
{
    int i;
    unsigned v = (unsigned) ~0;
    for (i = 0;(v = v >> 1) > 0;i++)
        ;
    return i;
}
unsigned rightrot(unsigned x,int n)
{
    int wordlength(void);
    int rbit;   //rightmost bit  

    while (n-- >0){
        rbit = (x & 1) << (wordlength() - 1);
        x = x >> 1;
        x = x | rbit;
    }
    return x;
}