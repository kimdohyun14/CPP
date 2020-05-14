#include <stdio.h>

// ftell 함수는 파일 위치 지시자의 정보를 임시로 저장할 때 유용하다.

int main() {
	long fpos;
	int i;

	/* 파일생성 */
	FILE* fp = fopen("text.txt", "wt");
	fputs("1234-", fp);
	fclose(fp);

	/* 파일개방 */
	fp = fopen("text.txt", "rt");

	for (i = 0; i < 4; i++) {
		putchar(fgetc(fp));
		fpos = ftell(fp); // 현재 파일 위치 지시자의 위치를 알 수 있다.
		fseek(fp, -1, SEEK_END);
		putchar(fgetc(fp));
		fseek(fp, fpos, SEEK_SET);
	}
	fclose(fp);
	return 0;
}