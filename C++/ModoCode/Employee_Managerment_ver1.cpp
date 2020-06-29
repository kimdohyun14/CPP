#include <iostream>
#include <string>

// Employee Ŭ������ EmployeeList Ŭ����

class Employee
{
	std::string name;
	int age;

	std::string position;
	int rank;

public:
	Employee(std::string name, int age, std::string position, int rank)
		:name(name), age(age), position(position), rank(rank) {}

	// ���� ������
	Employee(const Employee& employee)
	{
		name = employee.name;
		age = employee.age;
		position = employee.position;
		rank = employee.rank;
	}

	Employee() {}

	void print_info()
	{
		std::cout << name << " (" << position << " , " << age << ") ==>" 
			<< calculate_pay() << "����" << std::endl;
	}

	int calculate_pay()
	{
		return 200 + rank * 50;
	}
};

class EmployeeList
{
	int alloc_employee;
	int current_employee;
	Employee** employee_list; // ���� ������

public:
	EmployeeList(int alloc_employee) : alloc_employee(alloc_employee)
	{
		employee_list = new Employee * [alloc_employee];
		current_employee = 0;
	}

	void add_employee(Employee* employee)
	{
		if (current_employee >= alloc_employee)
		{
			Employee** pre_list = employee_list;
			
			alloc_employee *= 2;
			employee_list = new Employee * [alloc_employee];
			for (int i = 0; i < current_employee; i++)
				employee_list[i] = pre_list[i];

			delete[] pre_list;
		}

		employee_list[current_employee] = employee;
		current_employee++;
	}

	int current_employee_num()
	{
		return current_employee;
	}

	void print_employee_info()
	{
		int total_pay = 0;
		for (int i = 0; i < current_employee; i++)
		{
			employee_list[i]->print_info();
			total_pay += employee_list[i]->calculate_pay();
		}

		std::cout << "�� ���: " << total_pay << "����" << std::endl;
	}

	~EmployeeList()
	{
		for (int i = 0; i < current_employee; i++)
			delete employee_list[i];

		delete[] employee_list;
	}
};

int main()
{
	EmployeeList emp_list(2);
	emp_list.add_employee(new Employee("��ȫö", 34, "����", 1));
	emp_list.print_employee_info(); std::cout << std::endl;
	emp_list.add_employee(new Employee("����", 34, "����", 1));
	emp_list.print_employee_info(); std::cout << std::endl;
	emp_list.add_employee(new Employee("���缮", 41, "����", 7));
	emp_list.print_employee_info(); std::cout << std::endl;
	emp_list.add_employee(new Employee("������", 43, "����", 4));
	emp_list.print_employee_info(); std::cout << std::endl;
	emp_list.add_employee(new Employee("�ڸ��", 43, "����", 5));
	emp_list.print_employee_info(); std::cout << std::endl;
	emp_list.add_employee(new Employee("������", 36, "�븮", 2));
	emp_list.print_employee_info(); std::cout << std::endl;
	emp_list.add_employee(new Employee("��", 36, "����", -2));
	emp_list.print_employee_info(); std::cout << std::endl;
	return 0;
}