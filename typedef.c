// Se puede crear un nodo de un arbol usando un alias

# include <stdio.h>

typedef struct tnode {   /* the basic node */
    char *word; /* points to the text */
    int count; /* number of occurrences */
    struct tnode *left;  /* left child */
    struct tnode *right; /* right child */
} TREENODE, *TREEPTR;


