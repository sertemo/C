# include <stdio.h>

// El uso más frecuente de pointer arrays es para almacenar arrays de caracteres

char *month_name(int month) {  // devuelve un caracter pointer
    static char *name[13] = {  // un array de punteros a caracteres
        "no permitido",
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };
    return (month < 1 || month > 12) ? name[0] : name[month];
}