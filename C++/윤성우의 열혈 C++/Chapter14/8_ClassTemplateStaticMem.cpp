#include <iostream>
using namespace std;

template<typename T>
class SimpleStaticMem
{
private:
	static T mem;
public:
	void AddMem(int num) { mem += num; }
	void ShowMem() { cout << mem << endl; }
};

template<typename T>
T SimpleStaticMem<T>::mem = 0; // static 멤버의 초기화

// long long 타입에대해서는 초기화문 특수화 진행
template<>
long long SimpleStaticMem<long long>::mem = 5; 

int main()
{
	SimpleStaticMem<int> obj1;
	SimpleStaticMem<int> obj2;
	obj1.AddMem(2);
	obj2.AddMem(3);
	obj1.ShowMem();
	SimpleStaticMem<long> obj3;
	SimpleStaticMem<long> obj4;
	obj3.AddMem(100);
	obj4.ShowMem();
	SimpleStaticMem<long long> obj5;
	SimpleStaticMem<long long> obj6;
	obj5.AddMem(5);
	obj6.ShowMem();
	return 0;
}