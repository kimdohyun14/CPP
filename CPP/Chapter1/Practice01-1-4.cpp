#include <iostream>

int main() {
	int salary; //�޿�
	while (1) {
		std::cout << "�Ǹ� �ݾ��� ���� ������ �Է�(-1 to end): ";
		std::cin >> salary;
		if (salary == -1) break;
		std::cout << "�̹� �� �޿�: " << 50 + salary * 0.12 << "����"<<std::endl;
	}
	std::cout << "���α׷��� �����մϴ�." << std::endl;
	return 0;
}