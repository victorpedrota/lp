#include "stdio.h"
int main(int argc, char const *argv[]) {

  char a,b;
  scanf("%c %c", &a , &b);
  printf("+-----+\n");
  for (int i = 0; i < 5; i++) {
    printf("|");
    for (int j = 0; j < 5; j++) {
      if((j+i)%2 == 0){
        printf("%c", a);
      }
      else{
          printf("%c", b);
      }
    }
    printf("|\n");
  }
  printf("+-----+");
  return 0;
}
