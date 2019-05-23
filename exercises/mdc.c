#include "stdio.h"

int main(int argc, char const *argv[]) {
  int num1,num2,resto=0;

  scanf("%d", &num1);
  scanf("%d", &num2);

  while (num2 != 0)
  {
      printf("(%d) -%d- /%d/\n", resto, num1, num2);
      resto = num1 % num2;
      num1 = num2;
      num2 = resto;

  }
  printf("%d\n", num1);
  return 0;
}
