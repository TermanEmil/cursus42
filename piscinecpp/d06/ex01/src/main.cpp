#include <iostream>
#include <stdlib.h>
#include <time.h>

class Base {
public:
	virtual ~Base (void);
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base::~Base (void) {}

Base * generate (void) {
	int rs = rand() % 3;

	if (rs == 0) {
		std::cout << "Generated A" << std::endl;
		return new A();
	} else if (rs == 1) {
		std::cout << "Generated B" << std::endl;
		return new B();
	} else {
		std::cout << "Generated C" << std::endl;
		return new C();
	}
}

void identify_from_pointer (Base * p) {
	if (dynamic_cast<A*> (p) != NULL)
		std::cout << "It's a pointer to A" << std::endl;
	else if (dynamic_cast<B*> (p) != NULL)
		std::cout << "It's a pointer to B" << std::endl;
	else if (dynamic_cast<C*> (p) != NULL)
		std::cout << "It's a pointer to C" << std::endl;
	else
		std::cout << "WTF?" << std::endl;
}

void identify_from_reference (Base & p) {
	if (dynamic_cast<A*> (&p) != NULL)
		std::cout << "It's a pointer to A" << std::endl;
	else if (dynamic_cast<B*> (&p) != NULL)
		std::cout << "It's a pointer to B" << std::endl;
	else if (dynamic_cast<C*> (&p) != NULL)
		std::cout << "It's a pointer to C" << std::endl;
	else
		std::cout << "WTF?" << std::endl;	
}

int main (void) {
	srand(time(NULL));
	
	Base * base = generate();
	identify_from_pointer(base);
	identify_from_reference(*base);
	return 0;
}