#include <stdio.h>

struct point {
	int xpos;
	int ypos;
};

int main() {
	struct point pos1 = { 1,2 };
	struct point pos2 = { 100,200 };
	struct point* pptr = &pos1; // ����ü ���� pos1�� �ּ� �� ����

	(*pptr).xpos += 4; // pptr->xpos�� �ǹ̰� �����ϴ�.
	(*pptr).ypos += 5;
	printf("(%d, %d) \n", pptr->xpos, pptr->ypos);

	pptr = &pos2; // ����Ű�� ����� pos2�� ����
	pptr->xpos += 1; // (*pptr).xpos�� �ǹ̰� �����ϴ�.
	pptr->ypos += 2; // pptr�� ����Ű�� ������ ��� ypos�� ���� 2�����ϴ� �ǹ�
	printf("(%d, %d) \n", pptr->xpos, pptr->ypos);
	return 0;
}