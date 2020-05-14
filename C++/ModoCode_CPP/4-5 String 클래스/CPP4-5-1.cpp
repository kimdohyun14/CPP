//���� ����� ���ڿ� Ŭ����
//1. ���ڷκ����� ���ڿ� ����, C ���ڿ� (char*)�� ������ ����
//2. ���ڿ� ���̸� ���ϴ� �Լ�
//3. ���ڿ� �ڿ� �ٸ� ���ڿ� ���̱�
//4. ���ڿ� ���� ���ԵǾ� �ִ� ���ڿ� ���ϱ�
//5. ���ڿ��� ������ ��
//6. ���ڿ� ũ�� �� (������)

//MyString Ŭ�������� ��� ������ �ʿ��� �͵�
//* ���ڿ� �����Ͱ� ����� ������ ����Ű�� ������
//* ���ڿ� �������� ����
#include <iostream>
#include <cstring>

class MyString {
	char* string_content;  //���ڿ� �����͸� ����Ű�� ������
	int string_length;     //���ڿ� ����

public:
	//���� �ϳ��� ����
	MyString(char c);

	//���ڿ��� ���� ����
	MyString(const char* str);

	//���� ������
	MyString(const MyString& str);

	//assign �Լ�
	//�����ϴ� ��� ���� ������ �Լ�
	//'='�� ������ ������ �Ѵ�.
	MyString& assign(const MyString& str);
	MyString& assign(const char* str);

	//�Ҹ���
	~MyString();

	int length() const;

	void print() const;
	void println() const;
};

// (�� ���� ���ڿ�)�� �� ���� '����'�� �����Ѵ�.
// ���� : ���� ���ڿ��� ���̸� ������ string_length�� �ֱ� ������

MyString::MyString(char c) {
	string_content = new char[1];
	string_content[0] = c;
	string_length = 1;
}

//���� ��� ������ ���� �ٲ��� �ʴ´ٸ� �Լ��� ����� ��������.
MyString::MyString(const char* str) {
	string_length = strlen(str);
	string_content = new char[string_length];

	for (int i = 0; i < string_length; ++i) {
		string_content[i] = str[i];
	}
}

//���� ������
MyString::MyString(const MyString& str) {
	string_length = str.string_length;
	string_content = new char[string_length];
	for (int i = 0; i < string_length; ++i) {
		string_content[i] = str.string_content[i];
	}
}

MyString::~MyString() {
	delete[] string_content;
}

int MyString::length() const{
	return string_length;
}

void MyString::print() const{
	for (int i = 0; i < string_length; ++i) {
		std::cout << string_content[i];
	}
}

void MyString::println() const {
	for (int i = 0; i < string_length; ++i) {
		std::cout << string_content[i];
	}
	std::cout << std::endl;
}

//���ڷ� ���� ���ڿ��� ũ�Ⱑ ������ ���ڿ��� ũ�⺸�� �۴ٸ� ���� �����Ҵ� x
MyString& MyString::assign(const MyString& str) {
	if (str.string_length > string_length) {
		//�ٽ� �Ҵ��� ����߸� �Ѵ�.
		delete[] string_content;

		string_content = new char[str.string_length];
	}

	for (int i = 0; i != str.string_length; ++i) {
		string_content[i] = str.string_content[i];
	}

	string_length = str.string_length;

	return *this;
}

MyString& MyString::assign(const char* str) {
	int str_length = strlen(str);
	if (str_length > string_length) {
		//�ٽ� �Ҵ��� ����߸� �Ѵ�.
		delete[] string_content;

		string_content = new char[str_length];
	}

	for (int i = 0; i != str_length; ++i) {
		string_content[i] = str[i];
	}

	string_length = str_length;

	return *this;
}

int main() {
	MyString str1("hello world!");
	MyString str2(str1);

	str1.println();
	str2.println();

	return 0;
}



