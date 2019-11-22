#include <stdio.h>

// 입력 버퍼를 비워야 하는 이유

int main() {
	char perID[7]; // 총 7자리를 만듬 (널 문자 고려)
	char name[10];

	fputs("주민번호 앞 6자리 입력: ", stdout);
	fgets(perID, sizeof(perID), stdin); // 950208 + NULL문자 + 엔터 키(\n) => 총 7문자 입력

	// 입력 버퍼에는 \n(엔터 키)가 남아있게 된다.
	// 그런데 fgets는 \n을 만날 때까지만 읽게 되므로 아래가 그냥 \n로 읽기게 되는 문제점이다.
	// 즉, 입력 버퍼를 지워야 정상 작동하게 된다.

	fputs("이름 입력: ", stdout);
	fgets(name, sizeof(name), stdin);

	printf("주민번호: %s \n", perID);
	printf("이름: %s \n", name);
	return 0;
}