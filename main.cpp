#include <iostream>

struct A {
	A() = default;

	A(const A & a) { std::cout << "Copy-constructed" << std::endl; }
	A(A&& a) { std::cout << "Move-constructed" << std::endl; }
	A& operator=(A&& other) { std::cout << "Copy-assigned" << std::endl; return *this; }
	A& operator=(const A & other) { std::cout << "Move-assigned" << std::endl; return *this; }
	
	void print() const { std::cout << "Print!" << std::endl; }
};

void pass_by_value(A a) {
	a.print();
}

void pass_by_const_ref(const A & a) {
	a.print();
}

void pass_by_rref(A && a) {
	a.print();
}

int main() {
	A a1, a2, a3;

	std::cout << "Pass by value: " << std::endl;
	pass_by_value(std::move(a1));
	std::cout << "Pass by const-ref" << std::endl;
	pass_by_const_ref(a2);
	std::cout << "Pass by r-ref" << std::endl;
	pass_by_rref(std::move(a3));
}