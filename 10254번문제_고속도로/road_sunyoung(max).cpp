#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct sort{
	int x;
	int y;
	double value;
}SORT;

int main(void){
	
	int T, i, j, k, n, sNumber, sIndex;
	int **cityNumber;
	SORT CURRENT;
	SORT MAX;
	
	scanf("%d", &T);
	
	for(i = 0; i < T; i++){
		
		scanf("%d", &n);
		cityNumber = (int**)malloc(sizeof(int*)*n);	
		
		for(j = 0; j < n; j++)
			cityNumber[j] = (int*)malloc(sizeof(int*)*2);								

		for(j = 0; j < n; j++)
			scanf("%d %d", &cityNumber[j][0], &cityNumber[j][1]);
		
		MAX.x = 0;
		MAX.y = 1;
		MAX.value = 0.0;
		
		for(j = 0; j < n; j++){
			for(k = j + 1; k < n; k++){
				CURRENT.x = j;
				CURRENT.y = k;
				CURRENT.value = sqrt(pow((double)(cityNumber[j][0] - cityNumber[k][0]), 2.0) + pow((double)(cityNumber[j][1] - cityNumber[k][1]), 2.0));
				
				if(MAX.value < CURRENT.value){
					MAX.x = CURRENT.x;
					MAX.y = CURRENT.y;
					MAX.value = CURRENT.value;
				}
				
			}
		}
		
		printf("%d %d %d %d\n", cityNumber[MAX.x][0], cityNumber[MAX.x][1], cityNumber[MAX.y][0], cityNumber[MAX.y][1]);		
		
		for(j = 0; j < n; j++) 
	        free(cityNumber[j]); 
	    
	    free(cityNumber); 
	}	
}

