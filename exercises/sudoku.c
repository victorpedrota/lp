#include <stdio.h>

int verifica(int linha, int coluna, int matriz[9][9]){
    int i,j,numero = matriz[linha][coluna];

    for (j = 0; j < 9; j++) {
      if(matriz[linha][j] == numero && j!= coluna ){
        return 0;
      }
    }

    for (i = 0; i < 9; i++) {
      if(matriz[i][coluna] == numero && i!= linha){
        return 0;
      }
    }

    return 1;
}

int main(){

  int i,j,numero,linha[9][9], n_linha,x;
  int cont = 0;

  for (i = 0; i < 9; i++) {
    for(j = 0; j < 9; j++){
        scanf("%d", &linha[i][j]);
    }
  }
  /*
  for (i = 0; i < 9; i++) {
    for(j = 0; j < 9; j++){
        printf("%d", linha[i][j]);
    }
    printf("\n" );
  }
  */
  for (i = 0; i < 9; i++) {
    for(j = 0; j < 9; j++){
      if(!verifica(i,j, linha)){
        printf("0\n");
        return 0;
      }
    }
  }

  printf("1\n");
  return 0;
}
