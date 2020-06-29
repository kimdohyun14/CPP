#include <iostream>
#include <string>

// �ߺ��Ǵ� �ڵ带 ����� ���� �ذ��Ѵ�. (���뼺)
// �߰������� ���� �Լ��� ���ؼ� ����ϰ� �����Ѵ�.

// ����ϰ� ������, ������ Employee�� Manager(Employee�� ��ӹ���)�� �Ѵ� �����ϱ� ���ؼ�
// Manager** list; Employee** list; �� -> Employee** list�� �����ؼ� ����Ѵ�.
// ������ ������, virtual �Լ��� override �׸��� �� �ɽ������� �ȴ�.

class Employee
{
protected:
	std::string name;
	int age;

	std::string position;
	int rank;

public:
	Employee(std::string name, int age, std::string position, int rank)
		:name(name), age(age), position(position), rank(rank) {}

	Employee(const Employee& employee)
	{
		name = employee.name;
		age = employee.age;
		position = employee.position;
		rank = employee.rank;
	}

	Employee() { }

	virtual void print_info()
	{
		std::cout << name << " (" << position << " , " << age << ") ==> " << calculate_pay() << "����" << std::endl;
	}

	virtual int calculate_pay()
	{
		return 200 + rank * 50;
	}
};

class Manager : public Employee
{
	int year_of_service;

public:
	Manager(std::string name, int age, std::string position, int rank, int year_of_service)
		:year_of_service(year_of_service), Employee(name, age, position, rank) { }

	Manager(const Manager& manager)
		:Employee(manager.name, manager.age, manager.position, manager.rank)
	{
		year_of_service = manager.year_of_service;
	}

	Manager() : Employee() { }

	int calculate_pay() override
	{
		return 200 + rank * 50 + 5 * year_of_service;
	}

	void print_info() override
	{
		std::cout << name << " (" << position << " , " << age << ", " <<
			year_of_service << "����) ==> " << calculate_pay() << "����" << std::endl;
	}
};

class EmployeeList
{
	int alloc_employee;
	int current_employee;
	Employee** employee_list;  // ���� ������(Employee, Manager) �Ѵ� ����. �� ĳ�������� �ذ��� ����

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
			alloc_employee *= 2;
			Employee** prev_list = employee_list;

			employee_list = new Employee * [alloc_employee];
			for (int i = 0; i < current_employee; i++)
				employee_list[i] = prev_list[i];

			delete[] prev_list;
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

		std::cout << "�� ��� : " << total_pay << "����" << std::endl;
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
	EmployeeList emp_list(10);
	emp_list.add_employee(new Employee("��ȫö", 34, "����", 1));
	emp_list.add_employee(new Employee("����", 34, "����", 1));

	emp_list.add_employee(new Manager("���缮", 41, "����", 7, 12));
	emp_list.add_employee(new Manager("������", 43, "����", 4, 15));
	emp_list.add_employee(new Manager("�ڸ��", 43, "����", 5, 13));
	emp_list.add_employee(new Employee("������", 36, "�븮", 2));
	emp_list.add_employee(new Employee("��", 36, "����", -2));
	emp_list.print_employee_info();
	return 0;
}