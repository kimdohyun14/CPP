#include <stdio.h>

typedef struct sbox { // ����ü sbox ����
	int mem1;
	int mem2;
	double mem3;
}SBox;

typedef union ubox { // ����ü ubox ����
	int mem1;
	int mem2;
	double mem3;
}UBox;

int main() {
	SBox sbx;
	UBox ubx;
	printf("%p %p %p \n", &sbx.mem1, &sbx.mem2, &sbx.mem3); // struct���� ��� ���� �� �Ҵ�Ǿ �ּ� ���� ���� �ٸ���
	printf("%p %p %p \n", &ubx.mem1, &ubx.mem2, &ubx.mem3); // union���� ������ �����ϴ� ����� �ּ� ���� �����ϴ�.
	printf("%d %d \n", sizeof(SBox), sizeof(UBox)); 
	// ����ü�� �����ϴ� ����� ���� �Ҵ���� �ʰ�, �� �� ũ�Ⱑ ū ����� ������
	// �ϳ� �Ҵ�Ǿ� �̸� �����ϰ� �ȴ�.
	return 0;
}