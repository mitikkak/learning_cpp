
#include "Exercise.hpp"
#include "Attributes.hpp"
#include <cstdio>
#if __cplusplus > 199711L
#include <system_error>
#endif

#if __cplusplus > 199711L
void Attributes::f [[noreturn]]()    // f() will never return
{
    std::system_error e;
    throw e;
}
#else
void Attributes::f()
{
    throw "Error";
    return;
}
#endif

void Attributes::execute()
{
    try
    {
      f();
    }
    catch(char const* what)
    {
        printf("Attributes::execute catched exception(1): %s \n", what);
    }
#if __cplusplus > 199711L
    catch(const std::system_error& e)
    {
        printf("Attributes::execute catched exception(2): %u %s \n", e.code().value(), e.what());
    }
#endif
    printf("Attributes::execute do_this(): %u \n", do_this());
    log();
}

