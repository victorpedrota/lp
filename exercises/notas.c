#include "stdio.h"

int main(int argc, char const *argv[]) {
  int *vetor , i, j, numero_participantes, vagas=0,count=0, aux=0,x=0;

  scanf("%d", &numero_participantes);
  scanf("%d", &vagas);

  vetor = malloc ((numero_participantes+1) * sizeof (int));
  for (i = 0; i <= numero_participantes; i++){
    vetor[i]=0;
  }

  //recebendo as notas
  for (i = 0; i < numero_participantes; i++){
    scanf("%d", &vetor[i]);
  }

  //colocando vetor em ordem para comparação
  for (i = 0; i < numero_participantes; i++){
    for (j = i + 1; j < numero_participantes; j++){
      if (vetor[i] < vetor[j]){
        aux =  vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = aux;
      }
    }
  }

  //fazendo a comparação
  for (i = 0; i < numero_participantes; i++) {
    if(count < vagas){
      count++;
    }
    if(count >= vagas && x<1){
      while(vetor[i]==vetor[i+1]){
        i++;
        count++;
        x++;
      }
    }
  }

  printf("%d", count);
  free (vetor);
  return 0;
}
