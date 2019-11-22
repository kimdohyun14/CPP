#include <stdio.h>

int main() {
	int num = 100;
	int* ptr = &num; 
	int** dptr = &ptr; // 이중 포인터
	int*** tptr = &dptr; // 삼중 포인터 (이중 포인터 변수의 주소 값을 저장)

	printf("%d %d \n", **dptr, ***tptr);
	return 0;
}