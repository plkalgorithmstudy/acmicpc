#include <stdio.h>

int main(void){

	int n, m, T, i, j;
	double sum = 1.0, divider = 1.0;
	
	scanf("%d", &T);
	
	for(i = 0; i < T; i++){
		
		scanf("%d %d", &n, &m);

		//m! / (m-n)!
		for(j = m; j > m - n; j--){
			sum = sum * j; 
		}
		
		//n!
		for(j = n; j > 0 ; j--){
			divider = divider * j;
		}		
		
		printf("%.0f\n", sum/divider);
		sum = 1.0;
		divider = 1.0;
	}	
}


