#include <iostream>

namespace BestComImpl {
	void SimpleFunc(void) {
		std::cout << "BestCom이 정의한 함수" << std::endl;
	}
}

namespace ProgComlmpl {
	void SimpleFunc(void) {
		std::cout << "ProgCom이 정의한 함수" << std::endl;
	}
}

int main() {
	BestComImpl::SimpleFunc();
	ProgComlmpl::SimpleFunc();
	return 0;
}