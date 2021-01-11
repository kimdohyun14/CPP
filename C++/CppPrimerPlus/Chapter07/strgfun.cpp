// strgfun.cpp -- 문자열 매개변수와 함수
#include <iostream>
unsigned int c_in_str(const char* str, char ch);
int main()
{
	using namespace std;
	char mmm[15] = "minimum";       // 배열에 들어 있는 문자열
	const char* wail = "ululate";   // wail은 문자열을 지시한다.
	
	unsigned int ms = c_in_str(mmm, 'm');
	unsigned int us = c_in_str(wail, 'u');
	cout << mmm << "에는 m이 " << ms << "개 들어 있습니다.\n";
	cout << wail << "에는 u가 " << us << "개 들어 있습니다.\n";
	return 0;
}

unsigned int c_in_str(const char* str, char ch)
{
	int count = 0;

	while(*str) // *str가 '\0'이면 루프를 탈출한다
	{ 
		if (*str == ch)
			count++;
		str++;
	}
	// std::cout << (int)(*str) << std::endl;
	return count;
}