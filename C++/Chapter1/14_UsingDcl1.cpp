#include <iostream>

namespace Hybrid
{
	void HybFunc()
	{
		std::cout << "So simple function!" << std::endl;
		std::cout << "In namespace Hybrid" << std::endl;
	}
}

int main()
{
	using Hybrid::HybFunc;
	HybFunc();
	return 0;
}