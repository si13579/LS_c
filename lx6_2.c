#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define MAXWORD 100
#define YES 1
#define NO  0
/*
struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};
*/
struct tnode
{
    char *word;
    int match;
    struct tnode *left;
    struct tnode *right;
};

/*
struct tnode *
addtree(struct tnode *, char *);
void treeprint(struct tnode *);
*/
struct tnode *
addtreex(struct tnode *, char *, int, int *);
void treexprint(struct tnode *);
int getword(char *, int);

/*
main()
{
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root,word);
    treeprint(root);
    return 0;
}
*/

main(int argc, char *argv[])
{
    struct tnode *root;
    char word[MAXWORD];
    int found = NO;
    int num;

    num = (--argc && (*++argv)[0] == '-') ? atoi(argv[0]+1) : 6;
    root = NULL;
    while (getword(word,MAXWORD) != EOF) {
        if (isalpha(word[0]) && strlen(word) >= num)
            root = addtreex(root, word, num, &found);
        found = NO; 
    }
    treexprint(root);
    return 0;
}

struct tnode *
talloc(void);
//char *strdupss(char *);
int compare(char *, struct tnode *, int, int *);

struct tnode *
addtreex(struct tnode *p,char *w, int num, int *found)
{
    int cond;
    if (p == NULL) {
        p = talloc();
        p->word = strdup(w);
        p->match = *found;
        p->left = p->right = NULL;
    }
    else if ((cond = compare(w, p, num, found)) < 0)
        p->left = addtreex(p->left, w, num, found);
    else if (cond > 0)
        p->right = addtreex(p->right, w, num, found);
    return p;
}

int compare(char *s, struct tnode *p, int num, int *found)
{
    int i;
    char *t = p->word;

    for (i = 0; *s == *t; i++, s++, t++)
        if (*s == '\0')
            return 0;
    if (i >= num) {
        *found = YES;
        p->match = YES;
    }
    return *s - *t;
}

void treexprint(struct tnode *p)
{
    if (p != NULL) {
        treexprint(p->left);
        if (p->match)
            printf("%s\n",p->word);
        treexprint(p->right);
    }
}
/*
struct tnode *
addtree(struct tnode *p, char *w)
{
    int cond;

    if (p == NULL) {
        p = talloc();
        p->word = strdupss(w);
        p->count = 1;
        p->left = p->right = NULL;
    } 
    else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;
    else if (cond < 0)
        p->left = addtree(p->left, w);
    else 
        p->right = addtree(p->right, w);
    return p;
}

void treeprint(struct tnode *p)
{
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}
*/
struct tnode *
talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strdupss(char *s)
{
    char *p;

    p = (char *) malloc(strlen(s)+1);
    if (p != NULL)
        strcpy(p,s);
    return p;
}

int getword(char *word,int lim)
{
    int c,getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace (c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0;w++)
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else 
        buf[bufp++] = c;
}