#include <stdio.h>

int main(void) {
	int h, w, n;
	int x, y;
	int a;
	scanf("%d", &a);

	while (a--) {
		scanf("%d %d %d", &h, &w, &n);

		x = (n / h) + 1;
		y = (n % h);

		if (y == 0) {
			x -= 1;
			y = h;
		}

		if (x < 10) {
			printf("%d0%d\n", y, x);
		}
		else {
			printf("%d%d\n", y, x);
		}
	}
}