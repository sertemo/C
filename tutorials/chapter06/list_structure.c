
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define MAXLINE 100

// En C tenemos que crear una estructura de lista antes de poder usarla

struct lnode {
    char *text;
    struct lnode *next;
    struct lnode *prev;  // para hacer la lista reversible
};

// se necesita definir el head y el tail de la lista

struct lnode *head;
struct lnode *tail;

void print_list(struct lnode *head) {
    struct lnode *current;
    for (current = head; current != NULL; current = current->next) {
        printf("%s", current->text);
    }
}

void print_reverse_list(struct lnode *tail) {
    struct lnode *current;
    for (current = tail; current != NULL; current = current->prev) {
        printf("%s", current->text);
    }
}

int main() {
    char line[MAXLINE];
    while (fgets(line, MAXLINE, stdin) != NULL) {
        char *save = (char *) malloc(sizeof(line) + 1);
        strcpy(save, line);

        struct lnode *new = (struct lnode *) malloc(sizeof(struct lnode));

        if ( tail != NULL ) tail->next = new;
        new->text = save;
        new->next = NULL;
        new->prev = tail;
        tail = new;  // Aqui hacemos que tail apunte al nuevo nodo ( la cola avanza)

        if (head == NULL) head = new;
    }
    
    printf(">> Imprimimos la lista en orden\n");
    print_list(head);
    printf("\n");
    printf(">> Imprimimos la lista al reves\n");
    print_reverse_list(tail);
    printf("\n");
}