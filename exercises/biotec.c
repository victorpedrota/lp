#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  Algoritimo certo, porem precisa de otimizaço
  possivel otimização em alocar o vetor vetor
  ou mudar a logica para nao calucar todas as somas
*/
int verificar_igual(int *vetor, int pos){
  int i,j,x;
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
  return pos;
}

int main(void){
  char *mensagem, *tmp, aux;
  int i, j, x, cadeia=1, tam, *vetor, soma=0, pos=1, teste;


  //alocando o vetor temporario
  tmp = (char*)malloc(1000000 * sizeof(char));

  //devo ter deito bosta aqui
  if (!(vetor = (int *)malloc(10000000 * sizeof(int)))) {
		printf("Não foi possível alocar o vetor\n");
		exit(0);
	}

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
  for(cadeia = 1; cadeia <= tam; cadeia++){
    for(j = 0;j <= tam-cadeia; j++){
      soma = 0;
        for (x = 0; x < cadeia; x++) {
            soma += (mensagem[j+x]-96);

        }
        vetor[pos] = soma;
        teste = verificar_igual(vetor, pos);
        pos++;

    }

  }

  //retorna o numero de somas somas diferentes


  //imprimindo o resultado
  printf("%d\n", teste);

  //liberando o vetor
  free(mensagem);
}
