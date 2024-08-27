#include <stdio.h>

struct {
    unsigned is_keyword : 1;
    unsigned is_extern : 1;
    unsigned is_static : 1;
} flags;

int main(){
    printf("is_keyword: %d\n", flags.is_keyword);  // devuelve 0
    flags.is_keyword = ~flags.is_keyword;  // cambiamos el valor al contrario
    printf("is_keyword: %d\n", flags.is_keyword);  // devuelve 1
}