#include <stdio.h>

// �Է� ���۸� ����� �ϴ� ����

int main() {
	char perID[7]; // �� 7�ڸ��� ���� (�� ���� ���)
	char name[10];

	fputs("�ֹι�ȣ �� 6�ڸ� �Է�: ", stdout);
	fgets(perID, sizeof(perID), stdin); // 950208 + NULL���� + ���� Ű(\n) => �� 7���� �Է�

	// �Է� ���ۿ��� \n(���� Ű)�� �����ְ� �ȴ�.
	// �׷��� fgets�� \n�� ���� �������� �а� �ǹǷ� �Ʒ��� �׳� \n�� �б�� �Ǵ� �������̴�.
	// ��, �Է� ���۸� ������ ���� �۵��ϰ� �ȴ�.

	fputs("�̸� �Է�: ", stdout);
	fgets(name, sizeof(name), stdin);

	printf("�ֹι�ȣ: %s \n", perID);
	printf("�̸�: %s \n", name);
	return 0;
}