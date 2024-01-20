#pragma once
#include "Data.hpp"
#include <stdint.h>

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer &other);

public:
	~Serializer();
	Serializer &operator=(const Serializer &other);
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t ptr);
};