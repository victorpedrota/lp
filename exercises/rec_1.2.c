#include "stdio.h"

int main(int argc, char const *argv[]) {
  int w, altura , peso, resistencia, potencia = 0, i, n_robos;
  scanf("%d", &n_robos);
  for (i = 0; i < n_robos; i++) {
    scanf("%d %d %d %d", &altura, &peso, &w, &resistencia);
    potencia +=  (peso-altura)*(w + resistencia);
  }
  printf("%d\n", potencia);

  return 0;
}
