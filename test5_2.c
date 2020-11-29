#include<stdio.h>
void swap(int *px,int *py)
{
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
}
int main(){
    int a = 6;
    int b = 5;
    swap(&a,&b);
    printf("%d",a);
}