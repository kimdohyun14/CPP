#include <iostream>

int main() {
	char name[100];
	char pNum[100];

	std::cout << "����� �̸��� : ";
	std::cin >> name;
	std::cout << "��ȭ��ȣ�� : ";
	std::cin >> pNum;

	std::cout << "�̸��� : " << name << std::endl;
	std::cout << "��ȭ��ȣ�� : " << pNum << std::endl;
	return 0;
}