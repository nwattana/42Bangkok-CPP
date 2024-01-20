#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &other)
{
	*this = other;
}

Serializer::~Serializer()
{
}

Serializer &Serializer::operator=(const Serializer &other)
{
	*this = other;
	return *this;
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t ptr)
{
	return (reinterpret_cast<Data *>(ptr));
}