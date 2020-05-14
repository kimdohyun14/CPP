#include <stdio.h>

// 배열의 이름을 대상으로 *연산이 가능하며,
// 배열의 이름은 배열의 첫 번째 요소를 가리킨다.

int main() {
	int arr1[3] = { 1,2,3 };
	double arr2[3] = { 1.1,2.2,3.3 };

	printf("%d %g \n", *arr1, *arr2);
	*arr1 += 100;
	*arr2 += 100.5;
	printf("%d %g \n", *arr1, *arr2);
	return 0;
}