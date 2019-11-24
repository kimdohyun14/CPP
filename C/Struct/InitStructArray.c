#include <stdio.h>

struct person {
	char name[20];
	char phoneNum[20];
	int age;
};

// 구조체 배열 역시 중괄호 통해서 초기화가 가능하다.
int main() {
	struct person arr[3] = {
		{"바나나","010-1234-5678", 21},  // 첫 번째 요소 초기화
		{"초콜릿", "123-4567-8901", 22}, // 두 번째
		{"오렌지","134-587-3123", 23}    // 세 번째
	};

	int i;
	for (i = 0; i < 3; i++)
		printf("%s, %s, %d \n", arr[i].name, arr[i].phoneNum, arr[i].age);
	return 0;
}