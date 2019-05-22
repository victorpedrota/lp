#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  Algoritimo certo, porem precisa de otimizaço
  possivel otimização em alocar o vetor vetor
  ou mudar a logica para nao calucar todas as somas
*/

int main(void){
  char *mensagem, *tmp, aux;
  int i, j, x, cadeia=1, tam, *vetor, soma=0, pos=1;

  //alocando o vetor temporario
  tmp = (char*)malloc(100000 * sizeof(char));

  //devo ter deito bosta aqui
  vetor = (int*)malloc(1000000 * sizeof(int));

  //lendo a linha s
  scanf(" %s", tmp);

  //pegando o tamamho do vetor de entrada
  tam = strlen(tmp);

  //alocando o vetor do tamanho certo
  mensagem = (char*)malloc(tam * sizeof(char));

  //copiando o vetor
  for(i = 0 ;i < tam; i++){
    mensagem[i] = tmp[i];
  }

  //liberando o vetor temporario
  free(tmp);

  //aqui tem q ficar a soma das subcadeias
  for(i = 1; i < tam; i++){
    for(j = 1;j <= tam; j++){
      soma = 0;
      if(j+cadeia-1 <= tam){
        for (x = 0; x < cadeia; x++) {
            soma += (mensagem[j-1+x]-96);
        }
        vetor[pos] = soma;
        pos++;
      }
    }
    cadeia++;
  }

  //retorna o numero de somas somas diferentes
  for(i = 0; i < pos; i++){
    for(j = i + 1; j < pos;){
      if(vetor[j] == vetor[i]){
        for(x = j; x < pos; x++){
        vetor[x] = vetor[x + 1];
        }
        pos--;
      }
      else{
        j++;
      }
    }
  }

  //imprimindo o resultado
  printf("%d\n", pos);

  //liberando o vetor
  free(mensagem);
}
