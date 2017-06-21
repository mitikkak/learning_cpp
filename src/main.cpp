#include <iostream>
#include <vector>

class Exercise
{
public:
    void execute()
    {
        std::cout << "executed" << std::endl;
    }
};

int main(void)
{
    std::vector<Exercise> exercises;
    exercises.push_back(*(new Exercise()));
    for (std::vector<Exercise>::iterator it = exercises.begin(); it != exercises.end(); ++it)
    {
        it->execute();
    }
    return 0;
}
