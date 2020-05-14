#include <stdio.h>
#include <stdlib.h>

// malloc 함수와 free함수를 이용하면 메모리 공간의 할당과 소멸의 시점을 프로그래머가 직접 결정할 수 있다.
char* ReadUserName() {
	char* name = (char*)malloc(sizeof(char) * 30);
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

	printf("name1: %s \n", name1);
	printf("name2: %s \n", name2);

	free(name1);
	free(name2);
	return 0;
}