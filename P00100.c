#include<stdio.h>

int getCycleLength(int n);

int main() {
	
	int a;
	int b;
	
	while(scanf("%d%d", &a, &b) != EOF) {
		
		printf("%d ", a);
		printf("%d ", b);
		
		int aux;
		if(a > b) {
			aux = a;
			a = b;
			b = aux;
		}
		
		int maxCycleLength = 1;
		int i;
		int newCycleLength;
		
		for(i = a; i <=b; i++) {
			newCycleLength = getCycleLength(i);
			if( newCycleLength > maxCycleLength) {
				maxCycleLength = newCycleLength;
			}	
		}

		printf("%d\n", maxCycleLength);	
	}
	return 0;
}

int getCycleLength(int n) {
	
	int cyclelength = 1;
	
	while(n > 1) {
		if(n % 2 != 0) {
			n = ( 3 * n ) + 1;
		} else {
			n = n / 2;
		}
		cyclelength++;
	}
	
	return cyclelength;
}
