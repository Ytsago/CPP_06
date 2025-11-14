#include "ScalarConverter.hpp"

int main(int ac, char* const av[]) {
	
	if (ac > 2) {
		std::cout << "Too many argument" << std::endl;
		return -1;
	}

	if (ac == 2) {
		ScalarConverter::Convert(av[1]);
		return 0;
	}

	std::string	input;

	std::cout << "Value : 42" << std::endl;
	ScalarConverter::Convert("42");

	std::cout << "Value : yes" << std::endl;
	ScalarConverter::Convert("yes");

	std::cout << "Value : 42.4f" << std::endl;
	ScalarConverter::Convert("42.4f");

	std::cout << "Value : 246785412542152" << std::endl;
	ScalarConverter::Convert("246785412542152");

	std::cout << "Value : c" << std::endl;
	ScalarConverter::Convert("c");

	while (std::getline(std::cin, input) && input != "EXIT" && !std::cin.eof()) {
		ScalarConverter::Convert(input);
	}
	return 0;
}
