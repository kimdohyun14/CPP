// call-by-value
// call-by-reference
#include <cstdio>

// call-by-value
void swap(int x, int y) {
	int tmp = x;
	x = y;
	y = tmp;
}

// call-by-reference
// cpp¿¡¼­´Â int& x, int& y
void swap2(int* x, int* y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

int main() {
	int a, b;

	scanf("%d%d", &a, &b);

	swap(a, b);

	printf("a = %d, b = %d\n", a, b);

	swap2(&a, &b);

	printf("a = %d, b = %d\n", a, b);
	return 0;
}