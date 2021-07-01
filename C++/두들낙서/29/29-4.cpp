/*
입력 예
3 4
4 2 6 3
7 9 3 4
5 1 2 1

출력 예
15
23
9
*/

#include <cstdio>

int main() {
	int arr[15][15];
	int r, c;
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++) {
		int sum = 0;
		for (int j = 0; j < c; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < r; i++) {
		int sum = 0;
		for (int j = 0; j < c; j++) {
			sum += arr[i][j];
		}
		printf("%d\n", sum);
	}
}