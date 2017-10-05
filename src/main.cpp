#include <iostream>
#include <vector>
#include <typeinfo>
#include "Exercise.hpp"
#include "InitializerList.hpp"
#include "LongLongInteger.hpp"
#include "Alignment.hpp"
#include "Atomic.hpp"
#include "Attributes.hpp"
#include "EnumClass.hpp"
#include "CopyAndRethrowException.hpp"
#include "VariadicTemplate.hpp"
#include "RValueReference.hpp"
#include "OverrideControls.hpp"

int main(void)
{
    std::vector<Exercise*> exercises;
    exercises.push_back(new InitializerList());
    exercises.push_back(new LongLongInteger());
    exercises.push_back(new Alignment());
    exercises.push_back(new Atomic());
    exercises.push_back(new Attributes());
    exercises.push_back(new EnumClass());
    exercises.push_back(new CopyAndRethrowException());
    exercises.push_back(new VariadicTemplate());
    exercises.push_back(new RValueReference());
    exercises.push_back(new OverrideControls());
    for (std::vector<Exercise*>::iterator it = exercises.begin(); it != exercises.end(); ++it)
    {
        (*it)->execute();
//        std::cout << typeid(it).name() << std::endl;
//        std::cout << typeid(*it).name() << std::endl;
//        std::cout << typeid(*(*it)).name() << std::endl;
    }
    for (std::vector<Exercise*>::iterator it = exercises.begin(); it != exercises.end(); ++it)
    {
        delete *it;
    }
    return 0;
}
