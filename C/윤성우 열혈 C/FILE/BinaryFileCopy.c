#include <stdio.h>

int main() {
	FILE* src = fopen("src.bin", "rb");
	FILE* des = fopen("des.bin", "wb");
	char buf[20];
	int readCnt;

	if (src == NULL || des == NULL) {
		puts("���Ͽ��� ����");
		return -1;
	}

	while (1) {
		// ���Ϸκ��� �����͸� �о���̴µ�, �� 1 * sizeof(buf)�� ������ ũ�⸦ �о���δ�.
		readCnt = fread((void*)buf, 1, sizeof(buf), src);
		
		if (readCnt < sizeof(buf)) { // Ȯ���ϰ� ��� ���� �о�鿴�ٸ� readCnt�� sizeof(buf)�� ũ�Ⱑ ������ �ƴ϶�� �۴�.
			if (feof(src) != 0) { // ������ ���� �����ߴ��� üũ���ְ�,
				fwrite((void*)buf, 1, readCnt, des); // ��� ���� ���� ����Ʈ�� �������� �� ���� ������ �Ϻ��̴� �����Ѵ�.
				puts("���Ϻ��� �Ϸ�");
				break;
			}
			else
				puts("���Ϻ��� ����");

			break;
		}
		fwrite((void*)buf, 1, sizeof(buf), des); // �о����, �迭 buf�� ����� �����͸� ���Ͽ� ����
	}

	fclose(src);
	fclose(des);
	return 0;
}

// �߰������� ���� ���α׷��� ���� ������ ���Ѵٰ� �Ѵ�.

// 1. Read / Write�� ���ÿ� �����ؾ� �ϸ�,
// 2. ������ ���� �����ߴ����� Ȯ���ؾ� �Ѵ�.