#include <iostream>
using namespace std;

// get(), getlien() ������!
// Ư�� ���ڿ��� ��ġ �Է��� ȥ���� �� �����ؾ� �Ѵ�.
int main()
{
	cout << "���� ��ô� ����Ʈ�� ���� �����ϼ̳���?\n";
	int year;
	(cin >> year).get();
	cout << "��ô� ���ø� ������ �ֽðڽ��ϱ�?\n";
	char address[80];
	cin.getline(address, 80);
	cout << "����Ʈ ���� ���� : " << year << endl;
	cout << "���� : " << address << endl;
	cout << "����� �Ϸ�Ǿ����ϴ�!\n";
	return 0;
}