#include <iostream>

//레퍼런스 : 어떤 다른 변수의 참고, 다른 이름 (참조자)
//한 번 별명이 된다면 영원히 바뀔 수 없다.
int change_val(int& p) {
	p = 3;
	return 0;
}

int main() {
	int number = 5;

	std::cout << number << std::endl;
	change_val(number);
	std::cout << number << std::endl;
}