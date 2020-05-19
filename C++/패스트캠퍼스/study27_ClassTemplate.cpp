#include <iostream>
using namespace std;

// 클래스 템플릿

	/* C++은 클래스를 일반화하기 위해서 클래스 템플릿(Class Template)을 활용할 수 있다.
	   클래스 템플릿을 사용하면 자료형에 따라서 다르게 동작하는 클래스 집합을 만들 수 있다.
	   
	   예를들면 연결리스트의 자료형 사용 */

template<typename T>
class Data
{
private:
	T data;
public:
	Data(T data) : data(data) {}
	void setData(T data) { this->data = data; }
	T getDate() { return data; }
};

int main()
{
	Data<int> data1(1);
	Data<string> data2("dohyun");
	cout << data1.getDate() << " : " << data2.getDate() << endl;
	return 0;
}