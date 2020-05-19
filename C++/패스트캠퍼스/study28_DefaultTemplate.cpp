#include <iostream>
using namespace std;

// 클래스 템플릿 : 디폴트 템플릿 인수
template<typename T = int>
class Data
{
private:
	T data;
public:
	Data(T data) : data(data) { }
	void setData(T data) { this->data = data; }
	T getData() { return data; }
};

int main()
{
	Data<> data1(1);
	Data<string> data2("dohyun");
	cout << data1.getData() << " : " << data2.getData() << endl;
	return 0;
}