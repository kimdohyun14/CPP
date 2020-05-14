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
	std::cout << "BestCom이 정의한 함수" << std::endl;
}

void ProgCom::SimpleFunc()
{
	std::cout << "ProgCom이 정의한 함수" << std::endl;
}