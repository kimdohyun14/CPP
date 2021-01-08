// cctypes.cpp -- ctype.h ���̺귯�� ���
#include <iostream>
#include <cctype> // ���� ���� �Լ����� ����
int main()
{
	using namespace std;
	cout << "�м��� �ؽ�Ʈ�� �Է��Ͻʽÿ�. "
		"�Է��� ���� @���� ǥ���Ͻʽÿ�.\n";

	char ch;
	int whitespace = 0;
	int digits = 0;
	int chars = 0;
	int punct = 0;
	int others = 0;

	cin.get(ch);
	while (ch != '@')
	{
		if (isalpha(ch))
			chars++;
		else if (isspace(ch))
			whitespace++;
		else if (isdigit(ch))
			digits++;
		else if (ispunct(ch))
			punct++;
		else
			others++;
		cin.get(ch);
	}
	cout << "���ĺ� ���� " << chars << ", "
		<< "ȭ��Ʈ�����̽� " << whitespace << ", "
		<< "���� " << digits << ", "
		<< "������ " << punct << ", "
		<< "��Ÿ " << others << endl;
	return 0;
}