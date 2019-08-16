// explicit, mutable �� ���ؼ� �˾ƺ���.
// explicit��  C++���� ������ �ʴ� �Ͻ��� ��ȯ�� �� �� ������ �����Ϸ����� ���
// explicit�� ����ϸ� �� �����ڸ� �̿��� �Ͻ��� ��ȯ�� �Ұ����ϴ�.
#include <iostream>

class MyString {
	char* string_content; // ���ڿ� �����͸� ����Ű�� ������
	int string_length;    // ���ڿ� ����

	int memory_capacity;  // �Ҵ��� ũ��

public:
	// capacity ��ŭ �̸� �Ҵ��Ѵ�. (explicit Ű���� ���)
	explicit MyString(int capacity); 

	// ���ڿ��κ��� ����
	MyString(const char* str);

	// ���� ������
	MyString(const MyString& str);

	// �Ҹ���
	~MyString();

	int length() const;
};

MyString::MyString(int capacity) {
	string_content = new char[capacity];
	string_length = 0;
	memory_capacity = capacity;
}

MyString::MyString(const char* str) {
	string_length = 0;
	while(str[string_length++]) { }

	string_content = new char[string_length];
	memory_capacity = string_length;

	// ���ڿ� ����
	for (int i = 0; i != string_length; ++i)
		string_content[i] = str[i];
}

MyString::MyString(const MyString& str) {
	string_length = str.string_length;
	string_content = new char[string_length];

	for (int i = 0; i != string_length; ++i)
		string_content[i] = str.string_content[i];

	memory_capacity = string_length;
}

MyString::~MyString() {
	delete[] string_content;
}

int MyString::length() const {
	return string_length;
}

int main() {
	MyString s(3); // MyString(int capacity)�� ���� �����Ѵ�.
}

// explicit Ű���带 �̿��ϸ� �Ͻ��� ��ȯ�� ���� �� �ִ�.
// MyString s(3);  ���
// MyString s = 3; ������ ����