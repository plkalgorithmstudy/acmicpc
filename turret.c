#include <stdio.h>
#include <math.h>

int main() {
	
	int test_num, x1, y1, r1, x2, y2, r2;
	float sqrt_result;
	int sum;
	    
	scanf("%d", &test_num);
	
	for(int i = 0; i < test_num; i++){
		
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		
		if ( x1 == x2 && y1 == y2 && r1 == r2 ){
			// 작은 원이 큰 원 안에 있고, 반지름 길이도 같을 때 = 무한대			
			printf("-1\n");
			
		} else {
		
			// 두 점 사이의 거리
			sqrt_result = sqrt( (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) );
		
			// 반지름들의 합
			sum = r1 + r2;
			
			if ( sqrt_result > sum ) {
				// 작은 원과 큰 원이 서로 겹치치 않고, 서로의 반경 안에 포함되어 있지 않은 경우
				
				printf("0\n");
				
			} else if ( sqrt_result == sum ) {
				// 작은 원이 큰 원에 맞닿아 있는 경우
				
				printf("1\n");
				
			} else if ( sqrt_result < sum ) {
				
				if( ((sqrt_result + r2) < r1) || ((sqrt_result + r1) < r2) )
					printf("0\n");
				else if( ((sqrt_result + r2) == r1) || ((sqrt_result + r1) == r2) )
					printf("1\n");
				else
					printf("2\n");
				
			}
		}
	
	}
	
}