// cctypes.cpp -- ctype.h 라이브러리 사용
#include <iostream>
#include <cctype> // 문자 관련 함수들의 원형
int main()
{
	using namespace std;
	cout << "분석할 텍스트를 입력하십시오. "
		"입력의 끝을 @으로 표시하십시오.\n";

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
	cout << "알파벳 문자 " << chars << ", "
		<< "화이트스페이스 " << whitespace << ", "
		<< "숫자 " << digits << ", "
		<< "구두점 " << punct << ", "
		<< "기타 " << others << endl;
	return 0;
}