#include <iostream>
// ���� ���̴� ��ⷯ ������ �����̴�.
// �⺻������ % m ���� �����ϸ� ����� 0 ~ m - 1 ������ ������ ������ �ȴ�.
int main()
{
	using namespace std;
	const int Lbs_per_stn = 14;
	int lbs;

	cout << "����� ü���� �Ŀ�� ������ �Է��ϼ���. ";
	cin >> lbs;
	int stone = lbs / Lbs_per_stn;  // ���� ��������
	int pounds = lbs % Lbs_per_stn; // �������� �Ŀ���
	cout << lbs << " �Ŀ��� " << stone
		<< " ����, " << pounds << " �Ŀ���Դϴ�.\n";
	return 0;
}