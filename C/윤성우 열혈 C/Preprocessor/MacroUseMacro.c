#include <stdio.h>
#define PI 3.14
#define PRODUCT(X, Y) ((X)*(Y))
#define CIRCLE_AREA(R) (PRODUCT((R), (R)) * PI) // ��ũ�� ������ ��, ���� ���ǵ� ��ũ�δ� ����� �����ϴ�.

int main() {
	double rad = 2.1;
	printf("������ %g�� ���� ����: %g \n", rad, CIRCLE_AREA(rad));
	return 0;
}