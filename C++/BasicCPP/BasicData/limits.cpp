#include <iostream>
#include <climits> // �ִ밪���� �����س��� ������� (��ó��)

// #define �� C�� ����
// C++ ������ ��ȣ ����� �� ������. ex) const Ű���� ���

int main()
{
	using namespace std; // main �ȿ����� ��ȿ
	int n_int = INT_MAX;
	short n_short = SHRT_MAX;
	long n_long = LONG_MAX;
	long long n_llong = LLONG_MAX;

	// sizeof �����ڴ� ���������̳� ������ ũ�⸦ �˾Ƴ� �� �ִ�.
	// �������� �̸����� sizeof �����ڿ� ��ȣ�� �ٿ��� ������,
	// ���� �̸��� ����� ������ ��ȣ ���� ����� �����ϴ�.
	cout << "sizeof(int) " << sizeof(int) << endl;
	cout << "sizeof(short) " << sizeof(short) << endl;
	cout << "sizeof(long) " << sizeof(long) << endl;
	cout << "sizeof(long long) " << sizeof(long long) << endl;
	cout << "sizeof(n_llong) " << sizeof n_llong << endl;
	cout << endl;

	cout << "int max : " << n_int << endl;
	cout << "short max : " << n_short << endl;
	cout << "long max : " << n_long << endl;
	cout << "long long max : " << n_llong << endl;
	cout << "����Ʈ �� ��Ʈ �� : " << CHAR_BIT << endl;
	return 0;
}