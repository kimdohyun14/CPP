#include <stdio.h>

// ����ü�� ������� �޸� ������ �����ϰ� �ִٴ� ���� �� �� �ִ�.

typedef union ubox {
	int mem1;
	int mem2;
	double mem3;
}UBox;

int main() {
	UBox ubx; // 8����Ʈ �޸� �Ҵ� (��� �� ���� ū ��� ������ �Ҵ�Ǿ ����)

	ubx.mem1 = 20; // ���� 4����Ʈ�� �޸� ������ 20�� ����
	printf("%d \n", ubx.mem2); // ���� 4����Ʈ�� �޸� ������ ����

	ubx.mem3 = 7.15; // 12�࿡ �����ߴ� ���� �����. (�����ϱ� ������)
	printf("%d \n", ubx.mem1);  // ���������� �Ǿ����� ���� 4����Ʈ�� �аԵǸ� �� �� ���� ���� ��µȴ�.
	printf("%d \n", ubx.mem2);
	printf("%g \n", ubx.mem3);
	return 0;
}