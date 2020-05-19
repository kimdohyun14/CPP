#include <iostream>
using namespace std;

// Ŭ���� ���ø�

	/* C++�� Ŭ������ �Ϲ�ȭ�ϱ� ���ؼ� Ŭ���� ���ø�(Class Template)�� Ȱ���� �� �ִ�.
	   Ŭ���� ���ø��� ����ϸ� �ڷ����� ���� �ٸ��� �����ϴ� Ŭ���� ������ ���� �� �ִ�.
	   
	   ������� ���Ḯ��Ʈ�� �ڷ��� ��� */

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