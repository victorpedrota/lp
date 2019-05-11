#include <stdio.h>
#include <stdlib.h>
//ei pau no cu, se for copia troca as variaveis
int main(void){
   int vetor[3];
   int i, caso[3], x=0;

   for (i = 0; i < 3; i++){
      scanf("%d", &vetor[i]);
   }

   caso[0] = vetor[1]*2+vetor[2]*4;
   caso[1] = vetor[0]*2+vetor[2]*2;
   caso[2] = vetor[1]*2+vetor[0]*4;
   i = 0;
   x = caso[0];

   while (i < 3){
       if (caso[i] <= x){
          x = caso[i];
       }
       i++;
   }
   printf("%d\n",x);
   return 0;
}
