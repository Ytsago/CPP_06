#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void) {
	int nm = std::rand() % 3;

	switch (nm) {
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
	}
	return NULL;
}

void	identify(Base* p) {
	std::ostream& out = std::cout;
	Base*	pt;
	
	pt = dynamic_cast<A*>(p);
	if (pt != NULL) {
		out << "Object is type A";
	}

	pt = dynamic_cast<B*>(p);
	if (pt != NULL) {
		out << "Object is type B";
	}

	pt = dynamic_cast<C*>(p);
	if (pt != NULL) {
		out << "Object is type C";
	}
	out << std::endl;
}

void	identify(Base& p) {
	std::ostream& out = std::cout;
	try {
		A &obj = dynamic_cast<A&>(p);
		(void) obj;
		out << "Object is type A";
	}
	catch (std::exception &e) {
	}

	try {
		B &obj = dynamic_cast<B&>(p);
		(void) obj;
		out << "Object is type B";
	}
	catch (std::exception &e) {
	}

	try {
		C &obj = dynamic_cast<C&>(p);
		(void) obj;
		out << "Object is type C";
	}
	catch (std::exception &e) {
	}
	(void) p;
	out << std::endl;
}

int	main() {
	std::srand(time(NULL));
	for (size_t i = 0; i < 50; i++) {
		Base* randBase = generate();
		identify(randBase);
		identify(*randBase);
		std::cout << std::endl;
		delete randBase;
	}
	return 0;
}
