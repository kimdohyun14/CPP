#include <iostream>
#define ZERO 0
#include <climits>

// �����÷ο�� ����÷ο��� �������� ����
// ǥ���� �� �ִ� �Ѱ踦 �����, �� ǥ�� ������ �ݴ��������� �ٽ� �����ϰ� �ȴ�.
int main()
{
	using namespace std;
	short Dohee = SHRT_MAX;       // ���� ǥ���� �����ϴ�.
	unsigned short Insuk = Dohee; // ������ ǥ���� �� ����.

	cout << "���� ���� : " << Dohee << ", ";
	cout << "�μ� ���� : " << Insuk << endl;
	cout << "�� ���¿� 1���� �߰� �Ա� ����" << endl << endl;

	Dohee += 1; // �����÷ο� �߻�!
	Insuk += 1;
	cout << "���� ���� : " << Dohee << ", ";
	cout << "�μ� ���� : " << Insuk << endl << endl;

	cout << "��� ���� 0���� �ǵ��� �� �� ���¿��� 1���� ���� ����" << endl;

	Dohee = ZERO;
	Insuk = ZERO;
	cout << "���� ���� : " << Dohee << ", ";
	cout << "�μ� ���� : " << Insuk << endl;

	Dohee -= 1;
	Insuk -= 1; // ����÷ο� �߻�!
	cout << "���� ���� : " << Dohee << ", ";
	cout << "�μ� ���� : " << Insuk << endl;
	return 0;
}