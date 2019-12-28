#include <iostream>
using namespace std;

void Counter() {
	static int cnt; //이 문장은 딱 한번만 실행되며, 초기화를 하지 않으면 전역변수처럼 0으로 초기화된다.
	cnt++;
	cout << "Current cnt: " << cnt << endl;
}

int main() {
	for (int i = 0; i < 10; i++)
		Counter();
	return 0;
}