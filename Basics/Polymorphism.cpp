#include <iostream>

using namespace std;

class Base{
public:
    Base(){
        cout<<"Calling Base constructor\n";
    }

    virtual ~Base(){
        cout<<"Calling Base destructor\n";
    }
};

class Derived: public Base{
public:
    Derived(){
        cout<<"Calling Derived constrcutor\n";
    }

    ~Derived(){
        cout<<"Calling Derived destructor\n";
    }
};

// Passing by pointer avoid object slicing
void deletePtr(Base* ptr){
    if(ptr){
        delete ptr;
    }
}

int main(){
    {
        cout<<"Using base ptr\n";
        Base *base = new Derived();
        delete base;
    }
    {
        cout<<"Using derived ptr\n";
        Derived *derived = new Derived();
        deletePtr(derived);
    }
    return 0;
}