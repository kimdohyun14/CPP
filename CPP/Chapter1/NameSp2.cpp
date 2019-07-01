#include <iostream>

namespace BestComlmpl {
	void SimpleFunc(void);
}

namespace BestComlmpl {
	void PrettyFunc(void);
}

namespace ProgComlmpl {
	void SimpleFunc(void);
}

int main() {
	BestComlmpl::SimpleFunc();
	return 0;
}

void BestComlmpl::SimpleFunc(void) {
	std::cout << "BestCom이 정의한 함수" << std::endl;
	PrettyFunc(); //동일 이름공간
	ProgComlmpl::SimpleFunc(); //다른 이름공간
}

void BestComlmpl::PrettyFunc(void) {
	std::cout << "So Pretty!" << std::endl;
}

void ProgComlmpl::SimpleFunc(void) {
	std::cout << "ProgCom이 정의한 함수" << std::endl;
}