#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter {
	public:
		static void	Convert(std::string	input);
	private:
		ScalarConverter();										//Default constructor
		~ScalarConverter();										//Destructor
		ScalarConverter(const ScalarConverter &other);				//Copy constructor
		ScalarConverter &operator=(const ScalarConverter &other);	//Copy operator
};
#endif
