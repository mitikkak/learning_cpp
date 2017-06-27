
#include "Exercise.hpp"
#include "LongLongInteger.hpp"
#include <iostream>
#include <typeinfo>

void LongLongInteger::execute()
{
    long long thing = 0xAAAABBBBCCCCDDDD;
    std::cout << typeid(this).name() << " thing(" << sizeof(thing) << " bytes): " <<  std::hex << thing << std::endl;
    log();
}



