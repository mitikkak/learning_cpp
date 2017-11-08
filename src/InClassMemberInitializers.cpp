
#include "Exercise.hpp"
#include "InClassMemberInitializers.hpp"
#include <iostream>

class Abba
{
    unsigned value_{9};
public:
    Abba(){}
    Abba(unsigned const v): value_(v){}
    Abba(const Abba& other): value_(7){}
    unsigned value() const {return value_;}
};
void InClassMemberInitializers::execute()
{
    Abba a1;
    Abba a2(6);
    Abba a3(a1);
    using namespace std;
    cout << "Default: " << a1.value() << endl;
    cout << "Specialized: " << a2.value() << endl;
    cout << "Copy: " << a3.value() << endl;
    log();
}
