#include <iostream> // C++ 표준 입출력 라이브러리
#include <string>

int main()
{
	std::string input;

	std::cin >> input; 	// 연산자 >>는 공백 문자(space, Enter, Tab)을 기준으로 입력을 받는다.

	std::cout << input << std::endl;
	return 0;
}