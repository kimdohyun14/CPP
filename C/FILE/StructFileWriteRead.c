#include <stdio.h>

// 실제 프로그램은 구조체로 묶어서 정의하는 것이 보통
typedef struct fren {
	char name[10];
	char sex;
	int age;
}Friend;

// 구조체 변수를 하나의 바이너리 데이터로 인식하고 처리하면 가능하다.
int main() {
	FILE* fp;
	Friend myfren1;
	Friend myfren2;

	/*** file write ***/
	fp = fopen("friend.bin", "wb");
	printf("이름, 성별, 나이 순 입력: ");
	scanf("%s %c %d", myfren1.name, &(myfren1.sex), &(myfren1.age));
	fwrite((void*)&myfren1, sizeof(myfren1), 1, fp);
	fclose(fp);

	/*** file read ***/
	fp = fopen("friend.bin", "rb");
	fread((void*)&myfren2, sizeof(myfren2), 1, fp);
	printf("%s %c %d \n", myfren2.name, myfren2.sex, myfren2.age);
	fclose(fp);
	return 0;
}