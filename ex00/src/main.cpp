#include "ScalarConverter.hpp"

int main() {
	
	std::string	input;

	while (std::getline(std::cin, input) && input != "EXIT" && !std::cin.eof()) {
		ScalarConverter::Convert(input);
	}
	return 0;
}
