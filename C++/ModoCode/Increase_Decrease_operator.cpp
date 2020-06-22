#include <iostream>

class Test
{
	int x;

public:
	Test(int x) : x(x) {}
	Test(const  Test& t) : x(t.x) {}

	Test& operator++()
	{
		x++;
		std::cout << "���� ���� ������" << std::endl;
		return *this;
	}

	Test operator++(int)
	{
		Test temp(*this);
		x++;
		std::cout << "���� ���� ������" << std::endl;
		return temp;
	}

	int get_x() const
	{
		return x;
	}
};

void func(const Test& t)
{
	std::cout << "x : " << t.get_x() << std::endl;
}

int main()
{
	Test t(3);

	func(++t); // 4
	func(t++); // 4
	std::cout << "x : " << t.get_x() << std::endl; // 5
	return 0;
}