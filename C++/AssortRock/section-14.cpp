#include <iostream>
using namespace std;

struct _tagStudent
{
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;
};

int main()
{
	/*
	������ : ����Ű��. �Ϲ� ������ �Ϲ����� ���� �����ϰ� ������,
	������ ������ �޸� �ּҸ� �����ϰ� �ȴ�. ��� ���� Ÿ���� ������ Ÿ���� ������ �� �ִ�.
	int������ �ּҴ� int ������ ������ ������ �ؾ��Ѵ�. (Ÿ���� ��Ű�� ������ ��Ȱ�� �����Ͱ� ��µ��� ���� �� �ִ�.)
	�����ʹ� �޸� �ּҸ� ��Ƴ��� �����̱� ������ x86���� ������ ���� ������ 4byte�� ���´�.
	x64�� ���� 8byte�� ���´�.

	�����ʹ� �ڱ� ������ �ƹ����ϵ� �� �� ����. �ݵ�� �ٸ� ������ �޸� �ּҸ� ������ �־�� ���� �� �� �ִµ�,
	������ �ִ� �� �޸� �ּҿ� �����ؼ� ���� ������ �� �ִ�.
	
	���� : ����Ÿ�� *������;
	*/
	int iNumber = 100;
	// ���� ����� *�� �ٿ��ָ� �ش� Ÿ���� ������ ������ ����ȴ�.
	// ���� �տ� &�� �ٿ��ָ� �ش� ������ �޸� �ּҰ� �ȴ�.
	// pNum�� iNumber ������ �޸� �ּҸ� ������ ���� �ȴ�.
	// �׷��Ƿ� pNum�� �̿��ؼ� iNumber�� ���� ������ �� �ְ� �ȴ�.
	int* pNum = &iNumber;

	// x86 => ��� 4����Ʈ, x64 => ��� 8����Ʈ
	cout << sizeof(int*) << endl;
	cout << sizeof(char*) << endl;
	cout << sizeof(double*) << endl;

	// pNum�� �̿��ؼ� iNumber�� ���� �����غ���.
	// �������� �̿��ؼ� ���� �����ų� ������ �� �ִ�.
	// �������� ������ ���� �տ� *�� ���̰� �Ǹ� �������� �ȴ�.
	cout << *pNum << endl;
	*pNum = 1234;

	cout << "iNumber Address : " << iNumber << endl;
	cout << "iNumber Address : " << &iNumber << endl;
	cout << "pNum Value : " << pNum << endl;
	// ������ ������ �����̱� ������ �ּҸ� ������ �ִ�.
	cout << "pNum Address : " << &pNum << endl;

	/*
	�����Ϳ� �迭�� ���� : �迭���� �������̴�. �迭�� ��ü�� �ش� �迭�� �޸𸮿����� ������ �ּҸ� �ǹ��Ѵ�.
	*/
	int iArray[10] = { 1,2,3,4,5,6,7,8,9,10 };
	cout << "Array Address : " << iArray << endl;
	cout << "Array Address : " << &iArray[0] << endl;

	int* pArray = iArray;

	cout << pArray[2] << endl;

	/*
	������ ���� : +, - ������ �����Ѵ�. ++, -- �� �����ѵ� 1�� �����ϰ� �Ǹ�
	�ܼ��� �޸� �ּҰ��� 1 �����ϴ� ���� �ƴ϶�, int �������� ��� int Ÿ���� �޸� �ּҸ� ���� �Ǵµ�
	�޸� �ּҿ� 1�� �����ָ� 1������ �ƴ� �ش� ������Ÿ���� ����Ÿ�� ũ�⸸ŭ �����ϰ� �ȴ�.
	int �������̹Ƿ� int�� ũ���� 4��ŭ ���� �����ϰ� �Ǵ� ���̴�.
	*/

	cout << pArray << endl;
	cout << pArray + 2 << endl;
	cout << *pArray << endl;
	cout << *(pArray + 2) << endl;
	cout << *pArray + 100 << endl; // ������ �켱���� ������, �������� �����ϰ� ����, 100�� ���ؼ� ����� 101�� �ȴ�.

	// ��� ���ڿ� (const) �ٲ� �� ���� ���ڿ��̴�.
	// �� ���ڿ��� ������ �� ���� ��ŭ�� ũ�⸦ ���� ������, �� ��� ���ڿ��� ������ �� �ִ� �迭�� ������,
	// �� �༮�� �޸� �ּҸ� ��ȯ���ش�.
	const char* pText = "�׽�Ʈ ���ڿ�"; 
	// �ٲ� �� ���� ���ڿ��� �ٲܷ��� �ϸ� �ȵȴ�.
	// pText[0] = 'a'; 

	// ���ڿ� ���
	cout << pText << endl;
	// ���ڿ� �ּ�
	cout << (int*)pText << endl;

	// ����Ű�� �ּҸ� ������ �� �ְ� �ȴ�.
	pText = "abcde";
	cout << pText << endl;
	cout << (int*)pText << endl;

	// �Ȱ��� �ٽ� ����Ű�� �ص�, ����Ű�� �ּҴ� �����ϰ� �ȴ�.
	pText = "abcde";
	cout << pText << endl;
	cout << (int*)pText << endl;

	// ���ڿ��� ������ �� �ִ� ���ڿ�
	char str[8] = "abcdefg";

	cout << str << endl;
	cout << (int*)str << endl;
	cout << (int*)&str[0] << endl;

	_tagStudent tStudent = {};

	tStudent.iKor = 100;
	cout << tStudent.iKor << endl;

	// ����ü ������
	_tagStudent* pStudent = &tStudent;

	// ������ �켱���� ������ .�� ���� �ν��ϰ� �ȴ�.�޸��ּ� .�� �߸��� �����̴�. 
	// �׷��Ƿ� �Ұ�ȣ�� ������ �Ŀ� .�� �̿��ؼ� ����Ű�� ����� ��������� �����ؾ� �Ѵ�.
	(*pStudent).iKor = 50;
	cout << tStudent.iKor << endl;

	// ���� ���� ��������� ������ ���� ����� �� �ִ�.
	// �޸��ּ� -> �� �̿��ؼ� ��Ű���� ����� ����� ������ �� �ִ�. (���� ���)
	pStudent->iKor = 80;
	cout << tStudent.iKor << endl;

	// void : Ÿ���� ����. void�� ������Ÿ���� Ȱ���� �� �ִ�.
	// void* ������ �����ϰ� �Ǹ� �� ������ � Ÿ���� �޸� �ּҵ� ��� ���尡���ϴ�.
	// ��, �������� �Ұ����ϰ� �޸� �ּҸ� ���� �����ϴ�.
	// ������ �޸� �ּҸ� �����ϱ� ���� ���۷� ����� �� �ִ�.
	void* pVoid = &iNumber;
	cout << "iNumber Address : " << &iNumber << endl;
	cout << "iNumber Address : " << pVoid << endl;

	// ����ȯ�� ���ؼ� �ּҰ��� ���� ������ ����Ѵ�.
	int* pConvert = (int*)pVoid;
	*pConvert = 10101010;
	cout << "iNumber : " << iNumber << endl;
	// �̷��Ե� ����� �����ϴ�.
	*((int*)pVoid) = 9999;
	cout << "iNumber : " << iNumber << endl;

	// ����ü ���� ����ȯ�� ���ؼ� �ּҰ��� ���� ������ ����� �����ϴ�.
	pVoid = &tStudent;
	cout << "tStudent Address : " << &tStudent << endl;
	cout << "tStudent Address : " << pVoid << endl << endl;

	int iNum1 = 1000;
	int iNum2 = 2000;
	pNum = &iNum1;
	// ���� ������ : *�� 2�� ���δ�.
	// �Ϲ� ������ ������ �Ϲ� ������ �޸� �ּҸ� �����ϴ� �������
	// ���� �����ʹ� �������� �������̴�. ��, ���� �����ʹ� ������ ������ �޸� �ּҸ� �����ϴ� �������̴�.
	int** ppNum = &pNum;

	*ppNum = &iNum2; // pNum�� value�� iNum2�� �ּҰ����� �ٲ۴�. (�����Ѵ�.)
	*pNum = 3000;

	cout << "iNum1 : " << iNum1 << endl;
	cout << "iNum1 Addr : " << &iNum1 << endl;
	cout << "iNum2 : " << iNum2 << endl;
	cout << "iNum2 Addr : " << &iNum2 << endl << endl;

	cout << "*pNum : " << *pNum << endl;
	cout << "pNum Value : " << pNum << endl; // ����Ű�� �ִ� ������ �ּҰ�
	cout << "pNum Addr : " << &pNum << endl << endl;

	cout << "**ppNum : " << **ppNum << endl;
	cout << "*ppNum : " << *ppNum << endl;     // pNum�� value
	cout << "ppNum Value : " << ppNum << endl; // &pNum
	cout << "ppNum Addr : " << &ppNum << endl;
	return 0;
}