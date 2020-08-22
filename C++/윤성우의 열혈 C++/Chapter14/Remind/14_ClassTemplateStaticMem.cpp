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
T SimpleStaticMem<T>::mem = 0; // static 멤버의 초기화 문장

template<>
long SimpleStaticMem<long>::mem = 5; // 따로 long으로 특수화시켜 static 멤버를 5로 초기화 할 수 있다.
 
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
	return 0;
}
