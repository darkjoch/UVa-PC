#include <stdio.h>

int main() {
	
	int n, m;
	int fields = 0;
	
	while(scanf("%d%d", &n, &m) != EOF) {
		if(n == 0 && m == 0)
			break;
		
		if(fields > 0)	
			printf("\n");
			
		int field[n+2][m+2];
		
		int i;
		for(i = 0; i <= n +1; i++){
			int j;
			for(j = 0; j <= m+1; j++) {
				field[i][j] = 0;
			}
		}
		
		{
			int i;
			for(i = 0; i < n; i++){
				int j;
				for(j = 0; j < m; j++) {
					char fc;
					scanf(" %c", &fc);
					if(fc == '*') {
						field[i+1][j+1] = -1;
					}
				}
			}
		}
		
		{
			int i;
			for(i = 1; i <= n; i++){
				int j;
				for(j = 1; j <= m; j++) {
	
					int mines = 0;
					if(field[i][j] != -1) {
						
						int x;
						for(x = i - 1; x <= i + 1; x++) {
							
							int y;
							for(y = j - 1; y <= j + 1; y++) {
								if(field[x][y] == -1) {
									mines++;
								}
							}
						}
						field[i][j] = mines;
					}
				}
			}
		}
		
		{
			printf("Field #%d:\n", ++fields);
		
			int i;
			for(i = 1; i <= n; i++){
				int j;
				for(j = 1; j <= m ; j++) {
					if(field[i][j] == -1) {
							printf("*");
					} else {
						printf("%d", field[i][j]);
					}
				}
				printf("\n");			
			}
		}
	}
}

