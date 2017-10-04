
#include "Exercise.hpp"
#include "RValueReference.hpp"
#include <iostream>

// http://thbecker.net/articles/rvalue_references/section_01.html

class X
{
public:
    X(int const v): a(v)
    {
        std::cout << "ctor X at " << this << " = " << a << std::endl;
    }
    ~X()
    {
        std::cout << "dtor X at " << this << " = " << a << std::endl;
    }
#if 1
    X& operator=(X const & rhs) // classical implementation
    {
        a = rhs.a;
        std::cout << "(classical) X at " << this << " = " << a << std::endl;
        return *this;
    }
#endif
#if 1
    X& operator=(X&& rhs)
    {
        *this = rhs;
        std::cout << "(move) X at " << this << " = " << a << " rhs at " << &rhs << " value " << rhs.a << std::endl;
        return *this;
    }
    constexpr X(const X& another): a(another.a) {}
#endif
    int a;
};
void foo(const X& x)
{
    std::cout << "foo lvalue reference overload " << &x << " value " << x.a << std::endl;
}
#if 1
void foo(const X&& x)
{
    std::cout << "foo rvalue reference overload " << &x << " value " << x.a << std::endl;
}
#endif
X foobar()
{
    return X(0);
}

void RValueReference::execute()
{
    // 0. lvalues and rvalues
    //    lvalue (locator value) represents an object that occupies some identifiable location in memory (i.e. has an address).
    //    rvalue is an expression that does not represent an object occupying some identifiable location in memory.
    // The original definition of lvalues and rvalues from the earliest days of C is as follows:
    // An lvalue is an expression e that may appear on the left or on the right hand side of an assignment,
    // whereas an rvalue is an expression that can only appear on the right hand side of an assignment.
    // For example,
    int a = 42;
    int b = 43;

     // a and b are both l-values:
     a = b; // ok
     b = a; // ok
     a = a * b; // ok

     // a * b is an rvalue:
     int c = a * b; // ok, rvalue on right hand side of assignment
     //a * b = 42; // error, rvalue on left hand side of assignment

     X x1(1);
     X x2(2);
     x1 = x2; // classical assignment operator is called
     x1 = foobar(); // move constructor is called
     foo(x1); // argument is lvalue: calls foo(X&)
     foo(foobar()); // argument is rvalue: calls foo(X&&)

    // 2. Perfect forwarding
    log();
}
