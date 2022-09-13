#include <iostream>

// 확장 문자, 문자열
/*
char형은 signed, unsigned를 나눌 필요 없이 char로 사용한다.

확장 char형 : wchar_t (wide character type)
확장 문자 세트

wcin, wcout 객체를 사용해서 표현한다.
wchar_t bob = L'P';
wcout << L"hello" << endl;

새로운 C++11형: char16_t 와 char32_t
char16_t : unsigned 16비트형
u'C', u"Hello" 로 표현한다.

char32_t : unsigned 32비트형
U'C', U"Hello" 로 표현한다.

*/

int main()
{
	using namespace std;
	char ch = 'M';
	int i = ch;
	cout << ch << "의 ASCII 코드는 " << i << endl;

	// ch는 실제로 정수이므로 정수 연산이 가능하다.
	cout << "이 문자 코드에 +1을 하면\n";
	ch += 1;
	i = ch;
	cout << ch << "의 ASCII 코드는 " << i << endl;

	// cout.put() 멤버 함수를 사용해서 char형 변수 ch를 출력하자.
	cout << "cout.put(ch) : ";
	cout.put(ch);
	cout.put('!'); // 문자 상수 출력도 가능하다.
	cout << endl;
	return 0;
}