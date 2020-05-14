#include <stdio.h>

char* ReadUserName() {
	char name[30];
	printf("What's your name? ");
	gets(name);
	return name; // 문제점 : 문자열이 저장되어있는 배열이 함수를 빠져나가면서 소멸한다는 점
}

int main() {
	char* name1;
	char* name2;
	name1 = ReadUserName();
	printf("name1: %s \n", name1);
	name2 = ReadUserName();
	printf("name2: %s \n", name2);
	return 0;
}