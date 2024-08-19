// es el algoritmo de Peterson optimizado

# include <stdio.h>
# define N 2  // numero de procesos
# define True 1
# define False 0


int flag[N] = {False};  // Inicializamos a False todos
int turn;

void Dekkers_Algorithm(int i) 
{
    int j = NOT(i);
    while (True) {
        // tareas no CS
        printf("Fuera de la zona critica");
        // Hacemos el proceso actual interesado
        flag[i] = True;
        while(flag[j] == True){  // Si el otro proceso está interesado
            if (turn == j) {  // Y es el turno del otro proceso
                // Quitamos el interés en entrar
                flag[i] = False;
                while (turn == j);  // Busy wait mientras el turno sea del otro proceso
                flag[i] = True;

            }
        };
        // Entramos en zona crética
        printf("En la zona critica");
        // Indicamos con la flag que hemos finalizado
        flag[i] = False;
        turn = j;
    }
}