#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char animal[20] = "bear";
	const char* bird = "wren"; // ū����ǥ�� �ѷ����� ���ڿ��� �� ���ڿ��� ù ��° ������ �ּҸ� ��Ÿ����.
	char* ps;

	cout << animal << " and " << bird << endl;
	// cout << ps << endl; ������ �� �� ����.

	cout << "������ ������ �Է��ϼ���: ";
	cin >> animal; // �Է��� 20���� �̳����� �Ѵ�.
	// cin >> ps; ����� �ؼ��� �ȵǴ� �Ǽ�
	// ps�� ���Ե� ������ �����ϰ� ���� �ʱ� �����̴�.

	ps = animal; // �ּ� ����, ���� �޸� ��ġ�� ���� ���ڿ��� �����ϰ� �ȴ�.
	cout << ps << "s!\n";
	cout << "strcpy() �����:\n";
	// ���ڿ��� �ּҸ� �˰� �ʹٸ� �����͸� �ٸ� ������������ ��ȯ�ؾ� �Ѵ�.
	cout << (int*)animal << ": " << animal << endl;
	cout << (int*)ps << ": " << ps << endl;

	ps = new char[strlen(animal) + 1]; // �� �޸𸮸� �����Ѵ�.
	strcpy(ps, animal); // ���� ������ �� ���� "fox"�� ��� �ȴ�.
	cout << "strcpy() �����:\n";
	cout << (int*)animal << ": " << animal << endl;
	cout << (int*)ps << ": " << ps << endl;
	delete[] ps;
	return 0;
}