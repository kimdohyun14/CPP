#include <iostream>

using namespace std;

// pp�� int* Ÿ���� p������ �ּҸ� ������ �ȴ�.
void Test(int** pp)
{
	*pp = new int;
}

int main()
{
	//int* p = NULL;
	//Test(&p);

	FILE* pFile = NULL;

	// 1�� ���� : ������ ����������, fopen_s�� call-by-address ����
	// 2�� ���� : ���� ����̴�. ������ �����Ǵ� ���� ��δ� ���� ������Ʈ�� �ִ� ���� �����̴�.
	// ���� �������Ϸ� �������� ��쿡�� �ش� exe ������ �ִ� ��θ� �������� �������ش�.
	// 3�� ���� : ���� ����̴�. ���� ũ�� 2������ ����
	// ���� �б�, ����, ������ �ְ� ���� ����, �ؽ�Ʈ ����, ���̳ʸ� ����
	// 2���� ��尡 �־ ���ļ� ����Ѵ�.
	// r : �б� w : ���� a : ���� t : �ؽ�Ʈ���� b : ���̳ʸ� ����

	/*
	fopen_s(&pFile, "summer.txt", "wt");

	if (pFile != NULL)
	{
		// fwrite, fread 2���� �Լ��� ����
		// fputs, fgets �� ����
		const char* pText = "abcd";
		// 1�� ���� : �����ϰ��� �ϴ� ���� �޸� �ּҸ� �־��ش�.
		// 2�� ���� : �����ϰ��� �ϴ� ���� ����Ÿ���� �޸� ũ�⸦ �־��ش�.
		// 3�� ���� : �����ϰ��� �ϴ� ���� ������ �־��ش�.
		// 4�� ���� : ������ ������ ��Ʈ���� �־��ش�.
		fwrite(pText, 1, 4, pFile);

		// ������ �������� �ݾ��ش�.
		fclose(pFile);

		cout << "���� ����� ����" << endl;
	}
	*/

	fopen_s(&pFile, "summer.txt", "rt");

	if (pFile)
	{
		char strText[5] = {};

		fread(strText, 1, 4, pFile);

		cout << strText << endl;

		fclose(pFile);

		cout << "���� ����� ����" << endl;
	}

	return 0;
}