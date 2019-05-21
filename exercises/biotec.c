#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//função para calcular fatorial
int fatorial(int numero){
   if(numero > 1){
    return numero * fatorial(numero - 1);
  }else{
    return 1;
  }
}

int main(void){
  char *mensagem, *tmp, aux;
  int i, j, cadeia, k, tam, vetor[100], resp, count=0,o=0, denominador=1, numerador, soma=0, soma_anterior;
  int **matrix;

  for ( i = 0; i < 100; i++) {
    vetor[i]=0;
  }
  //alocando o vetor temporario
  tmp = (char*)malloc(100000 * sizeof(char));

  //lendo a linha s
  scanf(" %s", tmp);

  //pegando o tamamho do vetor de entrada
  tam = strlen(tmp);

  //alocando o vetor do tamanho certo
  mensagem = (char*)malloc(tam * sizeof(char));

  //copiando o vetor
  for(k = 0 ;k < tam; k++){
    mensagem[k] = tmp[k];
  }

  //liberando o vetor temporario
  free(tmp);
  cadeia = 1;
  //aqui tem q ficar a soma das subcadeias
  for  (j = 1; j < tam; j++) {
    for(int x=1;x<tam;x++){
      soma_anterior = soma;
      soma = 0;
      for (i = 0; i < cadeia; i++) {
        soma = soma + (mensagem[x-1+i]-96);

      }

      printf("%d\n", soma);

    }
    cadeia++;
  }

  for(i=0;i<tam;i++){
    printf("(%d)\n",  vetor[i]);
  }
  printf("%d\n", count);


  free(mensagem);
}
