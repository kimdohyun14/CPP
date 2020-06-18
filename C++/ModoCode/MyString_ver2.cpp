#include <iostream>
#include <cstring>

class MyString
{
	char* string_content;
	int string_length;
	int memory_capacity;  // 할당된 공간

public:
	MyString(char c);
	MyString(const char* str);
	MyString(const MyString& str);

	~MyString();

	int length() const;
	int capacity() const;
	void reserve(int size);

	void print() const;
	void println() const;

	MyString& assign(const MyString& str);
	MyString& assign(const char* str);
};

MyString::MyString(char c)
{
	string_content = new char[1];
	string_content[0] = c;
	string_length = 1;
	memory_capacity = 1;
}

MyString::MyString(const char* str)
{
	string_length = strlen(str);
	memory_capacity = string_length;
	string_content = new char[string_length];

	for (int i = 0; i != string_length; i++)
		string_content[i] = str[i];
}


MyString::MyString(const MyString& str)
{
	string_length = str.string_length;
	memory_capacity = string_length;
	string_content = new char[string_length];

	for (int i = 0; i != string_length; i++)
		string_content[i] = str.string_content[i];
}


MyString::~MyString()
{
	delete[] string_content;
}

int MyString::length() const
{
	return string_length;
}

void MyString::print() const
{
	for (int i = 0; i != string_length; i++)
		std::cout << string_content[i];
}

void MyString::println() const
{
	for (int i = 0; i != string_length; i++)
		std::cout << string_content[i];

	std::cout << std::endl;
}

MyString& MyString::assign(const MyString& str)
{
	if (str.string_length > memory_capacity)
	{
		// 이러면 다시 할당해줘야 한다.
		delete[] string_content;

		string_content = new char[str.string_length];
		memory_capacity = str.string_length;
	}

	for (int i = 0; i != str.string_length; i++)
		string_content[i] = str.string_content[i];

	/* 중요한 점
	   
	   굳이 str.string_length + 1  ~ string_length 부분은 초기화 시킬 필요가 없다.
	   왜냐하면 거기 까지는 읽어들이지 않기 때문이다.
	*/

	string_length = str.string_length;

	return *this;
}

MyString& MyString::assign(const char* str)
{
	int str_length = strlen(str);
	if (str_length > memory_capacity)
	{
		delete[] string_content;

		string_content = new char[str_length];
		memory_capacity = str_length;
	}

	for (int i = 0; i != str_length; i++)
		string_content[i] = str[i];

	string_length = str_length;

	return *this;
}

int MyString::capacity() const
{
	return memory_capacity;
}

void MyString::reserve(int size)
{
	if (size > memory_capacity)
	{
		char* prev_string_content = string_content;

		string_content = new char[size];
		memory_capacity = size;

		for (int i = 0; i != string_length; i++)
			string_content[i] = prev_string_content[i];

		delete[] prev_string_content;
	}

	// 만일 예약하려는 size 가 현재 capacity 보다 작다면
	// 아무것도 안해도 된다. 오히려 하면 비효율적인 비용이 발생.
}

int main()
{
	MyString str1("very very very long string");
	str1.reserve(30);

	std::cout << "Capacity : " << str1.capacity() << std::endl;
	std::cout << "String length : " << str1.length() << std::endl;
	str1.println();
	return 0;
}