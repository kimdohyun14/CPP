#include <stdio.h>

struct point {
	int xpos;
	int ypos;
};

struct person {
	char name[20];
	char phoneNum[20];
	int age;
};

// 구조체 변수의 초기화는 선언과 동시에 초기화가 가능하다.
// 초기화 과정에서 문자열 저장을 위해서 strcpy함수를 호출하지 않아도 초기화가 된다는 점이다.
int main() {
	struct point pos = { 10,20 };
	struct person man = { "김도현", "010-1234-5678", 25 };
	printf("%d %d \n", pos.xpos, pos.ypos);
	printf("%s %s %d \n", man.name, man.phoneNum, man.age);
	return 0;
}