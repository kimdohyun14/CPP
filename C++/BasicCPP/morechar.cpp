#include <iostream>

// Ȯ�� ����, ���ڿ�
/*
char���� signed, unsigned�� ���� �ʿ� ���� char�� ����Ѵ�.

Ȯ�� char�� : wchar_t (wide character type)
Ȯ�� ���� ��Ʈ

wcin, wcout ��ü�� ����ؼ� ǥ���Ѵ�.
wchar_t bob = L'P';
wcout << L"hello" << endl;

���ο� C++11��: char16_t �� char32_t
char16_t : unsigned 16��Ʈ��
u'C', u"Hello" �� ǥ���Ѵ�.

char32_t : unsigned 32��Ʈ��
U'C', U"Hello" �� ǥ���Ѵ�.

*/

int main()
{
	using namespace std;
	char ch = 'M';
	int i = ch;
	cout << ch << "�� ASCII �ڵ�� " << i << endl;

	// ch�� ������ �����̹Ƿ� ���� ������ �����ϴ�.
	cout << "�� ���� �ڵ忡 +1�� �ϸ�\n";
	ch += 1;
	i = ch;
	cout << ch << "�� ASCII �ڵ�� " << i << endl;

	// cout.put() ��� �Լ��� ����ؼ� char�� ���� ch�� �������.
	cout << "cout.put(ch) : ";
	cout.put(ch);
	cout.put('!'); // ���� ��� ��µ� �����ϴ�.
	cout << endl;
	return 0;
}