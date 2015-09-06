#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point{
	int x;
	int y;
}POINT;

typedef struct twoPointOneAngle{
	int p1Index;
	int p2Index;
	double angle;
}TPOA;

void swap(TPOA *A, TPOA *B){
	TPOA temp;
	temp = *A;
	*A = *B;
	*B = temp;
}
 
int direction(POINT *points, TPOA A, TPOA B, TPOA C){
	int dxAB, dxAC, dyAB, dyAC, Dir;
	
	dxAB = points[B.p2Index].x - points[A.p2Index].x;
	dyAB = points[B.p2Index].y - points[A.p2Index].y;
	dxAC = points[C.p2Index].x - points[A.p2Index].x;
	dyAC = points[C.p2Index].y - points[A.p2Index].x;
	
	if(dxAB * dyAC < dyAB * dxAC){
		Dir = 1;
	}
	if(dxAB * dyAC > dyAB * dxAC){
		Dir = -1;
	}	
	if(dxAB * dyAC == dyAB * dxAC){
		if(dxAB == 0 && dyAB == 0){
			Dir = 0;
		}
		if((dxAB * dxAC < 0)|| (dyAB * dyAC < 0)){
			Dir = -1;
		}else if((dxAB * dxAB + dyAB * dyAB >= dxAC * dxAC + dyAC * dyAC)){
			Dir = 0;
		}else{
			Dir = 1;
		}
	}
	return Dir;
}

int compareVAL( const void *arg1 , const void * arg2){
        double v1 , v2;
        v1 = ((TPOA *)arg1)->angle;
        v2 = ((TPOA *)arg2)->angle;

        if(v1 < v2) return -1;
        else if(v1 == v2) return 0;
        else return 1;
}

double computeAngle(POINT p1, POINT p2){
	
	int dx, dy, ax, ay;
	float t;
	
	dx = p2.x - p1.x;
	ax = abs(dx);
	
	dy = p2.y - p1.y;
	ay = abs(dy);
	
	t = (ax + ay == 0) ? 0 : (float) dy / (ax + ay);
	
	if(dx > 0){
		t = 2 - t;
	}else if(dy < 0){
		t = 4 + t;
	}
	
	return t * 90.0;
}

void convexHull(POINT *points, int size, TPOA *angleResults){
	int i, minIndex = 0;
	POINT minPoint = points[0];
	
	angleResults[i].p1Index = minIndex;
	angleResults[i].p2Index = minIndex;
	angleResults[i].angle = 0.0;
	
	for(int i = 1; i < size; i++){
		angleResults[i].p1Index = minIndex;
		angleResults[i].p2Index = i;
		angleResults[i].angle = computeAngle(points[minIndex], points[i]);
	}
}

int main(void){
	
	int T, n, i, j;
	POINT *points;
	TPOA *angleResults;
	
	TPOA CURRENT, MAX;
	
	scanf("%d", &T);
	
	for(i = 0; i < T; i++){
		
		scanf("%d", &n);
		
		points = (POINT *)malloc(sizeof(POINT)*n);
		angleResults = (TPOA *)malloc(sizeof(TPOA)*n);
		
		for(j = 0; j < n; j++){
			scanf("%d %d", &points[j].x, &points[j].y);
		}
				
		convexHull(points, n, angleResults);		
		qsort( angleResults , n , sizeof(TPOA) , compareVAL);
		
		
							
	    free(points); 
	    free(angleResults);
	}	
}





//		nextPoint = 3;
//		
//		for(j = 4; j < n; j++){
//			while(direction(points, angleResults[nextPoint-1], angleResults[nextPoint], angleResults[i]) >= 0){
//				nextPoint--;
//			}
//			nextPoint++;
//			
//			swap(&angleResults[nextPoint], &angleResults[i]);
//		}
//		
//		MAX.p1Index = 0;
//		MAX.p2Index = 1;
//		MAX.angle = 0.0;
//		
//		for(j = 0; j <= nextPoint; j++){
//			for(k = j + 1; k <= nextPoint; k++){
//				CURRENT.p1Index = angleResults[j].p2Index;
//				CURRENT.p2Index = angleResults[k].p2Index;
//				CURRENT.angle = sqrt(pow((double)(points[CURRENT.p1Index].x - points[CURRENT.p2Index].y), 2.0) + pow((double)(points[CURRENT.p1Index].y - points[CURRENT.p2Index].y), 2.0));
//				
//				if(MAX.angle < CURRENT.angle){
//					MAX.p1Index = CURRENT.p1Index;
//					MAX.p2Index = CURRENT.p2Index;
//					MAX.angle = CURRENT.angle;
//				}
//				
//			}
//		}
//		
//		printf("%d %d %d %d\n", points[MAX.p1Index].x, points[MAX.p1Index].y, points[MAX.p2Index].x, points[MAX.p2Index].y);	
	
