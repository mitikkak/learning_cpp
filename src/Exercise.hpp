
#ifndef SRC_EXERCISE_HPP_
#define SRC_EXERCISE_HPP_

class Exercise
{
public:
    Exercise();
    virtual ~Exercise(){};
    virtual void execute() = 0;
    void log() const;
};



#endif /* SRC_EXERCISE_HPP_ */
