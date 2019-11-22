#include <stdio.h>

int main() {
	int arr[3] = { 1, 2, 3 };
	int* ptr = arr;
	printf("%d %d %d \n", *ptr, *(ptr + 1), *(ptr + 2)); // 이러한 형태로 출력이 가능하다.

	// 포인터 변수 ptr은 int형 포인터이므로 값을 1씩 증가시키면,
	// 실제로는 4가 증가하게 된다. double인 경우에는 8이 증가.
	// 중요한 것은 arr[i] == *(arr + i) 인 것이다.
	printf("%d \n", *ptr); ptr++;
	printf("%d \n", *ptr); ptr++;
	printf("%d \n", *ptr); ptr--;
	printf("%d \n", *ptr); ptr--;
	printf("%d \n", *ptr); 
	return 0;
}

// 추가적으로 아래의 차이점은?
/*
	*(++ptr) = 20; // ptr에 저장된 값 자체를 변경하게 되고
	*(ptr+1) = 20; // ptr에 저장된 값은 변경되지 않게 된다.
*/