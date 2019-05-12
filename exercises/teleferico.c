#include "stdio.h"

int main(void) {
	int a,c,i=0;
	scanf("%d", &c);
	scanf("%d", &a);
	a++;
	while (a>0) {
		a = a - c;
		i++;
	}
	printf("%d\n", i);
	return 0;
}
