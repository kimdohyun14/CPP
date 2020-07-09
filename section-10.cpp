#include <iostream>
using namespace std;

#define NAME_SIZE	32

/*
����ü : �����ִ� �������� ��Ƽ� �ϳ��� ���ο� Ÿ���� ������ִ� ����̴�.
��������� ���� Ÿ���̴�.
���� : struct ����ü�� {};

�迭�� ����ü�� ������
1. �������� �����̴�.
2. ���ӵ� �޸� ���� �Ҵ�ȴ�. ����ü ������� ���ӵ� �޸� ������ ������ �ȴ�.
*/

// ����ü
struct _tagStudent
{
	// ��� ������
	char	strName[NAME_SIZE];
	int     iNumber;
	int     iKor;
	int		iEng;
	int		iMath;
	int		iTotal;
	float	fAvg;
};

int main()
{
	_tagStudent tStudent = {}; // ����ü ��ü�� 0���� �ʱ�ȭ�� �ȴ�. (����ü�� �ʱ�ȭ�� �����ָ� ������ ���� ���� �ȴ�.)
	_tagStudent tStudentArr[100] = {}; // �̷��� �迭�ε� ������ �����ϴ�.

	// ����ü ����� �����Ҷ��� . �� �̿��ؼ� �����ϰ� �ȴ�.
	tStudent.iKor = 100;

	//tStudent.strName = "adqwewq�����ٶ󸶹ٻ�";
	// ���ڿ��� �迭�� �־��� ������ �ܼ� �������δ� �Ұ����ϴ�.
	// strcpy_s ��� �Լ��� �̿��ؼ� ���ڿ��� ������ �־�� �Ѵ�.
	// �� �Լ��� �����ʿ� �ִ� ���ڿ��� �������� �������ش�.
	// �������� 0(NULL)���ڸ� �ڵ����� �־��ش�.
	// �ѱ��� �ϳ��� 2����Ʈ(2�� ���̷�)
	strcpy_s(tStudent.strName, "�����ٶ� asdf");

	cout << "�̸� ���� : " << strlen(tStudent.strName) << endl;

	// strcat_s �Լ��� ���ڿ��� �ٿ��ִ� ����̴�.
	// �����ʿ� �ִ� ���ڿ��� ���ʿ� �ٿ��ش�.
	// �������� 0(NULL)���ڸ� �ڵ����� �־��ش�.
	strcat_s(tStudent.strName, " ���ڿ� ���̱�");

	// strcmp �Լ��� �� ���ڿ��� ���Ͽ� ���� ��� 0�� ��ȯ�ϰ� �ٸ� ���
	// 0�� �ƴ� ���� ��ȯ�Ѵ�. (string compare)
	strcpy_s(tStudent.strName, "ȫ�浿");

	cout << "���� �̸��� �Է��ϼ��� : ";
	char	strName[NAME_SIZE] = {};
	cin >> strName;


	if (strcmp(tStudent.strName, strName) == 0)
	{
		cout << "�л��� ã�ҽ��ϴ�." << endl;
	}

	else
	{
		cout << "ã�� �л��� �����ϴ�." << endl;
	}

	// ���ڿ��� ���� �׻� 0(NULL)�� ������ �Ѵ�.
	// �׷��� �����Ⱚ�� ���ִ� ���¿��� �Ʒ�ó�� �� �迭 ��ҿ� ���� �־��ְ� �Ǹ� �� ���� ��µǰ�
	// �־����� ���� �κ��� �����Ⱚ���� �״�� ��µȴ�.
	// �ֳ��ϸ� ��µ� �� ���ڿ��� ���� �ν��� �� ���� �����̴�.
	tStudent.strName[0] = 'a';
	tStudent.strName[1] = 'b';
	tStudent.strName[2] = 0;
	

	cout << "�̸� : " << tStudent.strName << endl;
	cout << "�й� : " << tStudent.iNumber << endl;
	cout << "���� : " << tStudent.iKor << endl;
	cout << "���� : " << tStudent.iEng << endl;
	cout << "���� : " << tStudent.iMath << endl;
	cout << "���� : " << tStudent.iTotal << endl;
	cout << "��� : " << tStudent.fAvg << endl;

	return 0;
}