#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 입력받은 문자열을 역으로 출력하기.
// I am a boy -> boy a am I

int main() {
	int maxlen, len, i;
	char* str;

	printf("문자열의 최대길이 정보 입력 : ");
	scanf("%d", &maxlen); // scanf함수는 \n을 입력버퍼에 남기므로
	getchar(); // \n 문자의 삭제 (중요)

	str = (char*)malloc(sizeof(char) * (maxlen + 1));
	printf("문자열을 입력하세요 : ");
	fgets(str, maxlen + 1, stdin); // -> 문자열 + \n + NULL문자 형태로 입력받는다.
	str[strlen(str) - 1] = 0; // \n 문자의 삭제하고 문자열의 끝을 의미하는 널문자로 대체한다.
	len = strlen(str);

	for (i = len; i > 0; i--) {
		if (str[i] == ' ') { // 공백을 만나게 되면
			printf("%s ", &str[i + 1]); // 공백의 앞에서 부터 단어를 읽어들이고
			str[i] = 0; // 읽어들이고 난 후 이 부분을 널 문자로 교체해서 이미 출력된 단어는 제외하도록 한다.
		}
	}
	printf("%s", &str[0]);
	free(str);
	return 0;
}