#include <stdio.h>

char* ReadUserName() {
	char name[30];
	printf("What's your name? ");
	gets(name);
	return name; // ������ : ���ڿ��� ����Ǿ��ִ� �迭�� �Լ��� ���������鼭 �Ҹ��Ѵٴ� ��
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