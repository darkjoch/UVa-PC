#include<stdio.h>

#define ROW   5
#define COL   3

int number0[ROW][COL] = {
					{0,1,0},
					{1,0,1},
					{0,0,0},
					{1,0,1},
					{0,1,0}};
					
int number1[ROW][COL] = {
					{0,0,0},
					{0,0,1},
					{0,0,0},
					{0,0,1},
					{0,0,0}};
					
int number2[ROW][COL] = {
					{0,1,0},
					{0,0,1},
					{0,1,0},
					{1,0,0},
					{0,1,0}};
					
int number3[ROW][COL] = {
					{0,1,0},
					{0,0,1},
					{0,1,0},
					{0,0,1},
					{0,1,0}};
					
int number4[ROW][COL] = {
					{0,0,0},
					{1,0,1},
					{0,1,0},
					{0,0,1},
					{0,0,0}};
					
int number5[ROW][COL] = {
					{0,1,0},
					{1,0,0},
					{0,1,0},
					{0,0,1},
					{0,1,0}};
					
int number6[ROW][COL] = {
					{0,1,0},
					{1,0,0},
					{0,1,0},
					{1,0,1},
					{0,1,0}};

int number7[ROW][COL] = {
					{0,1,0},
					{0,0,1},
					{0,0,0},
					{0,0,1},
					{0,0,0}};

int number8[ROW][COL] = {
					{0,1,0},
					{1,0,1},
					{0,1,0},
					{1,0,1},
					{0,1,0}};

int number9[ROW][COL] = {
					{0,1,0},
					{1,0,1},
					{0,1,0},
					{0,0,1},
					{0,1,0}};

typedef int Array2D[ROW][COL];
					
int main() {
	
	int size;
	int numberToDisplay;
	
	while(scanf("%d%d", &size, &numberToDisplay) != EOF) {
		
		if(size == 0 && numberToDisplay == 0)
			return 0;
			
		int numberSize = 0;
		int digits[9];
		
		if(numberToDisplay == 0) {
			digits[0] = 0;
			numberSize = 1;
		} else {
			while(numberToDisplay >= 1) {		
				digits[numberSize] = numberToDisplay % 10;			
				numberToDisplay = numberToDisplay / 10;
				numberSize++;
			}
		}
				
		int x = (2 * size) + 3;
		int y = size + 2;
		int bufferSize = (y + 1) * numberSize;
		char buffer[x][bufferSize];
		int digitCounter = 0;
		
		int digitIndex;
		for(digitIndex=numberSize-1; digitIndex >= 0; digitIndex--) {
			int digitToDisplay = digits[digitIndex];
			Array2D *number = NULL;
			if(digitToDisplay == 0)
				number = &number0;
			if(digitToDisplay == 1)
				number = &number1;
			if(digitToDisplay == 2)
				number = &number2;
			if(digitToDisplay == 3)
				number = &number3;
			if(digitToDisplay == 4)
				number = &number4;
			if(digitToDisplay == 5)
				number = &number5;
			if(digitToDisplay == 6)
				number = &number6;
			if(digitToDisplay == 7)
				number = &number7;
			if(digitToDisplay == 8)
				number = &number8;
			if(digitToDisplay == 9)
				number = &number9;
			
			char resizedNumber[x][y];
			
			{
				int i;
				for(i=0; i < x; i++) {
					int j;
					for(j=0; j < y; j++) {
						resizedNumber[i][j] = ' ';
					}
				}
			}
			
			{
				int i;
				int h = 0;
				for(i = 0; i < ROW; i++) {
					if(i % 2 == 0) {
						int j;
						if((*number)[i][1] == 1) {
							int k;
							for(k = 1; k <= size; k++) {
								resizedNumber[h][k] = '-';
							}
						}
						h++;
					} else {			
						int k;
						for(k = 0; k < size; k++) {				
							if((*number)[i][0] != 0) {
								resizedNumber[h][0] = '|';
							}
							if((*number)[i][2] != 0 ) {
								resizedNumber[h][y-1] = '|';
							}
							h++;	
						}
						
					}	
				}
			}
				
			{
				int i;
				for(i=0; i < x; i++) {
					int j;
					for(j=0; j <= y; j++) {
						if(j==y){
							buffer[i][j+((y+1)*digitCounter)] = ' ';
						} else {
							buffer[i][j+((y+1)*digitCounter)] = resizedNumber[i][j];
						}
					}
				}
			}
			digitCounter++;
		}
		
		{
			int i;
			for(i=0; i < x; i++) {
				int j;
				for(j=0; j < bufferSize - 1; j++) {
					printf("%c", buffer[i][j]);
				}
				printf("\n");
			}
			printf("\n");
		}
		
	}
}

