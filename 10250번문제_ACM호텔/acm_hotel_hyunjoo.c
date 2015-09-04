#include <stdio.h>

int main(void) {
	
	int T,H,W,N, int1, int2, room, height;
	double double1 = 0.0;
	
	scanf("%d", &T);
	
	for(int i = 0; i < T; i++){
		scanf("%d %d %d", &H, &W, &N);
		
		double1 = (double)N/H;
		int1 = double1;
		
		if(double1 == int1)
			room = int1;
		else
			room = int1 + 1;
			
		int2 = N%H;
		
		if(int2 == 0)
			height = H;
		else
			height = int2;
		
		printf("%d\n", height*100 + room);
	}
	
}