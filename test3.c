#include<stdio.h>
int main()
{
    int a[]={1,2,3,4,5,6};
    int b = sizeof(a)/sizeof(a[0]);
    int low = 0;
    int high = b - 1;
    int x = 2;
    int mid = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if ( x < a[mid])
            high = mid - 1;
        else if ( x > a[mid])
            low = mid + 1;
        else
            return mid;        
    }
    printf("%d\n",mid);
    return 0;
} 
