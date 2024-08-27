# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define DEFAULT_SIZE 10

// Vamos a construir un objeto tipo String en C, simulando Python

struct pystr {  // Los atributos serán "privados"
    int length;
    int alloc; /* the length of data*/
    char *data;
};

// El constructor
struct pystr *pystr_new(void) {
    struct pystr* p = malloc(sizeof(struct pystr));
    p->length = 0;
    p->alloc = DEFAULT_SIZE;  // por ejemplo 10
    p->data = malloc(DEFAULT_SIZE);
    p->data[0] = '\0';  // Ponemos el 0 al principio
    return p;
}

// El destructor
void pystr_del(const struct pystr *self) {
    free((void*) self->data);  // primero el string
    free((void*) self);  // luego el objeto completo
}

// Método para printear
void pystr_dump(const struct pystr *self) {
    printf("String = %s\n", self->data);
    printf("Length = %d\n", self->length);
    printf("Alloc = %d\n", self->alloc);
    printf("################\n");
}

// Método para devolver la longitud de la cadena
int pystr_len(const struct pystr *self) {
    return self->length;
}

char *pystr_str(const struct pystr *self) {
    return self->data;
}

// Método para concatenar un caracter: x = x + 'h'
void pystr_append(struct pystr *self, char c) {
    if (self->length >= self->alloc) {
        self->alloc += 10;
        self->data = realloc(self->data, self->alloc);
    }
    self->data[self->length] = c;
    self->data[self->length + 1] = '\0';
    self->length++;
}

// Método para concatenar un string: x = x + "hello world"
void pystr_appends(struct pystr *self, const char *s) {
    int len = strlen(s);
    
    // Redimensionar si es necesario
    if (self->length + len >= self->alloc) {
        self->alloc = self->length + len + 1;  // +1 para el terminador nulo
        self->data = realloc(self->data, self->alloc);
    }
    
    // Apuntar al final de la cadena actual con un puntero temporal
    char *p = self->data + self->length;

    // Copiar los caracteres de 's' en el espacio disponible
    while (*s) {
        *p++ = *s++;
    }
    
    // Colocar el terminador nulo al final
    *p = '\0';

    // Actualizar la longitud de la cadena
    self->length += len;
}

// Método para asignar un string: x = "hello world"
void pystr_assign(struct pystr *self, const char *s) {
    int len = strlen(s);
    if (self->length < len) {
        self->alloc = len;
        self->data = realloc(self->data, self->alloc);
    }
    strcpy(self->data, s);
    self->length = len;
}


int main(void) {
    printf("Testing pystr class\n");
    struct pystr *x = pystr_new();  // llamamos al constructor

    pystr_dump(x);  // printeamos el contenido del string

    pystr_append(x, 'H');
    pystr_dump(x);

    pystr_appends(x, "ello world");
    pystr_dump(x);

    pystr_assign(x, "A completely new string");
    printf("String = %s\n", pystr_str(x));
    printf("Length = %d\n", pystr_len(x));
    pystr_dump(x);
    printf("Tamaño del objeto str: %d bytes\n", sizeof(*x));
    pystr_del(x);
    return 0;
}