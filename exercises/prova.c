#include "stdio.h"
int main(int argc, char const *argv[]) {
  int a = 0, b =1, qdivisores = 0, numerador, aux, j = 0, c = 2, num = 2;
  long denominador = 0;
  float soma;
  for (int i = 0; i < 50; i++) {
    denominador = a + b;
    b = a;
    a = denominador;
    while (j<=i) {
      for (aux = 1; aux <= c; aux++) {
        if(num%aux==0){
          qdivisores++;
        }
      }
      if(qdivisores <=2){
        j++;
      }
      c++;
      qdivisores = 0;
      numerador = num;
      num++;
    }
    printf("%d %d\n", numerador, denominador);
    soma += numerador/denominador;
  }
  printf("(%f)\n", soma);
  return 0;
}
