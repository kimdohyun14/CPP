#include <stdio.h>

typedef enum syllable { // typedef 선언이 추가된 열거형의 정의
	Do = 1, Re = 2, Mi = 3, Fa = 4, So = 5, La = 6, Ti = 7 // 열거형 상수들을 의미
}Syllable;

void Sound(Syllable sy) {

	// 열거형의 유용함은 둘 이상의 연관이 있는 이름을 상수로 선언함으로써
	// 프로그램의 가독성을 높이는데 있다.
	switch (sy) {
	case Do:
		puts("도는 하얀 도라지"); return;
	case Re:
		puts("레는 둥근 레코드"); return;
	case Mi:
		puts("미는 파란 미나리"); return;
	case Fa:
		puts("파는 예쁜 파랑새"); return;
	case So:
		puts("솔은 작은 솔방울"); return;
	case La:
		puts("라는 라디오고요~"); return;
	case Ti:
		puts("시는 졸졸 시냇물"); return;
	}
	puts("도레미파 솔라시도"); return;
}

int main() {
	Syllable tone;
	for (tone = Do; tone <= Ti; tone += 1)
		Sound(tone);
	return 0;
}