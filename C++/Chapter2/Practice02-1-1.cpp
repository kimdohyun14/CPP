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
	cout << "µ¡¼ÀÇÏ±â Àü num : " << num << endl;
	plusOne(num);
	cout << "µ¡¼ÀÇÑ ÈÄ num : " << num << endl;
	cout << "ºÎÈ£¹Ù²Ù±â Àü num : " << num << endl;
	InverSign(num);
	cout << "ºÎÈ£¹Ù²Û ÈÄ num : " << num << endl;
	return 0;
}