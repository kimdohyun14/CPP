#include <stdio.h>

typedef struct point {
	int xpos;
	int ypos;
}Point;

// �Լ��� ���ڷ� ����ü ������ ���޵� �� �ִ�.
// ���޵Ǵ� ����ü ������ ���� �Ű������� ��°�� ����ȴ�.
void ShowPosition(Point pos) {
	printf("(%d, %d) \n", pos.xpos, pos.ypos);
}

// ���������� ����ü�� ��ȯ�� �� �ִ�.
Point GetCurrentPosition() {
	Point cen;
	printf("Input current pos: ");
	scanf("%d %d", &cen.xpos, &cen.ypos);
	return cen;
}

int main() {
	Point curPos = GetCurrentPosition();
	ShowPosition(curPos);
	return 0;
}