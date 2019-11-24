#include <stdio.h>
#include <string.h>

// 구조체의 멤버로 배열이 선언되면 배열의 접근방식을
// 포인터로 선언되면 포인터의 접근방식을 이용하면 된다.

struct person {
	char name[20];
	char phoneNum[20];
	int age;
};

int main() {
	struct person man1, man2;
	strcpy(man1.name, "김도현");
	strcpy(man1.phoneNum, "010-1234-5678");
	man1.age = 25;

	printf("이름 입력 : "); scanf("%s", man2.name);
	printf("전화번호 입력 : "); scanf("%s", man2.phoneNum);
	printf("나이 입력 : "); scanf("%d", &man2.age);

	printf("이름: %s \n", man1.name);
	printf("번호: %s \n", man1.phoneNum);
	printf("나이: %d \n", man1.age);

	printf("이름: %s \n", man2.name);
	printf("번호: %s \n", man2.phoneNum);
	printf("나이: %d \n", man2.age);
	return 0;
}