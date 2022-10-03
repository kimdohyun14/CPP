#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char word[5] = "?ate";

	// strcmp (word, "mate") 같지 않으면 1을
	// 같으면 0을 리턴한다.
	for (char ch = 'a'; strcmp(word, "mate") != 0; ch++)
	{
		cout << word << endl;
		word[0] = ch;
	}

	char word1[5] = "abcd";
	char word2[5] = "ferd";

	// strcmp(a, b) == 0 같다.
	// strcmp(a, b) != 0 다르다.
	// strcmp(a, b) < 0  a가 b보다 사전순으로 앞이다.
	// strcmp(a, b) > 0  a가 b보다 사전순으로 뒤다.
	cout << strcmp(word1, word2) << endl; // -1

	cout << "루프 종료 : " << word << endl;
	return 0;
}