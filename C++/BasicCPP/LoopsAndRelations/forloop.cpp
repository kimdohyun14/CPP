#include <iostream>
using namespace std;

int main()
{
	cout << "ī��Ʈ �ٿ� ����!: ";
	int limit;
	cin >> limit;
	int i;
	// for ������ �� �κ�
	// 1. ���� �˻翡 ����� ī���� ���� �ʱ�ȭ => �ʱ�ȭ(initialzation)
	// 2. ������ ������ ������ ������ �˻� => ���� �˻�(test)
	// 3. ���� ��ü�� ���� => ���� ��ü�� ���� �˻簡 ���� ���� �����ϰ� �ȴ�.
	// 4. ī���� ���� ���� => ����(Update)
	for (i = limit; i; i--)
	{
		cout << "i = " << i << endl;
	}
	cout << "i = " << i << "�̹Ƿ� ������ ����\n";
	return 0;
}