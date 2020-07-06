#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	// ��� : ������ �ʴ� ��. ���� �� �� �����ϸ� �ٲ� �� ����.
	// ����� ����� ���ÿ� ���� �����صξ�� �Ѵ�.
	// �밡���� ǥ���(�տ� �������� �˾ƺ� �� �ְ� ǥ���Ѵ�.)
	// 16���� 8�ڸ��� 32��Ʈ�� ����. 1�ڸ��� 4��Ʈ, int�� 32��Ʈ
	const int iAttack = 0x00000001;   //     1 (2����)
	const int iArmor = 0x00000002;    //    10
	const int iHP = 0x00000004;       //   100
	const int iMP = 0x00000008;       //  1000
	const int iCritical = 0x00000010; // 10000

	// 1 | 100 = 101
	// 101 | 10000 = 10101
	// ������ �߰��� ���� OR������ �̿��ؼ� �߰��Ѵ�.
	int iBuf = iAttack | iHP | iCritical;

	// ������ ����� : �����ڸ� �ٿ��� ����� �� �ִ�.
	// �Ʒ��� Ǯ� ���� iBuf = iBuf & iHP;
	// 10101 ^ 00100 = 10001
	// HP ������ ������� ���� �� �ִ�.
	iBuf ^= iHP;

	// 10001 ^ 00100 = 10101. �ٽ� HP ������ �����.
	// XOR ������ �̿��ؼ� ��ġ ����ġ ����ó�� �ִ� �� �� �ִ�.
	iBuf ^= iHP;

	// 10101 & 00001 = 00001 = 1 (Attack�� �ִٴ� ���� �� �� �ִ�.)
	cout << "Attack : " << (iBuf & iAttack) << endl;
	// 10101 & 00000 = 0
	cout << "Armor : " << (iBuf & iArmor) << endl;
	cout << "HP : " << (iBuf & iHP) << endl;
	cout << "MP : " << (iBuf & iMP) << endl;
	cout << "Critical : " << (iBuf & iCritical) << endl;

	/*
	����Ʈ ������ : <<, >> �� �� ���� �����Ͽ� ������ ������ �ȴ�.
	�� ������ ���� ������ ������ ������ �ϰ� �ȴ�.
	���� ���ϱ�
	20 << 2 = 80
	20 << 3 = 160
	20 << 4 = 320
	20�� 2������ ��ȯ�Ѵ�.
	10100
	1010000
	10100000
	101000000

	���� ������(2^n �´����� �����⸦ �ϰ��� �� ��)
	20 >> 2 = 5
	20 >> 3 = 2
	10100
	101
	10
	*/

	// ������ �޸𸮰� �������� ���������� 4����Ʈ�� �ɰ���, 
	// ���� 16��Ʈ ���� 16��Ʈ�� ����Ͽ���.
	int iHigh = 187;
	int iLow = 13560;
	int iNumber = iHigh;

	// iNumber���� 187�� ���ִ�.
	// �� ���� <- �� �������� 16��Ʈ �̵���Ű��,
	// ���� 16��Ʈ�� ���� ���� �ȴ�.
	iNumber <<= 16;

	// ���� 16��Ʈ�� ä���.
	iNumber |= iLow;

	// High ���� ����Ѵ�.
	cout << "High : " << (iNumber >> 16) << endl;
	// Low ���� �����Ѵ�.
	cout << "Low : " << (iNumber & 0x0000ffff) << endl;

	// ���������� : ++, -- 1����, 1����
	iNumber = 10;

	// ��ġ(����)
	++iNumber;

	// ��ġ(����)
	iNumber++;

	cout << ++iNumber << endl;
	cout << iNumber++ << endl;
	cout << iNumber << endl;

	/*
	�б⹮���� ũ�� 2���� ������ �ִ�. if��, switch���� ����.
	if�� : ������ üũ���ִ� ����̴�.
	���� : if(���ǽ�) {}(�߰�ȣ, �ڵ��)
	if���� ���ǽ��� true�� �� ���, �ڵ�� ���� �ڵ尡 ���۵ȴ�.
	false�� ��쿡�� ���۵��� �ʴ´�.
	*/
	if (false)
	{
		cout << "if�� ������ true" << endl;
	}

	// ������ �ִ��� Ȯ���Ѵ�.
	if ((iBuf & iAttack) != 0)
	{
		cout << "Attack ������ �ֽ��ϴ�." << endl;
	}

	// if�� �Ʒ��� �� �ڵ尡 1���� ��� {}(�ڵ��)�� ������ �� �ִ�.
	// ������ �켱���� ������ �Ұ�ȣ�� ���� �����ش�.
	if ((iBuf & iArmor) != 0)
		cout << "Armor ������ �ֽ��ϴ�." << endl;

	if ((iBuf & iHP) != 0)
		cout << "HP������ �ֽ��ϴ�." << endl;

	if ((iBuf & iMP) != 0)
		cout << "MP������ �ֽ��ϴ�." << endl;

	if ((iBuf & iCritical) != 0)
		cout << "Critical������ �ֽ��ϴ�." << endl;

	/*
	else : if���� �ݵ�� ���� ����� �Ǿ�� �Ѵ�.
	if�� ������ false�� ��� else�� �ִٸ� else ���� ���� �ڵ尡 ���۵ȴ�.

	else if : if���� �ݵ�� ���� ����� �Ǿ�� �Ѵ�.
	if�� �Ʒ� �;� �ϰ� else���ٴ� ���� �־�� �Ѵ�. (�߰��ܰ�)
	else if�� �ڽ��� ���� �ִ� ���ǽ��� false�� ��� ���� else if�� ���ǽ��� üũ�Ѵ�.
	else if�� ��� ����� �����ϴ�.
	*/
	if (false)
		cout << "if�� ������ true�Դϴ�." << endl;
	else
		cout << "if�� ������ false�Դϴ�." << endl;

	cout << "���ڸ� �Է��ϼ��� : ";
	cin >> iNumber;

	if (10 <= iNumber && iNumber <= 20)
		cout << "10 ~ 20 ������ �����Դϴ�." << endl;
	else if (21 <= iNumber && iNumber <= 30)
		cout << "21 ~ 30 ������ �����Դϴ�." << endl;
	else if (31 <= iNumber && iNumber <= 40)
		cout << "31 ~ 40 ������ �����Դϴ�." << endl;
	else
		cout << "�� ���� �����Դϴ�." << endl;

	// ���� �߻�
	srand((unsigned int)time(0)); // ���� ���̺��� �߻�
	
	// rand�� �� ���������ۿ� �� ���´�.
	// �̷��� ������ ���� �˰����� ���� ���� ����ϰ� �ȴ�.
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;
	cout << (rand() % 100) << endl;            // 0 ~ 99
	cout << (rand() % 101 + 100) << endl;      // 100 ~ 200
	cout << (rand() % 10000 / 100.f) << endl;  // 0 ~ 99.99
	cout << (rand() % 10000 / 100.0f) << endl; // 0 ~ 99.99

	int iUpgrade = 0;
	cout << "Upgrade �⺻ ��ġ�� �Է��ϼ��� : ";
	cin >> iUpgrade;

	// ��ȭ Ȯ���� ���Ѵ�.
	float fPercent = rand() % 10000 / 100.f;

	// ��ȭ Ȯ�� : ���׷��̵尡 0 ~ 3 :    100%
	//             ���׷��̵尡 4 ~ 6 :     40%
	//             ���׷��̵尡 7 ~ 9 :     10%
	//             ���׷��̵尡 10 ~ 13 :    1%
	//             ���׷��̵尡 14 ~ 15 : 0.01%
	cout << "Upgrade : " << iUpgrade << endl; // �� ������ �����ϴ���?
	cout << "Percent : " << fPercent << endl; // �� ����  ���� Ȯ����?

	if (iUpgrade <= 3)
		cout << "��ȭ ����" << endl;

	else if(4 <= iUpgrade && iUpgrade <= 6)
	{
		if (fPercent < 40.f)
			cout << "��ȭ ����" << endl;
		else
			cout << "��ȭ ����" << endl;
	}

	else if (7 <= iUpgrade && iUpgrade <= 9)
	{
		if (fPercent < 10.f)
			cout << "��ȭ ����" << endl;
		else
			cout << "��ȭ ����" << endl;
	}

	else if (10 <= iUpgrade && iUpgrade <= 13)
	{
		if (fPercent < 1.f)
			cout << "��ȭ ����" << endl;
		else
			cout << "��ȭ ����" << endl;
	}

	else if (14 <= iUpgrade && iUpgrade <= 15)
	{
		if (fPercent < 0.01f)
			cout << "��ȭ ����" << endl;
		else
			cout << "��ȭ ����" << endl;
	}

	return 0;
}