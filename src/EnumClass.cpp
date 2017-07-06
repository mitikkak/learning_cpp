
#include "Exercise.hpp"
#include "EnumClass.hpp"
#include <typeinfo>
#include <cstdio>

#if __cplusplus > 199711L
enum class GlobalColor {black};
#endif

void EnumClass::execute()
{
#if __cplusplus > 199711L
    enum Alert : unsigned short { green, yellow, orange }; // traditional enum with underlying type defined
    enum class Color : unsigned long long { red = 0xAAAABBBBCCCCDDDD, blue=0xEEEEFFFF00001111 };   // scoped and strongly typed enum
                                             // no export of enumerator names into enclosing scope
                                             // no implicit conversion to int
#else
    enum Alert { green, yellow, orange };
    enum Color {red, blue};
#endif
    //enum class TrafficLight : public Color {yellow}; // no inheritance

    //Alert a = 7;              // error (as ever in C++)
    //Color c = 7;              // error: no int->Color conversion
    Color c = (Color) 7;
    int a2 = orange;             // ok: Alert->int conversion
#if __cplusplus > 199711L
    int a3 = Alert::orange;      // error in C++98; ok in C++11
#else
    int a3 = orange;
#endif
    //int a4 = blue;            // error: blue not in scope
    //int a5 = Color::blue;     // error: not Color->int conversion

#if __cplusplus > 199711L
    Color localColor = Color::blue;   // ok
    Color localColor2 = Color::red;   // ok
    GlobalColor globalColor = GlobalColor::black;

    printf("EnumClass::execute localColor type: %s value: %llx %llx, globalColor: %s \n",  typeid(localColor).name(), (unsigned long long)localColor, (unsigned long long)localColor2, typeid(globalColor).name());
#endif
    log();
}


