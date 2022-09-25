#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout << "단어 하나를 입력 : ";
	string word;
	cin >> word;

	// 문자열을 거꾸로 출력해보자.
	// 특이하게도 redder나 stats와 같이 거꾸로 읽어도 철자가 같은 회문(palindrome)을 입력하면 동일하다.
	for (int i = word.size() - 1; i >= 0; i--)
		cout << word[i];
	cout << "\n종료.\n";
	return 0;
}