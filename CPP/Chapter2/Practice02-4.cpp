#include <cstring>
#include <iostream>
using namespace std;

int main() {
	char str1[30] = "I am happy! and";
	cout << "���ڿ��� ���� ��� : " << strlen(str1) << endl;
	cout << "���ڿ��� �ڿ� good���̱� : ";
	strcat(str1, " good!");
	cout << str1 << endl;
	cout << "���ڿ� �����ϱ�" << endl;
	char str2[30];
	strcpy(str2, str1);
	cout << "����� ���ڿ� ��� : " << str2 << endl;
	cout << "���ڿ� ���ϱ� str1, str2" << endl;
	if (strcmp(str1, str2) == 0) {
		cout << "str1�� str2�� �����ϴ�." << endl;
	}
	else {
		cout << "str1�� str2�� ���� �ʽ��ϴ�." << endl;
	}
	return 0;
}