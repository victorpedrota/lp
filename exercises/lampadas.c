#include <stdio.h>
#include <stdlib.h>
//Este codigo é o codigo mais porco q ja fiz
  int **Alocar_matriz_real (int m, int n){
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

int **Liberar_matriz_real (int m, int n, int **v){
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
  int aux, a, num_acesas, num_lampadas,i, num_interrutores, num_lamp_inte,j,c=0,b,h=0;;
  scanf("%d %d", &num_interrutores, &num_lampadas);

	if (!(vetor = (int *)malloc(num_lampadas * sizeof(int)))) {
		printf("Não foi possível alocar o vetor\n");
		exit(0);
	}

  matrix = Alocar_matriz_real(num_interrutores,(num_lampadas+1));

  scanf("%d", &num_acesas);
  for (i = 0; i < num_acesas; i++){
    scanf("%d", &a);
    vetor[a-1] = 1;
  }

  for (i = 0; i < num_interrutores; i++) {
    scanf("%d", &num_lamp_inte);
    matrix[i][0] = num_lamp_inte;

    for (j = 0; j < num_lamp_inte; j++) {
      scanf("%d", &matrix[i][j+1]);
    }
  }
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

  if (b==0 && c>0) {
    printf("%d", c);
  }
  else if( b ==0 && c==0){
    printf("1");
  }
  else{
    printf("-1");
  }

	free(vetor);
  matrix = Liberar_matriz_real(num_interrutores,(num_lampadas+1), matrix);
}
