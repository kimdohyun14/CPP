#include <iostream>
#include <string>

class Employee {
protected:
	std::string name;
	int age;

	std::string position; // 직책
	int rank;             // 순위

public:
	Employee(std::string name, int age, std::string position, int rank)
		:name(name), age(age), position(position), rank(rank) {}

	// 복사 생성자
	Employee(const Employee& employee) {
		name = employee.name;
		age = employee.age;
		position = employee.position;
		rank = employee.rank;
	}

	// 디폴트 생성자
	Employee() {}

	// 가상 함수 2개 선언
	virtual void print_info() {
		std::cout << name << " (" << position << ", " << age << ") ==> "
			<< calculate_pay() << "만원" << std::endl;
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
			<< year_of_service << "년차) ==> " << calculate_pay() << "만원" << std::endl;
	}
};

class EmployeeList {
public:
	int alloc_employee;       // 할당한 총 직원 수
	int current_employee;     // 현재 직원 수
	Employee** employee_list; // 직원 데이터

public:
	EmployeeList(int alloc_employee) : alloc_employee(alloc_employee) {
		employee_list = new Employee * [alloc_employee];
		current_employee = 0;
	}

	void add_employee(Employee* employee) {
		// 사실 current_employee 가 alloc_employee 보다 더
        // 많아지는 경우 반드시 재할당을 한다.
		// (할당된 크기보다 더 많은 직원이 들어오는 경우 재할당)
		//std::cout << current_employee << "  " << alloc_employee << std::endl;
		if (current_employee + 1 >= alloc_employee) {
			// 임시로 저장
			Employee** prev_employee_list = employee_list;
			// 재할당 (현재 직원 수 * 2로)
			employee_list = new Employee * [current_employee * 2];
			// 복사
			for (int i = 0; i < current_employee; i++) {
				employee_list[i] = prev_employee_list[i];
			}
				
			// 임시로 저장된 객체 반환
			/*
			for (int i = 0; i < current_employee; i++)
				delete prev_employee_list[i];
		    */
			delete[] prev_employee_list;
			
			alloc_employee = current_employee * 2;
		}
		// 현재 직원 수가 할당한 총 직원 수보다 적은 경우는
		// 그냥 추가해주면 된다.
		employee_list[current_employee] = employee;
		current_employee++;
	}

	int current_employee_num() { return current_employee; }

	void print_employee_info() {
		int total_pay = 0;
		for (int i = 0; i < current_employee; i++) {
			// employee_list가 Employee 인지 Manager인지에 따라서 다르게 동작한다.
			// 이는 가상 함수에 의해서 결정된다.
			// 하나의 메소드를 호출했음에도 불구하고 여러가지 다른 작업들을
		    // 하는 것을 바로 다형성(polymorphism)이라고 부른다.
			employee_list[i]->print_info();
			total_pay += employee_list[i]->calculate_pay();
		}
		std::cout << "총 비용 : " << total_pay << "만원" << std::endl;
	}
	// 소멸자
	~EmployeeList() {
		for (int i = 0; i < current_employee; i++)
			delete employee_list[i];
		delete[] employee_list;
	}
};

int main() {
	EmployeeList emp_list(10);
	emp_list.add_employee(new Employee("노홍철", 34, "평사원", 1));
	emp_list.add_employee(new Employee("하하", 34, "평사원", 1));

	emp_list.add_employee(new Manager("유재석", 41, "부장", 7, 12));
	emp_list.add_employee(new Manager("정준하", 43, "과장", 4, 15));
	emp_list.add_employee(new Manager("박명수", 43, "차장", 5, 13));
	emp_list.add_employee(new Employee("정형돈", 36, "대리", 2));
	emp_list.add_employee(new Employee("길", 36, "인턴", -2));

	emp_list.add_employee(new Employee("A", 34, "평사원", 1));
	emp_list.add_employee(new Employee("B", 34, "평사원", 1));
	emp_list.add_employee(new Employee("C", 34, "평사원", 1));
	emp_list.add_employee(new Employee("D", 34, "평사원", 1));
	emp_list.print_employee_info();
	std::cout << emp_list.current_employee << " " << emp_list.alloc_employee << std::endl;
	return 0;
}