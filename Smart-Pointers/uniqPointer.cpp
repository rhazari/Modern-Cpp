#include <iostream>
#include <memory>

class Dummy{
public:
    Dummy(){
        std::cout<<"Dummy "<<this<<" constructed"<<"\n";
    }
    virtual ~Dummy(){
        std::cout<<"Dummy "<<this<<" destructed"<<"\n";
    }
};

std::unique_ptr<Dummy> source(){
    // make_unique not available in C++11
    return std::make_unique<Dummy>();
}

void sink(std::unique_ptr<Dummy> ptr){
    std::cout<<"Sink gets the value "<<ptr.get()<<"\n";
}

int main(){

    std::unique_ptr<Dummy> ptr = source();
    // Move unique pointers
    sink(move(ptr));
}