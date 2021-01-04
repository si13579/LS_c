#include<stdio.h>
/*
#define KEYWORD 01
#define EXTERNAL    02
#define STATIC  04
*/
/*
enum {KEYWORD = 01, EXTERNAL = 02, STATIC = 04 };
main()
{
    flags |= EXTERNAL | STATIC;
    flags &= ~(EXTERNAL | STATIC);
}
*/
struct {
    unsigned int is_keyword : 1;
    unsigned int is_extern  : 1;
    unsigned int is_static  : 1;
} flags;

main()
{
    flags.is_extern = flags.is_static = 1;
    flags.is_extern = flags.is_static = 0;
}
