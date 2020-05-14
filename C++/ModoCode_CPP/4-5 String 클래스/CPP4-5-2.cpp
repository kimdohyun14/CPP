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
	int memory_capacity;   //���� �Ҵ�� �޸� ������ ũ�⸦ ��Ÿ��.
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

	//���� �Ҵ�� �޸� ������ ũ�⸦ ��ȯ
	int capacity() const;
	//�Ҵ��� ���ڿ��� ũ�⸦ �̸� �����س��� �Լ�
	void reserve(int size);
    //Ư�� ��ġ�� ���ڸ� ��� �Լ�
	char at(int i) const;
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

int MyString::length() const {
	return string_length;
}

void MyString::print() const {
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
	if (str.string_length > memory_capacity) {
		//�ٽ� �Ҵ��� ����߸� �Ѵ�.
		delete[] string_content;

		string_content = new char[str.string_length];
		memory_capacity = str.string_length;
	}

	for (int i = 0; i != str.string_length; ++i) {
		string_content[i] = str.string_content[i];
	}

	string_length = str.string_length;

	return *this;
}

MyString& MyString::assign(const char* str) {
	int str_length = strlen(str);
	if (str_length > memory_capacity) {
		//�ٽ� �Ҵ��� ����߸� �Ѵ�.
		delete[] string_content;

		string_content = new char[str_length];
		memory_capacity = str_length;
	}

	for (int i = 0; i != str_length; ++i) {
		string_content[i] = str[i];
	}

	string_length = str_length;

	return *this;
}

int MyString::capacity() const {
	return memory_capacity;
}

void MyString::reserve(int size) {
	//�Ҵ�Ǵ� ũ�Ⱑ �������� ũ�ٸ� �ٽ� �Ҵ�
	if (size > memory_capacity) {
		char* prev_string_content = string_content;

		string_content = new char[size];
		memory_capacity = size;

		for (int i = 0; i != string_length; ++i) {
			string_content[i] = prev_string_content[i];
		}
		
		delete[] prev_string_content;
	}

	// ���� �����Ϸ��� size�� ���� capacity���� �۴ٸ�
	// �ƹ��͵� ���ص� �ȴ�.
}

char MyString::at(int i) const{
	if (i >= string_length || i < 0)
		return NULL;
	else
		return string_content[i];
}

int main() {
	MyString str1("very very very long string");
	str1.reserve(30);

	std::cout << "Capacity : " << str1.capacity() << std::endl;
	std::cout << "String length : " << str1.length() << std::endl;
	str1.println();
	return 0;
}


//�⺻���� �Լ��� �����ߴ�. �����ϸ� ������ ����.

// 1. ���� Ȥ�� ���ڿ��� ������ �� �ִ� �����ڿ� ���� ������
// 2. ���ڿ��� ���̸� �����ϴ� �Լ� (length)
// 3. ���ڿ� ���� �Լ� (assign)
// 4. ���ڿ� �޸� �Ҵ� �Լ�(reserve) �� ���� �Ҵ�� ũ�⸦ ��ȯ�ϴ� �Լ�(capacity)
// 5. Ư�� ��ġ�� ���ڸ� �����ϴ� �Լ� (at)


