#include <iostream>
using namespace std;

class SoSimple {
private:
	int num;
public:
	SoSimple(int n) :num(n){}
	SoSimple(const SoSimple& copy) :num(copy.num) {
		cout << "called SoSimple(const SoSimple& copy)" << endl;
	}
	void ShowData() {
		cout << "num: " << num << endl;
	}
};

void SimpleFuncObj(SoSimple ob) { //ob객체가 생성되고, 인자로 전달된 obj객체로 초기화된다.
	ob.ShowData();
}

int main() {
	SoSimple obj(7);
	cout << "함수호출 전" << endl;
	SimpleFuncObj(obj);
	cout << "함수호출 후" << endl;
	return 0;
}