
#if __cplusplus > 199711L
#include<stdexcept>
#endif
#include "Exercise.hpp"
#include "CopyAndRethrowException.hpp"
#if __cplusplus > 199711L
#include <thread>
#include<exception>
#endif
#include<iostream>

#if __cplusplus > 199711L
std::exception_ptr CopyAndRethrowException::teptr = nullptr;
#endif

#if __cplusplus > 199711L
void CopyAndRethrowException::task1()
{
    try
    {
        throw std::runtime_error("To be passed between threads");
    }
    catch(const std::exception &ex)
    {
        teptr = std::current_exception();
        std::cout << "CopyAndRethrowException::task1 exception: " << ex.what() << std::endl;
    }
}
void CopyAndRethrowException::task2()
{
    if (teptr) {
        try{
            std::rethrow_exception(teptr);
        }
        catch(const std::exception &ex)
        {
            std::cout << "CopyAndRethrowException::task2 with exception: " << ex.what() << "\n";
        }
    }

}
#endif

void CopyAndRethrowException::execute()
{
    log();
#if __cplusplus > 199711L
    std::thread t1(CopyAndRethrowException::task1);
    t1.join();
    std::thread t2(CopyAndRethrowException::task2);
    t2.join();
    if (teptr) {
        try{
            std::rethrow_exception(teptr);
        }
        catch(const std::exception &ex)
        {
            std::cout << "CopyAndRethrowException::execute with exception: " << ex.what() << "\n";
        }
    }
#endif
}

