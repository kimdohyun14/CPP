#include <iostream>
#include <string>
#include <cstring>
int main()
{
	using namespace std;
	char charr[20];
	string str;

	// strlen�� ù ��° ���ҿ��� ����Ͽ� �� ���ڿ� ������ ������ ����Ʈ���� ī�����Ѵ�.
	cout << "�Է� ������ charr�� �ִ� ���ڿ��� ���� : " << strlen(charr) << endl;
	cout << "�Է� ������ str�� �ִ� ���ڿ��� ���� : " << str.size() << endl;
	cout << "�ؽ�Ʈ �� ���� �Է�\n";
	cin.getline(charr, 20);
	cout << "�Է��� �ؽ�Ʈ: " << charr << endl;
	cout << "�� �ٸ� �ؽ�Ʈ �� ���� �Է�\n";
	getline(cin, str);
	cout << "�Է��� �ؽ�Ʈ: " << str << endl;
	cout << "�Է� ���Ŀ� charr�� �ִ� ���ڿ��� ���� : " << strlen(charr) << endl;
	cout << "�Է� ���Ŀ� str�� �ִ� ���ڿ��� ���� : " << str.size() << endl;
	return 0;
}