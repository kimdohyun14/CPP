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
	std::cout << "BestCom�� ������ �Լ�" << std::endl;
	PrettyFunc(); //���� �̸�����
	ProgComlmpl::SimpleFunc(); //�ٸ� �̸�����
}

void BestComlmpl::PrettyFunc(void) {
	std::cout << "So Pretty!" << std::endl;
}

void ProgComlmpl::SimpleFunc(void) {
	std::cout << "ProgCom�� ������ �Լ�" << std::endl;
}