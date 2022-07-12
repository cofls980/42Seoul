#include "Data.hpp"

Data::Data()
{
    this->num = 100;
}

Data::Data(const Data& ref)
{
    this->num = ref.getNum();
}

Data& Data::operator=(const Data& ref)
{
    this->num = ref.getNum();
    return (*this);
}

Data::~Data()
{}

Data::Data(int _num)
{
    this->num = _num;
}

int Data::getNum() const
{
    return this->num;
}

uintptr_t serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}