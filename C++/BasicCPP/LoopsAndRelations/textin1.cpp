#include <iostream>
using namespace std;
int main()
{
	char ch;
	int count = 0;
	cout << "���ڵ��� �Է�, �������� #: ";
	cin >> ch;
	while (ch != '#')
	{
		cout << ch;
		++count;
		cin >> ch;
	}
	cout << endl << count << " ���ڸ� �о����ϴ�.\n\n";

	// �Է¿� �ִ� ��ĭ ���ڵ��� ���ڵ��� �ʴ´�!
	// cin�� ��ĭ ����, ���� ���ڵ��� �����ϰ� �ǳʶڴ�.
	// cin �Է��� ���۸� �̿��Ѵ�!
	// ����ڰ� �Է��� ���ڵ��� Enter Ű�� ������ �������� ���α׷��� ���޵��� �ʴ´�.(�ӵ�)
	// �Ϲ������� I/O �۾��� ���̴�.

	// ������ �ذ��ϴ� ���
	char ch2;
	int count = 0;
	cout << "���ڵ��� �Է�, �������� #: ";
	cin.get(ch2);
	while (ch2 != '#')
	{
		cout << ch2;
		++count;
		cin.get(ch2);
	}
	cout << endl << count << " ���ڸ� �о����ϴ�.\n";
	return 0;
}