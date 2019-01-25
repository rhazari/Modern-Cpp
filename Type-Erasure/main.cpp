#include "erased.h"
#include <iostream>

using namespace std;

struct Link {
    void printName() const{
        cout<<"Link"<<"\n";
    }
};

struct Zelda {
    void printName() const{
        cout<<"Zelda"<<"\n";
    }
};


int main(){
    TypeErased te{Link()};
    te.printName();

    te = Zelda();
    te.printName();
}