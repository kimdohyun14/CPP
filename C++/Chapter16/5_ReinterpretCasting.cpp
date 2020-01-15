#include <iostream>
using namespace std;

// reinterpret_cast : 상관없는 자료형으로의 형 변환

// 포인터와 관련이 있는 모든 유형의 형 변환을 허용한다.

int main()
{
	int num = 0x010203;
	char* ptr = reinterpret_cast<char*>(&num); // int형 포인터 -> char형 포인터 형 변환

	for (int i = 0; i < sizeof(num); i++)
	{
		cout << static_cast<int>(*(ptr + i)) << endl; // char형 -> int형 형 변환
	}
	return 0;
}