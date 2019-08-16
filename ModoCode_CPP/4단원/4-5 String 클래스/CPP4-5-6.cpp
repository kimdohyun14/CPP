// ũ�� �� �Լ� compare
// 'ũ��'�� ���Ѵٴ� �ǹ̴� ���������� �迭�ؼ� � ���ڿ��� �� �ڿ� ������ �Ǵ�
// ���ڿ� ��ü�� �����ϴ� �Լ������, ���� C ���� strcmp �Լ�
#include <iostream>
#include <cstring>
#include <algorithm>

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

	// loc�� �ش���ġ�� ���� ���� �ǹ�, num�� ����� ������ ���� �ǹ�
	MyString& erase(int loc, int num);

	//find_from�������� �����ؼ� ���� ù ��° str�� ��ġ�� �����ϰ� �ȴ�.
	int find(int find_from, MyString& str) const;
	int find(int find_from, const char* str) const;
	int find(int find_from, char c) const;

	int compare(const MyString& str) const;
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

MyString& MyString::erase(int loc, int num) {

	// loc�� �պ��� �����ؼ� num���� ���ڸ� �����.
	if (num < 0 || loc < 0 || loc > string_length)
		return *this;

	// ����ٴ� ���� �ܼ��� ���� ���ڵ��� ������ ���� �´ٰ� ��������.
	for (int i = loc + num; i < string_length; ++i) {
		string_content[i - num] = string_content[i];
	}
	// -> string_length�� �����ؼ� �ڿ� ��� ������ ������ ���� �Ű��� �Ƚᵵ �ȴ�.
	// ������ ���ڵ��� ���� ���鼭 ���� ���ڵ��� �ʱ�ȭ ���� �ʾ�����
	// string_length ���� ó���߱� ������ ���� ���ڵ鿡 �Ű� ���� �ʾƵ� �ȴ�.
	string_length -= num;
	return *this;
}

int MyString::find(int find_from, MyString& str) const {
	int i, j;
	if (str.string_length == 0) return -1;
	for (i = find_from; i < string_length - str.string_length; ++i) {
		// find_from���� �����ؼ� string_content�� str�� �Ϻ��� ��ġ�Ѵٸ�
		// �� ��ġ�� �����ϰ�, ã�� ���� ��� -1�� �����Ѵ�.
		for (j = 0; j < str.string_length; ++j) {
			if (string_content[i + j] != str.string_content[j])
				break; // �ϳ��� �ٸ� �κ��� �ִٸ� ����.
		}

		if (j == str.string_length)
			return i;
	}
	return -1; // ã�� ������.
}

int MyString::find(int find_from, const char* str) const {
	MyString temp(str);
	return find(find_from, temp);
}

int MyString::find(int find_from, char c) const {
	MyString temp(c);
	return find(find_from, temp);
}

int MyString::compare(const MyString& str) const {
	// (*this) - (str) �� �����ؼ� �� 1, 0, -1 �� �� ����� �����Ѵ�.
	// 1�� (*this)�� ���������� �� �ڿ� �´ٴ� �ǹ�
	// 0�� �� ���ڿ��� ���ٴ� �ǹ�
	// -1�� (*this)�� ���������� �� �տ� �´ٴ� �ǹ�

	for (int i = 0; i < std::min(string_length, str.string_length); ++i) {
		if (string_content[i] > str.string_content[i])
			return 1;
		else if (string_content[i] < str.string_content[i])
			return -1;
	}

	// ���� ���� �ߴµ� ������ �ʾҴٸ� �� �κ� ���� ��� �Ȱ��� ���̹Ƿ�
	// ���� ���ڿ� ���̰� ���ٸ� �� ���ڿ��� �ƿ� ���� ���ڿ��� �ȴ�.
	if (string_length == str.string_length) return 0;

	// abd �� abcd �� ũ�� �񱳴� abcd �� �� �ڿ� ���� �ȴ�.
	else if (string_length > str.string_length)
		return 1;
	else
		return -1;
}

int main() {
	MyString str1("abcdef");
	MyString str2("abcde");

	// ������� 1�� ���´ٴ� �ǹ̴�
	// str1�� str2���� ���������� �ڿ� �ִٴ� ���̴�.
	std::cout << "str1 and str2 compare : " << str1.compare(str2) << std::endl;
	return 0;
}

/* ���� ���� ��� �������̽� */

// 1. ���� Ȥ�� ���ڿ��� ������ �� �ִ� �����ڿ� ���� ������
// 2. ���ڿ��� ���̸� �����ϴ� �Լ� (length)
// 3. ���ڿ� ���� �Լ� (assign)
// 4. ���ڿ� �޸� �Ҵ� �Լ� (reserve) �� ���� �Ҵ�� ũ�⸦ �˾ƿ��� �Լ�(capacity)
// 5. Ư�� ��ġ�� ���ڸ� �����ϴ� �Լ� (at)
// 6. Ư�� ��ġ�� Ư�� ���ڿ��� �����ϴ� �Լ�(insert)
// 7. Ư�� ��ġ�� Ư�� ������ ���ڸ� ����� �Լ�(erase)
// 8. Ư�� ��ġ�� �������� Ư�� ���ڿ��� �˻��ϴ� �Լ�(find)
// 9. �� ���ڿ��� ������ ���ϴ� �Լ�(compare)


