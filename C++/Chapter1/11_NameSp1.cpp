#include <iostream>

namespace BestCom
{
	void SimpleFunc()
	{
		std::cout << "BestCom�� ������ �Լ�" << std::endl;
	}
}

namespace ProgCom
{
	void SimpleFunc()
	{
		std::cout << "ProgCom�� ������ �Լ�" << std::endl;
	}
}

int main()
{
	BestCom::SimpleFunc();
	ProgCom::SimpleFunc();
	return 0;
}