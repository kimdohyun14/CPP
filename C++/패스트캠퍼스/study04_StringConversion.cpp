#include <iostream>
#include <string>
using namespace std;

// C++�� string�� �ٸ� �ڷ��������� ��ȯ�� �����ϴ�.

int main()
{
	int i = 123;
	string s = to_string(i);
	cout << "���� -> ���ڿ�: " << s << endl;
	s = "456";
	i = stoi(s); // string to integer
	cout << "���ڿ� -> ����: " << i << endl;
	return 0;
}