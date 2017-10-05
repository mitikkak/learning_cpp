
#include "Exercise.hpp"
#include "OverrideControls.hpp"
#include <iostream>

//http://www.stroustrup.com/C++11FAQ.html#override
struct B
{
    virtual void f() { std::cout << "B f()" << std::endl;}
    virtual ~B() {}
    virtual void g() const {}
    virtual void h(char) {}
    void k();   // not virtual
};

struct D: B
{
    void f() { std::cout << "D f()" << std::endl;}   // overrides B::f()
    void g();   // doesn't override B::g() (wrong type)
    virtual void h(char);   // overrides B::h()
    void k();   // doesn't override B::k() (B::k() is not virtual)
};
// To allow the programmer to be more explicit about overriding, we now have the "contextual keyword" override:
struct E : B {
    virtual ~E(){}
    void f() override /* final */ { std::cout << "E f()" << std::endl;};  // OK: overrides B::f()
//    void g() override;  // error: wrong type
    virtual void h(char) {}   // overrides B::h(); likely warning
//    void k() override;  // error: B::k() is not virtual
};

struct F : E {
    void f() override { std::cout << "F f()" << std::endl;}
};
/*
A declaration marked override is only valid if there is a function to override. The problem with h() is not guaranteed to be caught (because it is not an error according to the language definition) but it is easily diagnosed.
override is only a contextual keyword, so you can still use it as an identifier:


int override = 7;   // not recommended
*/

void OverrideControls::execute()
{
    B* foo = new F();
    foo->f();
    delete foo;

    log();
}
