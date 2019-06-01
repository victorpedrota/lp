#include "stdio.h"
#include "string.h"
#include "stdio.h"

int main(int argc, char const *argv[]) {
  char texto[20000];
  int tam,j,count=0,i;
  //scanf(" %s", texto);

  gets(texto);
  tam = strlen(texto);
  
  for ( i = 0, j = 0; i < tam; i++, j++) {
        if (texto[j] == ' ') {
            j++;
        }
        texto[i] = texto[j];
  }

  tam = strlen(texto);
  j = tam-1;
  for ( i = 0; i < tam; i++) {
    if(texto[i] != texto[j]){
      printf("nao");
      return 0;
    }
    j--;
  }
    printf("sim");

  return 0;
}
