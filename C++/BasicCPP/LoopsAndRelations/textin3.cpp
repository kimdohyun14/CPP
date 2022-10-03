#include <iostream>
using namespace std;

// cin�� EOF�� Ž������ ��, �� ���� ��Ʈ eofbit, failbit�� 1�� �����Ѵ�.
// cin.eof()�� ȣ���� EOF�� Ž���Ǿ����� true, �ƴϸ� false
// cin.fail()�� ȣ���� eofbit �Ǵ� failbit�� 1�� �����Ǿ� ������ true, �ƴϸ� false
// �� �޼��� ��� �̷��� �����ϴ� ���� �ƴ϶� ���Ÿ� �����Ѵ�.

// �÷��װ� �����Ǹ�, cin�� �� �̻��� �Է��� �޾Ƶ����� �ʴ´�.
// cin.clear() �޼���� EOF �÷��׸� �����, �ٽ� �Է��� ����� �� �ֵ��� ����Ѵ�.

// cin.get(char) �޼��尡 �����ϴ� ���� cin ��ü
// istream Ŭ������ cin�� ���� istream ��ü�� bool ������ ��ȯ�ϴ� �Լ��� �����Ѵ�.
// bool������ ��ȯ�� ����� ���������� �õ��� �бⰡ �����̸� true, ���и� false �����Ѵ�.

int main()
{
	char ch;
	int count = 0;
	cin.get(ch); // ���� �ϳ� �б�
	while (cin.fail() == false)  // EOF �˻�, while (cin.get(ch)) �̰͵� �����ϴ�.
                                 // �Է��� �������̸� ch�� ���� �ִ´�.
		                         // ���� ������ �ľ�, ������ �ʱ�ȭ, ������ ����(3���� ó��)
	{
		cout << ch; // ���� ����
		++count;
		cin.get(ch); // ���� ���ڸ� �д´�.
	}

	cout << count << " ���ڸ� �о����ϴ�.\n";
	return 0;
}
