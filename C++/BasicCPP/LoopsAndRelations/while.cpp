#include <iostream>
using namespace std;

const int ArSize = 20;
int main()
{
	char name[ArSize];

	cout << "���� �Է� : ";
	cin >> name;
	cout << "������ ���� �̸��� �� �ٿ� �� �ھ�\n";
	cout << "ASCII �ڵ�� �Բ� ǥ���ϸ� �̷���.\n";
	int i = 0;
	while (name[i] != '\0')
	{
		cout << name[i] << ": " << int(name[i]) << endl;
		i++;
	}
	// C ��Ÿ�� ���ڿ��� �޸�, string Ŭ���������� 
	// ���ڿ��� ���� �ν��ϱ� ���Ͽ� �� ���ڸ� ������� �ʴ´ٴ� ������ �ִ�.

	return 0;
}