#include <stdio.h>

// 문자열 단위로 복사를 진행

int main() {
	FILE* src = fopen("src.txt", "rt");
	FILE* des = fopen("des.txt", "wt");
	char str[20];

	if (src == NULL || des == NULL) {
		puts("파일오픈 실패");
		return -1;
	}

	// fgets 함수는 파일의 끝에 도달해서 더 이상 읽을 데이터가 존재하지 않거나
	// 오류가 발생하는 경우에 NULL을 반환한다.
	while (fgets(str, sizeof(str), src) != NULL)
		fputs(str, des);


	// 마찬가지로 파일복사의 성공을 확인하기 위해서 feof함수를 호출한다.
	if (feof(src) != 0)
		puts("파일복사 완료");
	else
		puts("파일복사 실패");

	fclose(src);
	fclose(des);
	return 0;
}