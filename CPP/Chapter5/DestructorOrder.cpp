#include <iostream>
using namespace std;

class Test {
private:
	int num;
public:
	Test(int n) :num(n) {}
	~Test() {
		cout << "num : " << num << endl;
	}
};

int main() {
	Test t1(10);
	cout << "tetetete" << endl;
	Test t2(20);
	return 0;
}