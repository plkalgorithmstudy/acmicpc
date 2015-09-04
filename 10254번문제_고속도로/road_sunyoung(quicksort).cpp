#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct sort{
	int x;
	int y;
	double value;
}SORT;

int compareVAL( const void *arg1 , const void * arg2){
        double v1 , v2;
        v1 = ((SORT *)arg1)->value;
        v2 = ((SORT *)arg2)->value;

        if(v1 > v2) return -1;
        else if(v1 == v2) return 0;
        else return 1;
}
 
int main(void){
	
	int T, i, j, k, n, sNumber, sIndex;
	int **cityNumber;
	SORT *s;
	
	scanf("%d", &T);
	
	for(i = 0; i < T; i++){
		
		scanf("%d", &n);
		cityNumber = (int**)malloc(sizeof(int*)*n);	
		
		for(j = 0; j < n; j++)
			cityNumber[j] = (int*)malloc(sizeof(int*)*2);								

		for(j = 0; j < n; j++)
			scanf("%d %d", &cityNumber[j][0], &cityNumber[j][1]);
		
		sIndex = 0;
		sNumber = (n-1)*(n)/2;
		s = (SORT *)malloc(sizeof(SORT)*sNumber);		
		for(j = 0; j < n; j++){
			for(k = j + 1; k < n; k++){
				s[sIndex].x = j;
				s[sIndex].y = k;
				s[sIndex].value = sqrt(pow((double)(cityNumber[j][0] - cityNumber[k][0]), 2.0) + pow((double)(cityNumber[j][1] - cityNumber[k][1]), 2.0));
				sIndex++;
			}
		}
		
		qsort( s , sNumber , sizeof(SORT) , compareVAL);
		
		printf("%d %d %d %d\n", cityNumber[s[0].x][0], cityNumber[s[0].x][1], cityNumber[s[0].y][0], cityNumber[s[0].y][1]);
		
		for(j = 0; j < n; j++) 
	        free(cityNumber[j]); 
	    
	    free(cityNumber); 
	}	
}

