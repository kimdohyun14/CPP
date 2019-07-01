#include <iostream>

int main() {
	int dan;
	std::cout << "숫자를 입력 : ";
	std::cin >> dan;
	for (int i = 1; i < 10; i++) {
		std::cout << dan << "*" << i << "=" << dan * i << std::endl;
	}
	return 0;
}