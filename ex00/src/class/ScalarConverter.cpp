#include "ScalarConverter.hpp"
#include <sstream>
#include <limits>


ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	(void) other;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &other) {
	(void) other;
	return (*this);
}

ScalarConverter::~ScalarConverter() {
}


template <typename T> void	printChar(std::ostream &out, T val) {
	char c = val;
	out << "\nChar: ";
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

template <typename T> void	printFloat(std::ostream &out, T val, bool& flag) {
	float	f = val;
	out << "Float: ";
	out << f;
	out << (flag ? ".0f\n" : "f\n");
}

template <typename T> void	printDouble(std::ostream &out, T val, bool& flag) {
	double	d = val;
	out << "Double: ";
	out << d;
	out << (flag ? ".0\n" : "\n");
}

template <typename T> void	printValue(T val, bool& flag) {
	std::ostream&	out = std::cout;
	if (val > 999999)
		flag = false;
	printChar(out, val);
	printInt(out, val);
	printFloat(out, val, flag);
	printDouble(out, val, flag);
	out << std::endl;
}

bool	isValidFloat(std::string in, std::stringstream& iss) {
	std::string	left;
	size_t	pos = in.find('.');
	iss >> left;
	if (pos != in.rfind('.'))
		return 0;
	if (iss.fail() || !iss.eof())
		return 0;
	if (left[0] != 'f' || pos == in.npos || left.size() > 1)
		return 0;
	return 1;
}

template <typename T> bool strConvert(std::string in, T *val) {
	std::stringstream iss(in);
	bool	doIHaveToWriteTheDot = true;
	iss >> *val;
	if (iss.fail())
		return 0;
	if (!iss.eof() && !isValidFloat(in, iss))
		return 0;
	size_t pos = in.find('.');
	if (pos != in.npos && (pos == 0 || std::isdigit(in[pos +1])))
		doIHaveToWriteTheDot = false;
	printValue(*val, doIHaveToWriteTheDot);
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
		bool	dummy_flag = true;
		printValue(input[0], dummy_flag);
		return ;
	}
	std::cout << "Error\nInput can't be converted !\n" << std::endl;
}
