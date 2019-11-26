#include <stdio.h>
#define PI 3.14
#define PRODUCT(X, Y) ((X)*(Y))
#define CIRCLE_AREA(R) (PRODUCT((R), (R)) * PI) // 매크로 정의할 때, 먼저 정의된 매크로는 사용이 가능하다.

int main() {
	double rad = 2.1;
	printf("반지름 %g인 원의 넓이: %g \n", rad, CIRCLE_AREA(rad));
	return 0;
}