#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char word[5] = "?ate";

	// strcmp (word, "mate") ���� ������ 1��
	// ������ 0�� �����Ѵ�.
	for (char ch = 'a'; strcmp(word, "mate") != 0; ch++)
	{
		cout << word << endl;
		word[0] = ch;
	}

	char word1[5] = "abcd";
	char word2[5] = "ferd";

	// strcmp(a, b) == 0 ����.
	// strcmp(a, b) != 0 �ٸ���.
	// strcmp(a, b) < 0  a�� b���� ���������� ���̴�.
	// strcmp(a, b) > 0  a�� b���� ���������� �ڴ�.
	cout << strcmp(word1, word2) << endl; // -1

	cout << "���� ���� : " << word << endl;
	return 0;
}