/*
�� Ÿ�� �� �д� ���

input : 38.5 19.2

char ch;
cin >> ch;
ù ���ڴ� 3, �� ���ڿ� �ش��ϴ� ���� �ڵ尡 ���Եȴ�.
�Է� ������ ���� �Ŀ�, �Է� ť�� �ִ� ���� ���ڴ� ���� 8�̴�.

int n;
cin >> n;
���� 3�� ���� 8�� �а� ������ ���� ���ڷ� �Ҽ����� �Է� ť�� ���ܵд�.

double x;
cin >> x;
�ε������� ���� �Ϻΰ� �ƴ� ù ���ڰ� ���� ������ �д´�.
����3, ���� 8, �Ҽ���. ����, ���� 5�� �а�, ������ ���� ���ڷ� ��ĭ�� �Է� ť�� ���ܵд�.

char word[50];
cin >> word;
��ĭ ���ڰ� ���� ������ �д´�.
����3, ����8, �Ҽ��� ����. , ���� 5�� �а�, ������ ���� ���ڷ� ��ĭ�� �Է� ť�� ���ܵд�.
���� �ڵ���� �迭 word�� �����ϰ�, ���� �� ���ڸ� �߰��Ѵ�.

char word[50];
cin.getline(word, 50);
���� ���ڰ� ���� ������ �д´�.
��� ���ڸ� �����ϰ�, ���� �� ���ڸ� �߰��Ѵ�.
��, ���� ���ڴ� ����Ѵ�!


#### ���� ����� ����ϴ� �⺻ ���� ####
1. fstream ��� ������ ����
2. ofstream ��ü�� ����
3. ofstream ��ü�� ���Ͽ� ����
4. ofstream ��ü�� cout�� ������ ������� ���
*/

#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	char automobile[50];
	int year;
	double a_price;
	double d_price;

	ofstream outFile; // ����� ���� ��ü ����
	outFile.open("carinfo.txt"); // ���Ͽ� ����

	cout << "�ڵ��� ����Ŀ�� ������ �Է��ϼ���: ";
	cin.getline(automobile, 50);
	cout << "������ �Է��ϼ��� : ";
	cin >> year;
	cout << "���� ������ �Է��ϼ���: ";
	cin >> a_price;
	d_price = 0.913 * a_price;

	// cout���� ��ũ���� ������ ���÷���

	cout << fixed;
	cout.precision(2); // ���е� 2���
	cout.setf(ios_base::showpoint);
	cout << "����Ŀ�� ����: " << automobile << endl;
	cout << "����: " << year << endl;
	cout << "���� ���� $" << a_price << endl;
	cout << "���� ���� $" << d_price << endl;

	// cout ��� outFile�� ����Ͽ� �Ȱ��� ���� ó���� �� �ִ�.
	outFile << fixed;
	outFile.precision(2);
	outFile.setf(ios_base::showpoint);
	outFile << "����Ŀ�� ����: " << automobile << endl;
	outFile << "����: " << year << endl;
	outFile << "���� ���� $" << a_price << endl;
	outFile << "���� ���� $" << d_price << endl;

	outFile.close(); // ���� ó�� ����
	return 0;
}