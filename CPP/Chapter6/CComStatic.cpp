#include <iostream>
using namespace std;

void Counter() {
	static int cnt; //�� ������ �� �ѹ��� ����Ǹ�, �ʱ�ȭ�� ���� ������ ��������ó�� 0���� �ʱ�ȭ�ȴ�.
	cnt++;
	cout << "Current cnt: " << cnt << endl;
}

int main() {
	for (int i = 0; i < 10; i++)
		Counter();
	return 0;
}