#include <string>
#include <iostream>
#include <stdint.h>
#include "Data.hpp"
#include "Serializer.hpp"


int main(void)
{
	Data*		data = new Data;
	uintptr_t serialized = Serializer::serialize(data);
	Data* deserialized= Serializer::deserialize(serialized);


	std::cout << "data: " << data << std::endl;
	std::cout << "serialized: " << serialized << std::endl;
	std::cout << "deserialized: " << deserialized << std::endl;

	delete data;
}