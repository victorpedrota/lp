#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main(int argc, char const *argv[]) {
  int x = 0,i;
  char c[100000];
  scanf("%s", c);
  for ( i = 0; i < strlen(c); i++) {
    x+= (c[i]);
  }
  printf("%d\n", x%3);

}
