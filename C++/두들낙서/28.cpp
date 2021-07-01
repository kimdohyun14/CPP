// 배열 포인터 : 배열을 가리키는 포인터 (포인터가 1개)
// 포인터 배열 : 포인터들이 배열이라는 뜻 (포인터가 여러개)

#include <cstdio>

int main() {
	int a = 10;
	int b = 20;
	int c = 30;
	int d = 40;
	int* ptr[4]; // {int*, int*, int*, int*}

	ptr[0] = &a;
	ptr[1] = &b;
	ptr[2] = &c;
	ptr[3] = &d;

	printf("%d %d %d %d\n", *ptr[0], *ptr[1], *ptr[2], *ptr[3]);

	int arr[4] = { 1,2,3,4 };
	for (int i = 0; i < 4; i++) {
		ptr[i] = &arr[i];
	}

	for (int i = 0; i < 4; i++) {
		printf("%d ", *ptr[i]);
	}
	printf("\n");

	char str[] = "Hello!"; // null(\0)문자까지 합쳐서 7개
	printf("%s\n\n", str);

	char strings[3][10] = { "Hello", "World", "Dohyun" };
	char* p_str[3];
	for (int i = 0; i < 3; i++) {
		p_str[i] = strings[i];
	}

	for (int i = 0; i < 3; i++) {
		printf("%s\n", strings[i]);
	}
	printf("\n");

	for (int i = 0; i < 3; i++) {
		printf("%s\n", p_str[i]);
	}
	printf("\n");
}