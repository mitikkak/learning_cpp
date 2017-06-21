#include <iostream>
#include <vector>
#include <typeinfo>

class Exercise
{
public:
    Exercise()
    {
        std::cout << "Exercise constructor " << this << std::endl;
    }
    virtual ~Exercise(){};
    virtual void execute() = 0;
    void log() const
    {
        std::cout << typeid(*this).name() << " executed " << this << std::endl;
    }
};

class Something : public Exercise
{
    void execute()
    {
        log();
    }
};

class Otherthing : public Exercise
{
    void execute()
    {
        log();
    }
};

int main(void)
{
    std::vector<Exercise*> exercises;
    exercises.push_back(new Something());
    exercises.push_back(new Otherthing());
    for (std::vector<Exercise*>::iterator it = exercises.begin(); it != exercises.end(); ++it)
    {
        (*it)->execute();
        std::cout << typeid(it).name() << std::endl;
        std::cout << typeid(*it).name() << std::endl;
        std::cout << typeid(*(*it)).name() << std::endl;
    }
    return 0;
}
