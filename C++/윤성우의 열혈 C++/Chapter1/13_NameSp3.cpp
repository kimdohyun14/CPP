#include <iostream>

namespace BestCom
{
	void SimpleFunc();
}

namespace BestCom
{
	void PrettyFunc();
}

namespace ProgCom
{
	void SimpleFunc();
}

int main()
{
	BestCom::SimpleFunc();
	return 0;
}

void BestCom::SimpleFunc()
{
	std::cout << "BestCom이 정의한 함수" << std::endl;
	PrettyFunc();          // 동일 이름공간인 경우(명시하지 않아도 사용가능)
	ProgCom::SimpleFunc(); // 다른 이름공간이므로 명시 필수

}

void BestCom::PrettyFunc()
{
	std::cout << "So Pretty!!" << std::endl;
}

void ProgCom::SimpleFunc()
{
	std::cout << "ProgCom이 정의한 함수" << std::endl;
}