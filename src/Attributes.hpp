
#ifndef SRC_ATTRIBUTES_HPP_
#define SRC_ATTRIBUTES_HPP_

class Attributes : public Exercise
{
#if __cplusplus > 199711L
    void f [[noreturn]]();
    [[gnu::always_inline]] int do_this() const
    {
        return 1;
    }
#else
    void f();
#endif
    void execute();
};



#endif /* SRC_ATTRIBUTES_HPP_ */
