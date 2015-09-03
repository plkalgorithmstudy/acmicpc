#include <stdio.h>
#include <math.h>

int main(void){
	int num, x1, y1, r1, x2, y2, r2;
	float distance;
	int radiusSum;
	
	scanf("%d", &num);
	
	for(int i = 0; i < num; i++){
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		
		if(x1 == x2 && y1 == y2 && r1 == r2){
			printf("-1\n");
		}else{
			distance = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
			radiusSum = r1 + r2;
			if((radiusSum == distance) || ((r2 > r1) ? r2-r1 == distance : r1-r2 == distance)){
				printf("1\n");
			}else if(distance < radiusSum && ((r2>r1) ? r2-r1 < distance : r1-r2 < distance)){
				printf("2\n");
			}else{
				printf("0\n");
			}	
		}
	}
}
