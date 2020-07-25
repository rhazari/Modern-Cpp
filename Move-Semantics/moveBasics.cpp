#include <iostream>
#include <utility>

class Foo{
public:
    Foo(){
        std::cout<<"Default Constructor"<<"\n";
    }

    Foo(const Foo& rhs){
        std::cout<<"Copy Constructor"<<"\n";
        if(rhs.i != nullptr){
            i = new int(*rhs.i);
        }
    }

    Foo& operator=(const Foo& rhs){
        std::cout<<"Copy Assignment"<<"\n";
        if(rhs.i != nullptr){
            i = new int(*rhs.i);
        }
        return *this;
    }

    Foo& operator=(Foo&& rhs){
        std::cout<<"Move Assignment"<<"\n";
        if(rhs.i != nullptr){
            i = rhs.i;
            rhs.i = nullptr;
        }
        return *this;
    }


    ~Foo(){
        std::cout<<"Destrcutor"<<"\n";
        if(i != nullptr){
            delete i;

        }
    }

    int* i = nullptr;
};

int main(){

    Foo f1;
    // Copy Assignment
    {
        Foo f2;
        f2.i = new int(10);
        f1 = f2;	
    }
    std::cout<<"\n";
    // Move Assignment
    {
        Foo f2;
        f2.i = new int(10);
        f1 = std::move(f2);	
    }
}