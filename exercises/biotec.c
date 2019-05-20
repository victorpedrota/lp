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
  int i, j, possibilidades=1, k, tam, vetor[100], resp, count=0, denominador=1, numerador, soma;
  
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

  //ordenando vetor
  for (i = 0; i < tam; i++){
    for (j = i + 1; j < tam; j++){
      if (mensagem[i] < mensagem[j]){
        aux =  mensagem[i];
        mensagem[i] = mensagem[j];
        mensagem[j] = aux;
      }
    }
  }

  //imprimindo pra teste
  for (i = 0; i < tam; i++) {
    printf("(%c)", mensagem[i] );
  }
  printf("\n");

  //vendo quais sao repetidos
  for (i = 0; i < tam; i++) {
    resp=1;
    while(mensagem[i]==mensagem[i+1]) {
      resp++;
      i++;
    }
    count++;
    vetor[count] = resp;
    printf("(%d)", resp);
    printf("-%d-\n",count );
  }

  //teste
  for (i = 1; i <= count; i++) {
    denominador = denominador * fatorial(vetor[i]);
  }
  numerador = fatorial(tam);
  possibilidades = numerador/denominador;

  printf("%d\n", possibilidades);

  //fazendo a soma
  soma =0;
  for(k=0; k < tam;k++){
    soma = soma + (mensagem[k]-96);
  }
  printf("/%d/\n", soma);

  free(mensagem);
}
