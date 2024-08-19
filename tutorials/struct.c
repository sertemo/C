#include <stdio.h>
#include <string.h>

struct Persona {
    char nombre[50];
    int edad;
    float altura;
};

int main() {
    // Declaración e inicialización de una estructura
    struct Persona persona1 = {"Juan Perez", 30, 1.75};

    // Modificación de los miembros de la estructura
    persona1.edad = 31;
    strcpy(persona1.nombre, "Juan Manuel Perez");

    // Acceso y uso de los miembros
    printf("Nombre: %s\n", persona1.nombre);
    printf("Edad: %d\n", persona1.edad);
    printf("Altura: %.2f\n", persona1.altura);

    return 0;
}

// Definición de la estructura Persona usando typedef
typedef struct {
    char nombre[50];
    int edad;
    float altura;
} Persona;

int main() {
    // Ahora puedes declarar variables del tipo Persona sin usar 'struct'
    Persona persona1;
    
    // Asignar valores a los miembros de la estructura
    strcpy(persona1.nombre, "Juan Perez");
    persona1.edad = 30;
    persona1.altura = 1.75;

    // Acceso y uso de los miembros
    printf("Nombre: %s\n", persona1.nombre);
    printf("Edad: %d\n", persona1.edad);
    printf("Altura: %.2f\n", persona1.altura);

    return 0;
}