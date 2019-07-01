#include <iostream>

int main() {
	char name[100];
	char pNum[100];

	std::cout << "당신의 이름은 : ";
	std::cin >> name;
	std::cout << "전화번호는 : ";
	std::cin >> pNum;

	std::cout << "이름은 : " << name << std::endl;
	std::cout << "전화번호는 : " << pNum << std::endl;
	return 0;
}