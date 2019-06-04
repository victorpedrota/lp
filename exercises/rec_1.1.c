#include "stdio.h"
int main(int argc, char const *argv[]) {
  int i,j;
  char a,b;
  scanf("%c %c", &a , &b);
  printf("+-----+\n");
  for ( i = 0; i < 5; i++) {
    printf("|");
    for ( j = 0; j < 5; j++) {
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
