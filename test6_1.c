#include<stdio.h>
//struct {abc} x,y,z;
struct point
{
    int x;
    int y;
};
//struct point pt;
//struct point pt1 = {300,4};
//struct point pt2 = {5,8};
struct rect
{
    struct point pt1;
    struct point pt2;
};

//double dist,sqrt(double);
struct rect screen = {3,20,30,4};
main()
{
    //printf("%d,%d",pt.x,pt.y);
    //dist = sqrt((double)pt.x*pt.x + (double)pt.y*pt.y);
    //printf("%f",dist);
    printf("%d",screen.pt1.x);
    return 0;
}
