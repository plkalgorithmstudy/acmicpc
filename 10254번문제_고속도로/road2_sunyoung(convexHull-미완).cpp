#include <iostream>
#include <stack>
#include <stdlib.h>
#include <math.h>

using namespace std;

typedef struct point{
	int x;
	int y;
}Point;

typedef struct cal{
	int x;
	int y;
	double value;
}Cal;

Point p0;
int convexHullSize;
Point nextToTop(stack<Point> &S)
{
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}

int swap(Point &p1, Point &p2)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}
 
int dist(Point p1, Point p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}
 
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}
int compare(const void *vp1, const void *vp2)
{
   Point *p1 = (Point *)vp1;
   Point *p2 = (Point *)vp2;
 
   int o = orientation(p0, *p1, *p2);
   if (o == 0)
     return (dist(p0, *p2) >= dist(p0, *p1))? -1 : 1;
 
   return (o == 2)? -1: 1;
}
Point* convexHull(Point *points, int n){
   int ymin = points[0].y, min = 0;
   Point *result;
   for (int i = 1; i < n; i++)
   {
     int y = points[i].y;
 
     if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
        ymin = points[i].y, min = i;
   }
 
   swap(points[0], points[min]);
 
   p0 = points[0];
   qsort(&points[1], n-1, sizeof(Point), compare);
 
   stack<Point> S;
   S.push(points[0]);
   S.push(points[1]);
   S.push(points[2]);
 
   for (int i = 3; i < n; i++)
   {
      while (orientation(nextToTop(S), S.top(), points[i]) != 2)
         S.pop();
      S.push(points[i]);
   }
 
	result = (Point *)malloc(sizeof(Point)*S.size());	
	int index = 0;
   while (!S.empty())
   {
       Point p = S.top();
       result[index].x = p.x;
       result[index].y = p.y;
       S.pop();
   }
   convexHullSize = index;
   return result;
}

int main(void){
	
	int T, n, i, j, k;
	Point *points;
	
	Cal CURRENT, MAX;
	scanf("%d", &T);
	
	for(i = 0; i < T; i++){
		
		cin >> n;
//		scanf("%d", &n);
		
		points = (Point *)malloc(sizeof(Point)*n);
		
		for(j = 0; j < n; j++){
			cin >> points[j].x; 
			cin >> points[j].y;
//			scanf("%d %d", &points[j].x, &points[j].y);
		}
		
		Point* convexPoints;						
		convexPoints = convexHull(points, n);
		
		MAX.x = 0;
		MAX.y = 1;
		MAX.value = 0.0;
		
		for(j = 0; j < convexHullSize - 1; j++){
			for(k = j + 1; k < convexHullSize - 1; k++){
				CURRENT.x = j;
				CURRENT.y = k;
				CURRENT.value = sqrt(pow((double)(convexPoints[j].x - convexPoints[k].x), 2.0) + pow((double)(convexPoints[j].y - convexPoints[k].y), 2.0));
				
				if(MAX.value < CURRENT.value){
					MAX.x = CURRENT.x;
					MAX.y = CURRENT.y;
					MAX.value = CURRENT.value;
				}
			}
		}
		
		printf("%d %d %d %d\n", convexPoints[MAX.x].x, convexPoints[MAX.x].y, convexPoints[MAX.y].x, convexPoints[MAX.y].y);
							
	    free(points); 
	}	
	
	return 0;
}
	
