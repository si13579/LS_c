#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};

#define HASHSIZE 101
static struct nlist *
hashtab[HASHSIZE];

unsigned hash(char *s)
{
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

struct nlist *
lookup(char *);
//char *strdupss(char *);

struct nlist *
install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) {
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;  
    }
    else 
        free((void *) np->defn);
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np; 
}

/*
char *strdupss(char *s)
{
    char *p;

    p = (char *) malloc(strlen(s)+1);
    if (p != NULL)
        strcpy(p,s);
    return p;
}
*/

struct nlist *
lookup(char *s)
{
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s,np->name) == 0)
            return np;
    return NULL;
}

void undef(char *s)
{
    int h;
    struct nlist *prev, *np;
    prev = NULL;
    h = hash(s);
    for (np = hashtab[h]; np!= NULL; np = np->next) {
        if (strcmp(s, np->name) == 0)
            break;
        prev = np;
    }
    if (np != NULL) {
        if (prev == NULL)
            hashtab[h] = np->next;
        else 
            prev->next = np->next;
        free((void *) np->name);
        free((void *) np->defn);
        free((void *) np);
    }

}
main()
{
    char *name = "abc";
    char *defn = "1";
    install(name,defn);
    lookup(name);
    printf("%s\n",hashtab[hash(name)]->defn);
    undef(name);
    if ((hashtab[hash(name)]) == NULL)
        printf("222");
    return 0;
}
