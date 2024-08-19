// Implementación de la peterson's solution en sincronización de procesos
// Combinación de Lock variable y strict alternation
// Solución para 2 procesos
// 2 variables_ flag y turn
// flag es para indicar el interés en entrar en Critical sesion
// turn es para indicar el turno de cada proceso

# include <stdio.h>

# define N 2  // numero de procesos
# define True 1
# define False 0

int flag[N] = {False};  // Inicializamos a False todos
int turn;

void Process(int i) {
    int j = NOT(i);
    while (True) {
        // tareas no CS
        printf("Fuera de la zona critica");
        // Hacemos el proceso actual interesado
        flag[i] = True;
        turn = i;
        while (flag[j] == True && turn == i);  /*Busy wait si hay otro proceso interesado y
                                                soy el último en actualizar turn*/ 
        // Entramos en zona crítica
        printf("En la zona critica");
        // Indicamos con la flag que hemos finalizado
        flag[i] = False;
    }
}