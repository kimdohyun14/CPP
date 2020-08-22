#include <iostream>
using namespace std;

// 템플릿 매개변수는 디폴트 값 지정도 가능하다.
template<typename T=int, int len=7>
class SimpleArray
{
private:
	T arr[len];
public:
	T& operator[] (int idx) { return arr[idx]; }
	SimpleArray<T, len>& operator=(const SimpleArray<T, len>& ref)
	{
		for (int i = 0; i < len; ++i)
			arr[i] = ref.arr[i];
		return *this;
	}
};

int main()
{
	SimpleArray<> arr;
	for (int i = 0; i < 7; ++i)
		arr[i] = i + 1;
	for (int i = 0; i < 7; ++i)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}