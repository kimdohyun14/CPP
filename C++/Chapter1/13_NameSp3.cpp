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
	std::cout << "BestCom�� ������ �Լ�" << std::endl;
	PrettyFunc();          // ���� �̸������� ���(������� �ʾƵ� ��밡��)
	ProgCom::SimpleFunc(); // �ٸ� �̸������̹Ƿ� ��� �ʼ�

}

void BestCom::PrettyFunc()
{
	std::cout << "So Pretty!!" << std::endl;
}

void ProgCom::SimpleFunc()
{
	std::cout << "ProgCom�� ������ �Լ�" << std::endl;
}