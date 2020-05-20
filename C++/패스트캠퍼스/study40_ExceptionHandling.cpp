#include <iostream>
using namespace std;

// ����

	/* ����(Exception)�� ���α׷��� �����ϴ� �������� �߻��ϴ� ����ġ ���� ����(Error)�� �ǹ��Ѵ�.
	   C++������ �߻��� ���ɼ��� ���� ������ ���ؼ� ���� ó��(Exception Handling)�� �� �� �ֵ��� ���ش�.
	*/

// ���� ó�� ����

	/* C++�� Try - Catch ������ �̿��ؼ� ���� ó���� ������ �� �ֵ��� �Ѵ�.
	
	   - try   : Ư���� �ڵ� ��Ͽ��� ���ܰ� �߻��� �� ������ ���
	   - catch : �߻��� ���ܿ� ���ؼ� �ڵ鷯�� Ư���� ������ ó���Ѵ�.
	   - throw : try�������� �߻��� ������ �����Ѵ�.
	*/

int main()
{
	int a = 7, b = 0;
	try
	{
		if (b == 0)
		{
			throw "0���� ���� �� �����ϴ�.";
		}
		cout << a / b << endl;
	}
	catch (const char* str)
	{
		cout << str << endl;
	}
	return 0;
}