#ifndef SERIAL_HPP
#define SERIAL_HPP

#include <iostream>

class Data
{
private:
    int num;

public:
    Data();
    Data(const Data& ref);
    Data& operator=(const Data& ref);
    ~Data();
    Data(int _num);

    int getNum() const;
};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif