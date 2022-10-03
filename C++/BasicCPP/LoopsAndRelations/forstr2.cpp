#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout << "단어를 입력하세요 : ";
	string word;
	cin >> word;

	char temp;
	int i, j;
	// --i, ++j 두 개의 표현식은 하나의 표현식으로 간주된다!
	for (j = 0, i = word.size() - 1; j < i; --i, ++j)
	{
		temp = word[i];
		word[i] = word[j];
		word[j] = temp;
	}
	cout << word << endl;
	return 0;
}