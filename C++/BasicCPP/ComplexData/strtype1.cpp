#include <iostream>
#include <string>
using namespace std;

// C ��Ÿ�� ���ڿ��� string ��ü�� �ʱ�ȭ ����
// cin �� ����Ͽ� string ��ü�� Ű���� �Է��� ���尡��
// cout �� ����ؼ� string ��ü�� �� �� �ִ�.
// �迭 ǥ�⸦ ����ؼ� string ��ü�� ����Ǿ� �ִ� �������� ���ڵ鿡 ���� �� ���Ⱑ �����ϴ�.
int main()
{
	char charr1[20];
	char charr2[20] = "jaguar";
	string str1;
	string str2 = "panther"; 

	cout << "����̰��� ���� �� ���� �Է� : ";
	cin >> charr1;
	cout << "����̰��� �� �ٸ� ���� �� ���� �Է� : ";
	cin >> str1; // str1�� ũ�⸦ �ڵ����� �����Ѵ�. (�Է¿� �°� ũ�Ⱑ �����ȴ�.)
	cout << "�Ʒ� �������� ��� ����̰��Դϴ�:\n";
	cout << charr1 << " " << charr2 << " " << str1 << " " << str2 << endl;

	cout << charr2 << "���� �� ��° ���� : " << charr2[2] << endl;
	cout << str2 << "���� �� ��° ���� : " << str2[2] << endl;
	return 0;
}