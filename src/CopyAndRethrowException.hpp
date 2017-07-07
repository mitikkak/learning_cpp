
#ifndef SRC_COPYANDRETHROWEXCEPTION_HPP_
#define SRC_COPYANDRETHROWEXCEPTION_HPP_

class CopyAndRethrowException : public Exercise
{
#if __cplusplus > 199711L
    static std::exception_ptr teptr;
#endif
    static void task1();
    static void task2();
    void execute();
};

#endif /* SRC_COPYANDRETHROWEXCEPTION_HPP_ */
