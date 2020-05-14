#include <iostream>

namespace BestCom
{
	void SimpleFunc()
	{
		std::cout << "BestCom이 정의한 함수" << std::endl;
	}
}

namespace ProgCom
{
	void SimpleFunc()
	{
		std::cout << "ProgCom이 정의한 함수" << std::endl;
	}
}

int main()
{
	BestCom::SimpleFunc();
	ProgCom::SimpleFunc();
	return 0;
}