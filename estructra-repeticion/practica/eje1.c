/*
    1. WHIEL
        while es la estructura de repeti mas segura 
    
    2. DO WHILE()
        Se usa para menu de opciones

    3. FOR()
        Se usa para rengos de numeracion.

    - Tipos de variables a usar en estos bucles
        - Acumuladoras. 
        - Contadoras.

    Para las variables contadoras:
        * variable = variable + 1;
            variable++  -> Pos incremento.
            ++variable  -> Pre incremento.
        
        * variable = variable - 1;
            varibale--
            --variable

    Para las  variables acumuladoras:
        * variable = variable + acumulo;
            variables += acumulo;

        * variable = variable - acumulo;
            variable -= acumulador;

        * variable = variable * acumulo;
            variable *= acumulador;

        * variable = variable / acumulo;
            variable /= acumulador;


*/
#include <stdio.h>

int main() {
    int num;
    printf("Ingrese numero para las tablas: ");
    scanf("%d", &num);
    int i;
    printf("---------- FOR ----------\n");
    for(i = 0; i <= 12; i++){
        printf("%d x %d = %d\n",num, i, (num * i));
    } 

    i=0;
    printf("\n---------- WHILE ----------\n");
    while (i <= 12) {
        printf("%d x %d = %d\n",num, i, (num * i));
        
        i++;
    }
    
    i = 0;
    printf("\n---------- DO WHILE ----------\n");
    do {
        printf("%d x %d = %d\n",num, i, (num * i));
        
        i++;
    }while (i <= 12);
    

    return 0;
}
