#include <stdio.h>

typedef struct sbox { // 구조체 sbox 정의
	int mem1;
	int mem2;
	double mem3;
}SBox;

typedef union ubox { // 공용체 ubox 정의
	int mem1;
	int mem2;
	double mem3;
}UBox;

int main() {
	SBox sbx;
	UBox ubx;
	printf("%p %p %p \n", &sbx.mem1, &sbx.mem2, &sbx.mem3); // struct형은 멤버 각각 다 할당되어서 주소 값이 서로 다르나
	printf("%p %p %p \n", &ubx.mem1, &ubx.mem2, &ubx.mem3); // union형은 변수를 구성하는 멤버의 주소 값이 동일하다.
	printf("%d %d \n", sizeof(SBox), sizeof(UBox)); 
	// 공용체를 구성하는 멤버는 각각 할당되지 않고, 그 중 크기가 큰 멤버의 변수만
	// 하나 할당되어 이를 공유하게 된다.
	return 0;
}