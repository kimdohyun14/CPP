#include <iostream>
using namespace std;

class SoSimple {
private:
	int num;
public:
	SoSimple(int n):num(n){}
	SoSimple& AddNum(int n) {
		num += n;
		return *this; //��ü �ڽ��� ��ȯ
	}
	void ShowData() const {
		cout << "num: " << num << endl;
	}

};

int main() {
	const SoSimple obj(7);
	//obj.AddNum(5); const �Լ��� �ƴϱ� ������ ����
	obj.ShowData();
	return 0;
}