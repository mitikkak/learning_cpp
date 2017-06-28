#include <iostream>
#include <vector>
#include <typeinfo>
#include "Exercise.hpp"
#include "InitializerList.hpp"

InitializerList::InitializerList() :
#if __cplusplus > 199711L
        container({ 1, 2 })
#else
       container()
#endif
{
}

#if __cplusplus > 199711L
void InitializerList::log(std::initializer_list<int> args) const
{
    for (auto p : args)
    {
        std::cout << "InitializerList::log<int> " << p << "\n";
    }
}
void InitializerList::log(std::initializer_list<std::pair<int,int>> args) const
{
    for (auto p : args)
    {
        std::cout << "InitializerList::log<pair<int,int>> " << p.first << ", " << p.second << "\n";
    }
}
#endif
void InitializerList::execute()
{
    Exercise::log();
    for (int i = 0; i < container.size(); i++)
    {
        std::cout << "container[" << i << "] " << container[i] << std::endl;
    }
#if __cplusplus > 199711L
    log({ 1, 2, 3 });
    log({{ 1, 2}, {3, 4}});
#endif
}

