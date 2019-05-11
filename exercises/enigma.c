/*
   atenção pau no cu, muda o nome das variaveis e o tamanho do vetor pra nao deixar na cara
*/
#include <stdio.h>
#include <string.h>

int main (void) {

   char msg_cripto[100000];
   char msg[100000];
   int tam_msg, a=0, tam_cripto, b=0, i, j;
   scanf(" %s", &msg_cripto );
   scanf(" %s", &msg );
   tam_cripto = strlen(msg_cripto);
   tam_msg = strlen(msg);

   for (j=0; j <= (tam_cripto-tam_msg); j++) {
     for (i=0; i < tam_msg; i++) {
       if (msg_cripto[i+j] == msg[i]) {
         a++;
        }
      }
      if (a<=0) {
        b++;
      }
      a=0;
   }

   printf("%d\n", b);
   return 0;

}
