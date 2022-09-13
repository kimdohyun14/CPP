#include <iostream>
using namespace std;
/*
istream Ŭ������ �� ��° ��� �Լ��� get()

�� �Լ��� ���� ���ڸ� �о ������ �ʰ�, �Է� ť�� �״�� ���ܵд�.
=> getline()���� �������̴�.

�׷��� ���� ���� ���ڸ� ������ ���ؼ�
cin.get() �� ȣ���ϱ⵵ �Ѵ�.
=> ���� �����̵� �ƴϸ� �ٸ� �����̵� ���� ������ ���� �ϳ��� �д´�.

�����ؼ� ����ϱ⵵ �Ѵ�.
cin.get(name, ArSize).get();
=> cin.getline(name, ArSize) �� ������ �ǹ̴�.

# �Լ� �����ε�
�Ű����� ����Ʈ�� �ٸ��� �Ͽ� ���� �̸��� �Լ��� ���� �� ����� ��

getline() �� ����ϱ� �� �� ���ϰ�,
get()�� ���� üŷ�� �� �� ����.
*/

int main()
{
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];

	cout << "�̸� �Է�:\n";
	cin.get(name, ArSize).get(); // ���ڿ�, ���� ���ڸ� �д´�.
	cout << "�����ϴ� ����Ʈ �Է�:\n";
	cin.get(dessert, ArSize).get();
	cout << "���ִ� " << dessert << " ����Ʈ�� �غ��ϰڽ��ϴ�. " << name << "��!\n";
	return 0;
}