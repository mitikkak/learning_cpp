#include <iostream>
#include <vector>
#include <typeinfo>
#include "Exercise.hpp"
#include "InitializerList.hpp"
#include "LongLongInteger.hpp"
#include "Alignment.hpp"

int main(void)
{
    std::vector<Exercise*> exercises;
    exercises.push_back(new InitializerList());
    exercises.push_back(new LongLongInteger());
    exercises.push_back(new Alignment());
    for (std::vector<Exercise*>::iterator it = exercises.begin(); it != exercises.end(); ++it)
    {
        (*it)->execute();
//        std::cout << typeid(it).name() << std::endl;
//        std::cout << typeid(*it).name() << std::endl;
//        std::cout << typeid(*(*it)).name() << std::endl;
    }
    return 0;
}
