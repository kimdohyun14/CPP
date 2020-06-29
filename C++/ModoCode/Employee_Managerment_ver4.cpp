#include <iostream>
#include <string>

// 중복되는 코드를 상속을 통해 해결한다. (재사용성)
// 추가적으로 가상 함수를 통해서 깔끔하게 정리한다.

// 깔금하게 정리란, 기존의 Employee와 Manager(Employee를 상속받은)을 둘다 관리하기 위해서
// Manager** list; Employee** list; 를 -> Employee** list로 정리해서 사용한다.
// 가능한 이유는, virtual 함수와 override 그리고 업 케스팅으로 된다.

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
		std::cout << name << " (" << position << " , " << age << ") ==> " << calculate_pay() << "만원" << std::endl;
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
			year_of_service << "년차) ==> " << calculate_pay() << "만원" << std::endl;
	}
};

class EmployeeList
{
	int alloc_employee;
	int current_employee;
	Employee** employee_list;  // 직원 데이터(Employee, Manager) 둘다 가능. 업 캐스팅으로 해결이 가능

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

		std::cout << "총 비용 : " << total_pay << "만원" << std::endl;
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
	emp_list.add_employee(new Employee("노홍철", 34, "평사원", 1));
	emp_list.add_employee(new Employee("하하", 34, "평사원", 1));

	emp_list.add_employee(new Manager("유재석", 41, "부장", 7, 12));
	emp_list.add_employee(new Manager("정준하", 43, "과장", 4, 15));
	emp_list.add_employee(new Manager("박명수", 43, "차장", 5, 13));
	emp_list.add_employee(new Employee("정형돈", 36, "대리", 2));
	emp_list.add_employee(new Employee("길", 36, "인턴", -2));
	emp_list.print_employee_info();
	return 0;
}