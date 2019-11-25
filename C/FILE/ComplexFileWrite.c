#include <stdio.h>

// 텍스트 데이터 + 바이너리 데이터 => 하나의 문자열로 만들어서 파일에 저장한다.

int main() {
	char name[10];
	char sex;
	int age;

	FILE* fp = fopen("friend.txt", "wt");
	int i;

	if (fp == NULL) {
		puts("파일오픈 실패");
		return -1;
	}

	puts("파일오픈 성공!");
	for (i = 0; i < 3; i++) {
		printf("이름 성별 나이 순 입력: ");
		scanf("%s %c %d", name, &sex, &age); // scanf함수는 엔터 키의 입력을 읽어 들이지 않고 입력버퍼에 남겨두므로
		getchar(); // 버퍼에 남아있는 \n을 소멸하기 위해서 getchar 함수를 호출한다.
		fprintf(fp, "%s %c %d", name, sex, age);
	}
	fclose(fp);
	return 0;
}