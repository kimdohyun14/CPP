#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout << "�ܾ� �ϳ��� �Է� : ";
	string word;
	cin >> word;

	// ���ڿ��� �Ųٷ� ����غ���.
	// Ư���ϰԵ� redder�� stats�� ���� �Ųٷ� �о ö�ڰ� ���� ȸ��(palindrome)�� �Է��ϸ� �����ϴ�.
	for (int i = word.size() - 1; i >= 0; i--)
		cout << word[i];
	cout << "\n����.\n";
	return 0;
}