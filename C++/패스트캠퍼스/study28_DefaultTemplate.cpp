#include <iostream>
using namespace std;

// Ŭ���� ���ø� : ����Ʈ ���ø� �μ�
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