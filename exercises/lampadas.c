#include <stdio.h>
#include <stdlib.h>

//Este codigo é o codigo mais porco q ja fiz
//função pra alocação dinamica matriz
int **alocar_matriz (int m, int n){
    int **v;
    int i;
    if (m < 1 || n < 1) {
      printf ("** Erro: Parametro invalido **\n");
      return (NULL);
  }

  v = (int **) calloc (m+1, sizeof(int *));
  if (v == NULL) {
    printf ("** Erro: Memoria Insuficiente **");
    return (NULL);
  }

  for ( i = 0; i <= m; i++ ) {
    v[i] = (int*) calloc (n+1, sizeof(int));
    if (v[i] == NULL) {
      printf ("** Erro: Memoria Insuficiente **");
      return (NULL);
    }
  }
  return (v);
}
//função para liberar a matrix
int **liberar_matriz (int m, int n, int **v){
  int i;
  if (v == NULL) return (NULL);
  if (m < 1 || n < 1) {
    printf ("** Erro: Parametro invalido **\n");
    return (v);
  }
  for (i=0; i<=m; i++) free (v[i]);
    free (v);
    return (NULL);
  }

int main() {

	int *vetor, **matrix;
  int i, j, a, num_acesas, num_lampadas, num_interrutores, num_lamp_inte, c=0, b, h=0;

  //valores de entrada
  scanf("%d %d", &num_interrutores, &num_lampadas);

  //alocando o vetor
	if (!(vetor = (int *)malloc(num_lampadas * sizeof(int)))) {
		printf("Não foi possível alocar o vetor\n");
		exit(0);
	}

  //alocando a matrix caso numeros sejam mt grandes
  matrix = alocar_matriz(num_interrutores,(num_lampadas+1));

  //recebendo numero lampadas acesas
  scanf("%d", &num_acesas);

  //vendo quais lampadas estao acesas
  for (i = 0; i < num_acesas; i++){
    scanf("%d", &a);
    vetor[a-1] = 1;
  }

  //mudando o estado das lampadas para acesas
  for (i = 0; i < num_interrutores; i++) {
    scanf("%d", &num_lamp_inte);
    matrix[i][0] = num_lamp_inte;

    for (j = 0; j < num_lamp_inte; j++) {
      scanf("%d", &matrix[i][j+1]);
    }
  }

  //vendo relacao interrutor/lampada e mudando estado da lampada
  while(h<50){
    for (i = 0; i < num_interrutores; i++) {
      b=0;
      for(a = 0; a < num_lampadas; a++){
       if (vetor[a] == 1) {
         b++;
        }
      }
      if(b>0){
        c++;
        for (j = 1; j <= matrix[i][0]; j++) {
          if(vetor[matrix[i][j]-1]==1){
            vetor[matrix[i][j]-1] = 0;
          }
          else{
            vetor[matrix[i][j]-1] = 1;
          }
        }
      }
    }
    h++;
  }

  //conferindo os casos e imprimindo as respostas
  if (b==0 && c>0) {
    printf("%d", c);
  }
  else if( b ==0 && c==0){
    printf("1");
  }
  else{
    printf("-1");
  }

  //liberando os vetores apos o uso
	free(vetor);
  matrix = liberar_matriz(num_interrutores,(num_lampadas+1), matrix);
}
