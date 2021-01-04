#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXLINES 100
typedef int Length;

Length len, maxlen;
Length *lengths[];

typedef char * String;

String p, lineptr[MAXLINES], alloc(int);
int strcmp(String, String);

main()
{
p = (String) malloc(100);
}
/*
struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *
talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}
*/
typedef struct tnode *
Treeptr;

typedef struct tnode {
    char *word;
    int count;
    Treeptr left;
    Treeptr right;
} Treenode;

Treeptr talloc(void)
{
    return (Treeptr) malloc(sizeof(Treenode));
}

typedef int (*PEI)(char *,char *);
PEI strcmps, numcmp;


/*
union u_tag
{
    int ival;
    float fval;
    char *sval;
} u;


void abc(utype)
{
    if (utype == INT)
        printf("%d\n",u.ival);
    else if (utype == FLOAT)
        printf("%f\n", u.fval);
    else if (utype == STRING)
        printf("%s\n", u.sval);
    else
        printf("bad type %d in utype\n", utype);
}
*/
/*
#define NSYM 100
struct t1 {
    char *name;
    int flags;
    int utype;
    union {
        int ival;
        float fval;
        char *sval;
    } u;
} symtab[NSYM];
int i = 1;
main()
{
    symtab[i].u.ival;
    *symtab[i].u.sval;
    symtab[i].u.sval[0];
}
*/
