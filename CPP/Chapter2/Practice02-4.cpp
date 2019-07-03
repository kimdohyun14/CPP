#include <cstring>
#include <iostream>
using namespace std;

int main() {
	char str1[30] = "I am happy! and";
	cout << "문자열의 길이 계산 : " << strlen(str1) << endl;
	cout << "문자열의 뒤에 good붙이기 : ";
	strcat(str1, " good!");
	cout << str1 << endl;
	cout << "문자열 복사하기" << endl;
	char str2[30];
	strcpy(str2, str1);
	cout << "복사된 문자열 출력 : " << str2 << endl;
	cout << "문자열 비교하기 str1, str2" << endl;
	if (strcmp(str1, str2) == 0) {
		cout << "str1과 str2가 같습니다." << endl;
	}
	else {
		cout << "str1과 str2가 같지 않습니다." << endl;
	}
	return 0;
}