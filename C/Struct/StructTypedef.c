#include <stdio.h>

// case 1
struct point {
	int xpos;
	int ypos;
};

typedef struct point Point; // �� �� �����ϰ� ����� �����ϴ�.

// case 2
typedef struct person {
	char name[20];
	char phoneNum[20];
	int age;
}Person;

int main() {
	Point pos = { 10,20 };
	Person man = { "�赵��", "123-4567-8910", 25 };
	printf("%d, %d \n", pos.xpos, pos.ypos);
	printf("%s, %s, %d \n", man.name, man.phoneNum, man.age);
	return 0;
}