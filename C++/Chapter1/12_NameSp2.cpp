#include <iostream>

namespace BestCom
{
	void SimpleFunc();
}

namespace ProgCom
{
	void SimpleFunc();
}

int main()
{
	BestCom::SimpleFunc();
	ProgCom::SimpleFunc();
	return 0;
}

void BestCom::SimpleFunc()
{
	std::cout << "BestCom�� ������ �Լ�" << std::endl;
}

void ProgCom::SimpleFunc()
{
	std::cout << "ProgCom�� ������ �Լ�" << std::endl;
}