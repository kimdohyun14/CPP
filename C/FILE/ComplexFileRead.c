#include <stdio.h>

// 텍스트 데이터 + 바이너리 데이터로 되어있는 파일을 읽어들여서 출력한다.

int main() {
	char name[10];
	char sex;
	int age;

	FILE* fp = fopen("friend.txt", "rt");
	int ret;

	while (1) {
		// fscanf함수는 파일의 끝에 도달하거나 오류가 발생하면 EOF를 반환한다.
		ret = fscanf(fp, "%s %c %d", name, &sex, &age);
		if (ret == EOF)
			break;
		printf("%s %c %d \n", name, sex, age);
	}
	fclose(fp);
	return 0;
}