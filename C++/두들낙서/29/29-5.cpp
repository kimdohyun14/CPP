#include <cstdio>

int main() {
	int arr[3][3] = { 0 };

	printf("%d\n", &arr);    // 林家
	printf("%d\n", arr);     // 林家
	printf("%d\n", *arr);    // 林家

	printf("%d\n", &arr[0]); // 林家
	printf("%d\n", arr[0]);  // 林家
	printf("%d\n", *arr[0]); // 0

	printf("%d\n", &arr[0][0]); // 林家
	printf("%d\n", arr[0][0]); // 0
}