#include <iostream>
#include <memory>
#include <cassert>
#include <vector>

class Base{
public:
    Base(){std::cout<<"Base Constructor"<<"\n";}
    virtual ~Base(){std::cout<<"Base Destructor"<<"\n";}
    virtual void func(){std::cout<<"Base::func"<<"\n";}
};

class Derived:public Base{
public:
    Derived(){std::cout<<"Derived Constructor"<<"\n";}
    ~Derived(){std::cout<<"Derived Destructor"<<"\n";}
    void func() override{std::cout<<"Derived::func"<<"\n";}
};

std::unique_ptr<Derived> movePointer(std::unique_ptr<Derived> ptr){
    ptr->func();
    return ptr;
}

int main(){

    {
        auto p1 = std::make_unique<Derived>();
        // Unique Pointers can only be moved; not copied
        //auto p2 = movePointer(p1);
        auto p3 = movePointer(std::move(p1));

        assert(!p1);
        p3->func();
    }
    std::cout<<"\n";
    std::cout<<"\n";
    {
        std::unique_ptr<Base> p1 = std::make_unique<Derived>();
        p1->func();
        std::vector<std::unique_ptr<Base>> myVec;
        myVec.push_back(std::move(p1));
        myVec.push_back(std::make_unique<Derived>());
        myVec.emplace_back(std::make_unique<Derived>());

        for(const auto& p: myVec)
            p->func();
    }
}