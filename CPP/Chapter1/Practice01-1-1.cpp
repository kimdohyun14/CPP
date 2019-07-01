#include <iostream>

int main() {
	int val, idx = 1;
	int result = 0;
	while (1) {
		std::cout << idx << "번째 정수 입력: ";
		std::cin >> val;
		result += val;
		idx++;
		if (idx == 6) break;
	}
	std::cout << result << std::endl;
	return 0;
}