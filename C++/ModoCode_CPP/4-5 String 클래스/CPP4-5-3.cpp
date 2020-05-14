// ���ڿ� �����ϱ� (insert)
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

	// �Է� ��ġ�� �޴� ���, �� �Է� ��ġ '��'�� ���ڸ� insert�Ѵ�.
	MyString& insert(int loc, const MyString& str);
	MyString& insert(int loc, const char* str);
	MyString& insert(int loc, char c);
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

char MyString::at(int i) const {
	if (i >= string_length || i < 0)
		return NULL;
	else
		return string_content[i];
}

MyString& MyString::insert(int loc, const char* str) {
	MyString temp(str);
	return insert(loc, temp);
}

MyString& MyString::insert(int loc, char c) {
	MyString temp(c);
	return insert(loc, temp);
}

MyString& MyString::insert(int loc, const MyString& str) {
	// i�� ��ġ �ٷ� �տ� ���ڸ� �����ϰ� �ȴ�.
	// abc ��� ���ڿ��� insert(1, 'd') -> adbc

	// ������ ����� �Է¿� ���ؼ��� �������� �ʴ´�.
	if (loc<0 || loc > string_length) return *this;

	if (string_length + str.string_length > memory_capacity) {
		// ���Ӱ� �������� �Ҵ��ؾ� �Ѵ�.

		/* �����Ҵ� ����ȭ */
		// memory_capacity = string_length + str.string_length;
		// ���� �Ҵ��ؾ� �� �޸� ũ�� (string_length + str.string_length)�� 
		// memory_capacity�� �� �� ���϶��, memory_capacity�� �� ��� �Ҵ��Ѵ�.
		if (memory_capacity * 2 > string_length + str.string_length)
			memory_capacity *= 2;
		else
			memory_capacity = string_length + str.string_length;

		char* prev_string_content = string_content;
		string_content = new char[memory_capacity];

		//�ϴ� insert �Ǵ� �κ� ���������� ������ �����Ѵ�.
		int i;
		for (i = 0; i < loc; ++i) {
			string_content[i] = prev_string_content[i];
		}

		//�׸��� ���Ӱ� insert�Ǵ� ���ڿ��� �ִ´�.
		for (int j = 0; j != str.string_length; ++j) {
			string_content[i + j] = str.string_content[j];
		}

		//���� �ٽ� ���� ���� ���ڿ��� ������ �޺κ��� �����Ѵ�.
		for (; i < string_length; ++i) {
			string_content[str.string_length + i] = prev_string_content[i];
		}

		delete[] prev_string_content;

		string_length = string_length + str.string_length;
		return *this;
	}

	// ���� �ʰ����� �ʴ� ��� ���� �����Ҵ��� �� �ʿ䰡 ����.
	// ȿ�������� insert�ϱ� ����, �и��� �κ��� ���� �ڷ� �о������.

	for (int i = string_length - 1; i >= loc; --i) {
		// �ڷ� �б�. �� �� ������ ���ڿ� �����Ͱ� ������� �ʰ��Ѵ�.
		string_content[i + str.string_length] = string_content[i];
	}

	// �׸��� insert �Ǵ� ���� �ٽ� ����ֱ�
	for (int i = 0; i < str.string_length; ++i) {
		string_content[i + loc] = str.string_content[i];
	}

	string_length = string_length + str.string_length;
	return *this;
}

int main() {
	MyString str1("very very very long string");
	MyString str2("<some string inserted between>");
	str1.reserve(30);

	std::cout << "Capacity : " << str1.capacity() << std::endl;
	std::cout << "String length : " << str1.length() << std::endl;
	str1.println();

	str1.insert(5, str2);
	std::cout << "Capacity : " << str1.capacity() << std::endl;
	std::cout << "String length : " << str1.length() << std::endl;
	str1.println();
	return 0;
}


