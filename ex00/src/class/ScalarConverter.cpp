#include "ScalarConverter.hpp"
#include <sstream>
#include <limits>

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

template <typename T> void	printChar(std::ostream &out, T val) {
	char c = val;
	out << "Char: ";
	if (val < 0 || val > 127) {
		out << "impossible\n";
		return ;
	}
	if (isprint(c))
		 out << c << "\n";
	else
		out << "Non displayable\n";
}


template <typename T> void	printInt(std::ostream &out, T val) {
	int	i = val;
	out << "Int: ";
	if (val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max())
		out << "impossible\n";
	else
		out << i << "\n";
}

template <typename T> void	printFloat(std::ostream &out, T val) {
	float	f = val;
	out << "Float: ";
	// if (val < std::numeric_limits<float>::min() || val > std::numeric_limits<float>::min())
		// out << "impossible\n";
	// else
		out << f << "f\n";
}

template <typename T> void	printDouble(std::ostream &out, T val) {
	double	d = val;
	out << "Double: ";
	out << d << "\n";
}

template <typename T> void	printValue(T val) {
	std::ostream&	out = std::cout;
	printChar(out, val);
	printInt(out, val);
	printFloat(out, val);
	printDouble(out, val);
	out << std::endl;
}

template <typename T> bool strConvert(std::string in, T *val) {
	std::stringstream iss(in);
	iss >> *val;
	if (iss.fail() || (!iss.eof() && in[in.size() - 1] != 'f'))
		return 0;
	printValue(*val);
	return 1;
}

void	pseudoFloat(std::string in) {
	std::ostream& out = std::cout;
	printChar(out, -1);
	out << "Int: impossible\n";
	out << "Float: " << in << "\n" << "Double: " << (in.erase(in.size() - 1)) << std::endl;
}

void	pseudoDouble(std::string in) {
	std::ostream& out = std::cout;
	printChar(out, -1);
	out << "Int: impossible\n";
	out << "Float: " << in + "f" << "\n" << "Double: " << in << std::endl;
}

bool	printLiteral(std::string in) {
	std::string	f[] = {"+inff", "inff", "-inff", "nanf"};
	std::string	d[] = {"+inf", "inf", "-inf", "nan"};

	for (unsigned int i = 0; i < (sizeof(f) / sizeof(std::string)); i++) {
		if (in == f[i]) {
			pseudoFloat(in);
			return 1;
		}
	}
	for (unsigned int i = 0; i < (sizeof(d) / sizeof(std::string)); i++) {
		if (in == d[i]) {
			pseudoDouble(in);
			return 1;
		}
	}
	return 0;
}

void	ScalarConverter::Convert(std::string input) {
{
	int	val;
	if (strConvert(input, &val))
		return ;
}
{
	float	val;
	if (strConvert(input, &val))
		return ;
}
{
	double	val;
	if (strConvert(input, &val))
		return ;
}
	if (printLiteral(input))
		return ;
	if (input.size() == 1 && std::isprint(input[0])) {
		printValue(input[0]);
		return ;
	}
	std::cout << "Error\nInput can't be converted !" << std::endl;
}
