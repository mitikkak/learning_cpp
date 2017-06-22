#ifndef SRC_INITIALIZERLIST_HPP_
#define SRC_INITIALIZERLIST_HPP_

class InitializerList : public Exercise
{
    std::vector<int> container;
    void log(std::initializer_list<int> args) const;
    void log(std::initializer_list<std::pair<int,int>> args) const;
public:
    InitializerList();
    void execute();
};



#endif /* SRC_INITIALIZERLIST_HPP_ */
