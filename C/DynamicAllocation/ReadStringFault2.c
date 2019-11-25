#include <stdio.h>
char name[30]; // 전역변수를 이용한다면?

char* ReadUserName() {
	printf("What's your name? ");
	gets(name);
	return name;
}

int main() {
	char* name1;
	char* name2;
	name1 = ReadUserName();
	printf("name1: %s \n", name1);
	name2 = ReadUserName();
	printf("name2: %s \n\n", name2);

	printf("name1: %s \n", name1); // 문제점 : name1이 name2로 덮어씌게 된다.
	printf("name2: %s \n", name2);
	return 0;
}