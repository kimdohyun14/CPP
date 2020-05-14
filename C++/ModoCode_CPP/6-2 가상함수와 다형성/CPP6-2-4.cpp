#include <iostream>
#include <string>

class Employee {
protected:
	std::string name;
	int age;

	std::string position; // ��å
	int rank;             // ����

public:
	Employee(std::string name, int age, std::string position, int rank)
		:name(name), age(age), position(position), rank(rank) {}

	// ���� ������
	Employee(const Employee& employee) {
		name = employee.name;
		age = employee.age;
		position = employee.position;
		rank = employee.rank;
	}

	// ����Ʈ ������
	Employee() {}

	// ���� �Լ� 2�� ����
	virtual void print_info() {
		std::cout << name << " (" << position << ", " << age << ") ==> "
			<< calculate_pay() << "����" << std::endl;
	}

	virtual int calculate_pay() {
		return 200 + rank * 50;
	}

};

class Manager : public Employee {
	int year_of_service;

public:
	Manager(std::string name, int age, std::string position, int rank,
		int year_of_service)
		: year_of_service(year_of_service), Employee(name, age, position, rank) { }

	int calculate_pay() override {
		return 200 + rank * 50 + 5 * year_of_service;
	}

	void print_info() override{
		std::cout << name << " (" << position << ", " << age << ", "
			<< year_of_service << "����) ==> " << calculate_pay() << "����" << std::endl;
	}
};

class EmployeeList {
public:
	int alloc_employee;       // �Ҵ��� �� ���� ��
	int current_employee;     // ���� ���� ��
	Employee** employee_list; // ���� ������

public:
	EmployeeList(int alloc_employee) : alloc_employee(alloc_employee) {
		employee_list = new Employee * [alloc_employee];
		current_employee = 0;
	}

	void add_employee(Employee* employee) {
		// ��� current_employee �� alloc_employee ���� ��
        // �������� ��� �ݵ�� ���Ҵ��� �Ѵ�.
		// (�Ҵ�� ũ�⺸�� �� ���� ������ ������ ��� ���Ҵ�)
		//std::cout << current_employee << "  " << alloc_employee << std::endl;
		if (current_employee + 1 >= alloc_employee) {
			// �ӽ÷� ����
			Employee** prev_employee_list = employee_list;
			// ���Ҵ� (���� ���� �� * 2��)
			employee_list = new Employee * [current_employee * 2];
			// ����
			for (int i = 0; i < current_employee; i++) {
				employee_list[i] = prev_employee_list[i];
			}
				
			// �ӽ÷� ����� ��ü ��ȯ
			/*
			for (int i = 0; i < current_employee; i++)
				delete prev_employee_list[i];
		    */
			delete[] prev_employee_list;
			
			alloc_employee = current_employee * 2;
		}
		// ���� ���� ���� �Ҵ��� �� ���� ������ ���� ����
		// �׳� �߰����ָ� �ȴ�.
		employee_list[current_employee] = employee;
		current_employee++;
	}

	int current_employee_num() { return current_employee; }

	void print_employee_info() {
		int total_pay = 0;
		for (int i = 0; i < current_employee; i++) {
			// employee_list�� Employee ���� Manager������ ���� �ٸ��� �����Ѵ�.
			// �̴� ���� �Լ��� ���ؼ� �����ȴ�.
			// �ϳ��� �޼ҵ带 ȣ���������� �ұ��ϰ� �������� �ٸ� �۾�����
		    // �ϴ� ���� �ٷ� ������(polymorphism)�̶�� �θ���.
			employee_list[i]->print_info();
			total_pay += employee_list[i]->calculate_pay();
		}
		std::cout << "�� ��� : " << total_pay << "����" << std::endl;
	}
	// �Ҹ���
	~EmployeeList() {
		for (int i = 0; i < current_employee; i++)
			delete employee_list[i];
		delete[] employee_list;
	}
};

int main() {
	EmployeeList emp_list(10);
	emp_list.add_employee(new Employee("��ȫö", 34, "����", 1));
	emp_list.add_employee(new Employee("����", 34, "����", 1));

	emp_list.add_employee(new Manager("���缮", 41, "����", 7, 12));
	emp_list.add_employee(new Manager("������", 43, "����", 4, 15));
	emp_list.add_employee(new Manager("�ڸ��", 43, "����", 5, 13));
	emp_list.add_employee(new Employee("������", 36, "�븮", 2));
	emp_list.add_employee(new Employee("��", 36, "����", -2));

	emp_list.add_employee(new Employee("A", 34, "����", 1));
	emp_list.add_employee(new Employee("B", 34, "����", 1));
	emp_list.add_employee(new Employee("C", 34, "����", 1));
	emp_list.add_employee(new Employee("D", 34, "����", 1));
	emp_list.print_employee_info();
	std::cout << emp_list.current_employee << " " << emp_list.alloc_employee << std::endl;
	return 0;
}