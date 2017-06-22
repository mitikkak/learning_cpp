
#include "Exercise.hpp"
#include <iostream>
#include <typeinfo>

Exercise::Exercise()
{
    std::cout << "Exercise constructor " << this << std::endl;
}
void Exercise::log() const
{
    std::cout << typeid(*this).name() << " executed " << this << std::endl;
}

