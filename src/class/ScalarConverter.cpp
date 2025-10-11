#include "ScalarConverter.hpp"
#include <istream>

ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	(void) other;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &other) {
	if (this != &other)
		return (*this);
	return (*this);
}

ScalarConverter::~ScalarConverter() {
	std::cout << "Destructor called" << std::endl;
}

void ScalarConverter::Convert(std::string input) {
	bool	isChar = false;
	bool	isNb = false;
	bool	isDot = false;

	for (size_t i = 0; i < input.size(); i++) {
		if (!std::isprint(input[i])) {
			std::cout << "Some weird character that can't be printed has been found" << std::endl;
			return ;
	  	}
		if (std::isprint(input[i]) && !std::isdigit(input[i])) {
			if (isChar) {
				std::cout << "Multiple char has been detected !" << std::endl;
				return ;
			}
			else
				isChar = true;
		}
		if (std::isdigit(input[i]))
			isNb = true;
		if (input[i] == '.')
		{
			if (isDot) {
				std::cout << "Multiple cdot has been detected !" << std::endl;
				return ;
			}
			else if (i == 0) {
				std::cout << "Number can't start with a dot !" << std::endl;
				return ;
			}
			else
				isDot = true;
		}
	}
	if (isChar && isNb && input[input.size() - 1] != 'f') {
		std::cout << "Mixed char and number" << std::endl;
		return ;
	}
	std::cout << "input seem correct" << std::endl;
}
