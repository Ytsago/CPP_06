#include <string>
#include <iostream>
#include "Serializer.hpp"

struct Data {
	int			x;
	char		c;
	std::string	word;
};

std::ostream& operator<<(std::ostream& out, Data& el) {
	out << "Int: " << el.x << "\nChar: " << el.c << "\nWord: " << el.word;
	return out;
}

int	main() {
	Data		base = {.x = 7, .c = 'z', .word = "Hello"};
	uintptr_t	serialized = Serializer::serialize(&base);
	Data*		deserialized = Serializer::deserialize(serialized);

	std::cout << "Base data address : " << &base
		<< "\nSerialized pointer : " << serialized
		<< "\nDeserialize address : " << deserialized << "\n\n";
	
	std::cout << "Data value : " << base
		<< "\n\nDeserialized value : " << *deserialized << std::endl;
	return 0;
}
