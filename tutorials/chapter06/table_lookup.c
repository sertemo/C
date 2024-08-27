#include <stdio.h>
#include <stdlib.h>
#define HASHSIZE 100

struct nlist { /* basic table entry */
    char *name;
    char *def;
    struct nlist *next; /* next entry in chain */
};

static struct nlist *hashtab[HASHSIZE]; /* pointer table. Array de punteros */

strcpy(char *s, char *t) /* copy t to s; pointer version 3 */
    {
    while (*s++ = *t++);
    }

char *strsave(char *s) /* save string s somewhere */
    {
    char *p, *alloc();

    if ((p = alloc(strlen(s)+1)) != NULL)
        strcpy(p, s);
    return(p);
    }

hash(char *s) /* form hash value for string s */
    {
    int hashval;

    for (hashval = 0; *s != '\0'; )
        hashval += *s++;  // se añade el valor ASCII y se avanza el puntero
    return(hashval % HASHSIZE);
    }

struct nlist *lookup(char *s) /* look for s in hashtab */
    {
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)    
        if (strcmp(s, np->name) == 0)
            return(np); /* found it */
    return(NULL); /* not found */
    }

struct nlist *install(char *name, char *def) /* put (name, def) in hashtab*/
    {
    struct nlist *np, *lookup();
    char *strsave(), *malloc();
    int hashval;
    if ((np = lookup (name)) == NULL) { /* not found */
        np = (struct nlist *) alloc(sizeof(*np));
        if (np == NULL) return(NULL);
        if ((np->name = strsave(name)) == NULL) return (NULL);

        hashval = hash(np->name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else /* already there */
        free(np->def); /* free previous definition */
    if ((np->def = strsave(def)) == NULL)
        return(NULL);
    return(np);
    }