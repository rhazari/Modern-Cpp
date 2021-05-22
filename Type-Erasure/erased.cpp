#include "erased.h"
#include <iostream>
#include <vector>

struct Link {
    void printName() const{
        std::cout<<"Link"<<"\n";
    }
};

struct Zelda {
    void printName() const{
        std::cout<<"Zelda"<<"\n";
    }
};

int main(){
    TypeErased te{Link()};
    te.printName();

    te = Zelda();
    te.printName();

    std::cout<<"===== Checking from Vector Container =======\n";
    std::vector<TypeErased> vec;
    vec.push_back(Link());
    vec.push_back(Zelda());

    for(const auto& elem: vec){
        elem.printName();
    }
    std::cout<<"\n";
}