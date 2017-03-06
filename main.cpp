#include <iostream>

struct A {
	A() = default;

	A(const A & a) { std::cout << "Copy-constructed" << std::endl; }
	A(A&& a) { std::cout << "Move-constructed" << std::endl; }
	A& operator=(A&& other) { std::cout << "Copy-assigned" << std::endl; return *this; }
	A& operator=(const A & other) { std::cout << "Move-assigned" << std::endl; return *this; }
	
	void print() const { std::cout << "Print!" << std::endl; }
};

void pass_by_value_with_move_level_2(A a) {
    std::cout << "In Level 2" << std::endl;
}

void pass_by_value_with_move(A a) {
    std::cout << "In Level 1" << std::endl;
    pass_by_value_with_move_level_2(std::move(a));
}

void pass_by_value_with_copy(A a) {
}

void pass_by_const_ref(const A & a) {
	a.print();
}

void pass_by_rref(A && a) {
	a.print();
}

int main() {
	A a1, a2, a3, a4;

    // Elide expected
	std::cout << "Pass by value with move: " << std::endl;
    pass_by_value_with_move(std::move(a1));

    std::cout << "Pass by value with move from temporary: " << std::endl;
    pass_by_value_with_move(A());

    std::cout << "Pass by const-ref" << std::endl;
	pass_by_const_ref(a2);

    std::cout << "Pass by r-ref" << std::endl;
	pass_by_rref(std::move(a3));


    // Elide not expected
    std::cout << "Pass by value with copy: " << std::endl;
    pass_by_value_with_copy(a4);
}
