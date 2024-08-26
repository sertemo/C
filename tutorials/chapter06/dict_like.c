# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define MAXWORD 50
# define LETTER 'a'
# define DIGIT  '0'

# define NKEYS 26

struct key {
    char *keyword;
    int keycount;
};

struct key keytab[NKEYS];

getword(w, lim) /* get next word from input */
char *w;
int lim;
{
    int c, t;
    if (type(c = *w++ = getch()) != LETTER) {
        *w = '\0';
        return(c);

    }

    while (--lim > 0) {
        t = type(c = *w++ = getch());
        if (t != LETTER && t != DIGIT) {
            ungetch(c);
            break;
        }
    }
    *(w-1) = '\0';
    return (LETTER);
}

int strcmp(char *s, char *t) {
    for ( ; *s == *t; s++, t++) {
        if (*s == '\0')
            return 0;
    }
    return *s - *t;
}

struct key *binary(char *word, struct key tab[], int n) /* find word. Devuelve un puntero a una estructura key */
{
    int cond;

    struct key *low = &tab[0];
    struct key *high = &tab[n-1];
    struct key *mid;

    while (low <= high) {
        mid = low + (high-low) / 2;
        if ((cond = strcmp(word, mid->keyword)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return (mid);
    }
    return(NULL);
}

main() /* count C keywords; pointer version */
{
    int t;
    char word[MAXWORD];
    struct key *binary(), *p;

    while ((t = getword(word, MAXWORD)) != EOF)
        if (t == LETTER)
            if ((p=binary(word, keytab, NKEYS)) != NULL)
                p->keycount++;
    for (p = keytab; p < keytab + NKEYS; p++)
        if (p->keycount > 0)
            printf("%4d %s\n", p->keycount, p->keyword);
}
