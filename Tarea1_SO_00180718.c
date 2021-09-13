#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "pthread.h"

void mate(int *arg){

    //Se crea el puntero a usar para abrir el archivo
    FILE* inp;
    //buffer usado para escribir en el archivo
    char buffer_inp[256];
   
    int suma, resta, multiply;

    //suma

    arg[2] = arg[1] + arg[0];

    //resta

    arg[3] = arg[0] - arg[1];

    //multiplicacion

    arg[4] = arg[0] * arg[1];

    //Se trabaja el archivo de texto y se cierra al terminar de usarlo
    fopen_s(&inp, "data.txt", "w");

    sprintf_s(buffer_inp, 256, "%d, %d, %d, %d, %d\n", arg[0], arg[1], arg[2], arg[3], arg[4]);

    fwrite(buffer_inp, sizeof(char), strlen(buffer_inp), inp);

    fclose(inp);

}
    
int main(void){

    int data[4];

    data[0] = 4;
    data[1] = 2;
    
    pthread_t h1;

    pthread_create(&h1, NULL, (void *)mate, (void *)&data);

    pthread_join(h1, NULL); 
      
    //Se muestran los datos en el main
    printf("%d, %d, %d, %d, %d\n", data[0], data[1], data[2], data[3], data[4]); 
}



