#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
  char *mensagem, *tmp, aux;
  int i, j, cadeia, k, tam, vetor[100], resp, count=0, soma=0, pos=0;
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
    for(int x=1;x<=tam;x++){
      soma = 0;
      if(x+cadeia-1<=tam){
        for (i = 0; i < cadeia; i++) {
            soma = soma + (mensagem[x-1+i]-96);
          }
        printf("%d\n", soma);
        vetor[pos] = soma;
        pos++;
      }
    }
    cadeia++;
  }
  /*
  for(i=0;i<pos;i++){
    printf("(%d)\n",  vetor[i]);
  }
  */
  for( i = 0; i < tam; i++ )
    {
        for( j = i + 1; j < tam; )
        {
            if( vetor[j] == vetor[i] )
            {
                for( k = j; k < tam; k++ )
                    vetor[k] = vetor[k + 1];

                tam--;
            }
            else
            {
                j++;
            }
        }
    }

  printf("%d\n",  strlen(vetor));


  free(mensagem);
}
