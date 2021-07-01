#include <cstdio>

int main() {
	int arr[3][3] = { 0 };

	printf("%d\n", &arr[0][0]);  // 1637856

	printf("%d\n", arr[0] + 1);  // 1637860
	printf("%d\n", &arr[0] + 1); // 1637868
	printf("%d\n", arr + 1);     // 1637868
	printf("%d\n", &arr + 1);    // 1637892
}