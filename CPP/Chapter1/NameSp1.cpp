#include <iostream>

namespace BestComImpl {
	void SimpleFunc(void) {
		std::cout << "BestCom�� ������ �Լ�" << std::endl;
	}
}

namespace ProgComlmpl {
	void SimpleFunc(void) {
		std::cout << "ProgCom�� ������ �Լ�" << std::endl;
	}
}

int main() {
	BestComImpl::SimpleFunc();
	ProgComlmpl::SimpleFunc();
	return 0;
}