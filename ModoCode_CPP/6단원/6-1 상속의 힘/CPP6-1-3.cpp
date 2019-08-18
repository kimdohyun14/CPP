#include <iostream>
#include <string>

class Employee {
	std::string name;
	int age;

	std::string position; // 직책(이름)
	int rank; // 순위

public:
	Employee(std::string name, int age, std::string position, int rank)
		:name(name), age(age), position(position), rank(rank){ }


	// 복사 생성자
	Employee(const Employee& employee) {
		name = employee.name;
		age = employee.age;
		position = employee.position;
		rank = employee.rank;
	}

	// 디폴트 생성자
	Employee() { }

	void print_info() {
		std::cout << name << " (" << position << " , " << age << ") ==> "
			<< calculate_pay() << "만원" << std::endl;
	}

	int calculate_pay() { return 200 + rank * 50; }
};

// Employee 클래스와 다른점은 월급을 계산하는 함수와 프린트함수만 약간 다르다.
class Manager {
	std::string name;
	int age;

	std::string position;
	int rank;
	int year_of_service;

public:
	Manager(std::string name, int age, std::string position, int rank, int year_of_service)
		:year_of_service(year_of_service),
		name(name),
		age(age),
		position(position),
		rank(rank) { }

	// 복사 생성자
	Manager(const Manager& manager) {
		name = manager.name;
		age = manager.age;
		position = manager.position;
		rank = manager.rank;
		year_of_service = manager.year_of_service;
	}

	// 디폴트 생성자
	Manager() { }

	int calculate_pay() { return 200 + rank * 50 + 5 * year_of_service; }
	void print_info() {
		std::cout << name << " (" << position << " , " << age << ", " << year_of_service <<
			"년차) ==> " << calculate_pay() << "만원" << std::endl;
	}
};

class EmployeeList {
	int alloc_employee;		  // 할당한 총 직원 수 (할당된 크기)

	int current_employee;	  // 현재 직원 수 (실제로 사용하고 있는 양)
	Employee** employee_list; // 직원 데이터
	//Employee* 객체를 담는 배열로 사용하기 때문에 **붙이게 됨.
	
	int current_manager;      // 직원 데이터
	Manager** manager_list;   // 매니저 데이터

public:
	EmployeeList(int alloc_employee) : alloc_employee(alloc_employee) {
		current_employee = 0;
		current_manager = 0;
		employee_list = new Employee * [alloc_employee];
		manager_list = new Manager * [alloc_employee];
	}

	void add_employee(Employee* employee) {

		// alloc_employee 보다 current_employee 가 더많아진다면 새로 재할당
		if (alloc_employee < current_employee + 1) {
			// 로직
			// employee_list 주소값을 prev_list에 복사한다.
			// employee_list에 새 공간을 할당한다.
			// prev_list의 내용을 다시 employee_list에 복사한다.
			// prev_list를 해제한다.


			// 이전의 직원들의 내용을 저장
			Employee** prev_employee_list = employee_list;

			// 넉넉하게 공간을 새로 할당한다.
			employee_list = new Employee * [current_employee * 2];

			// 새로 할당한 공간에 다시 복사 (실제 직원들)
			for (int i = 0; i < current_employee; i++)
				employee_list[i] = prev_employee_list[i];

			delete[] prev_employee_list; // 1차원 배열이므로

			alloc_employee = current_employee * 2;
		}

		// 공간이 충분하면 직원을 넣기만 하면된다.
		employee_list[current_employee] = employee;
		current_employee++;
	}

	void add_manager(Manager* manager) {
		manager_list[current_manager] = manager;
		current_manager++;
	}

	int current_employee_num() { return current_employee; }
	int current_manager_num() { return current_manager; }

	void print_employee_info() {
		int total_pay = 0;
		for (int i = 0; i < current_employee; i++) {
			employee_list[i]->print_info();
			total_pay += employee_list[i]->calculate_pay();
		}
		for (int i = 0; i < current_manager; i++) {
			manager_list[i]->print_info();
			total_pay += manager_list[i]->calculate_pay();
		}

		std::cout << "총 비용 : " << total_pay << "만원 " << std::endl;
	}

	~EmployeeList() {
		for (int i = 0; i < current_employee; i++) {
			delete employee_list[i];
		}
		for (int i = 0; i < current_manager; i++) {
			delete manager_list[i];
		}

		delete[] employee_list;
		delete[] manager_list;
	}
};



int main() {
	EmployeeList emp_list(10);
	emp_list.add_employee(new Employee("노홍철", 34, "평사원", 1));
	emp_list.add_employee(new Employee("하하", 34, "평사원", 1));

	emp_list.add_manager(new Manager("유재석", 41, "부장", 7, 12));
	emp_list.add_manager(new Manager("정준하", 41, "과장", 4, 15));
	emp_list.add_manager(new Manager("박명수", 41, "차장", 5, 13));
	emp_list.add_employee(new Employee("정형돈", 36, "대리", 2));
	emp_list.add_employee(new Employee("길", 36, "인턴", -2));
	emp_list.print_employee_info();
	return 0;
}

// 상속의 중요성
// 다른 클래스의 내용을 그대로 포함할 수 있는 작업을 가능토록 해준다.
// 무언가를 물려 받아서 사용한다.