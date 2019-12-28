#include <iostream>
using namespace std;

class SoSimple {
private:
	int num;
public:
	SoSimple(int n):num(n){}
	SoSimple& AddNum(int n) {
		num += n;
		return *this; //객체 자신을 반환
	}
	void ShowData() const {
		cout << "num: " << num << endl;
	}

};

int main() {
	const SoSimple obj(7);
	//obj.AddNum(5); const 함수가 아니기 때문에 오류
	obj.ShowData();
	return 0;
}