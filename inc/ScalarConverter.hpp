#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter {
	public:
		ScalarConverter();										//Default constructor
		virtual ~ScalarConverter() = 0;										//Destructor
		ScalarConverter(const ScalarConverter &other);				//Copy constructor
		ScalarConverter &operator=(const ScalarConverter &other);	//Copy operator

		static void	Convert(std::string	input);
	private:

};
#endif
