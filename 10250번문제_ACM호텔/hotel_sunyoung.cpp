#include <stdio.h>

int main(void){
	int T, H, W, N, i;
	int step, room;
	int mok;
	int namuzi;
	
	scanf("%d", &T);
	
	for(i = 0; i < T; i++){
		scanf("%d %d %d", &H, &W, &N);
		
		if(N <= H){
			step = N;
			room = 1;
		}else{
			namuzi = N % H;
			mok = N / H;
			
			if(namuzi == 0){
				step = H;
				room = mok;
			}else{
				step = namuzi;
				room = mok + 1;	
			}
		}
		
		if(room < 10){
			printf("%d0%d\n", step, room);					
		}else{
			printf("%d%d\n", step, room);					
		}
	}
}
