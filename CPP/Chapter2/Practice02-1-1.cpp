#include <iostream>
using namespace std;

void plusOne(int &ref) {
	ref++;
}

void InverSign(int &ref) {
	ref = ref * (-1);
}

int main() {
	int num = 1;
	cout << "�����ϱ� �� num : " << num << endl;
	plusOne(num);
	cout << "������ �� num : " << num << endl;
	cout << "��ȣ�ٲٱ� �� num : " << num << endl;
	InverSign(num);
	cout << "��ȣ�ٲ� �� num : " << num << endl;
	return 0;
}