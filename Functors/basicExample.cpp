#include <iostream>

class AddFunctor {
    int m_val;
public:
    AddFunctor(int _val): m_val(_val){}

    int operator()(int _val) const{
        return m_val + _val;
    }
};

int main(){
    AddFunctor obj(3);
    std::cout<< obj(10)<<"\n";
    std::cout<< obj(17)<<"\n";
}