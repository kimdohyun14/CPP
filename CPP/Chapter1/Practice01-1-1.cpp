#include <iostream>

int main() {
	int val, idx = 1;
	int result = 0;
	while (1) {
		std::cout << idx << "��° ���� �Է�: ";
		std::cin >> val;
		result += val;
		idx++;
		if (idx == 6) break;
	}
	std::cout << result << std::endl;
	return 0;
}