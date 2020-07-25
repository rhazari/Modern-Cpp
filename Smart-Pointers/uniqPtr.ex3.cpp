#include <iostream>
#include <memory>
#include <vector>

class Dummy{
public:
    Dummy(){
        std::cout<<"Dummy "<<this<<" constructed"<<"\n";
    }
    virtual ~Dummy(){
        std::cout<<"Dummy "<<this<<" destructed"<<"\n";
    }
};

int main(){

    std::vector<std::unique_ptr<Dummy>> myVec;

    for(int k = 0; k < 10; ++k){
        myVec.push_back(std::make_unique<Dummy>());
    }
}