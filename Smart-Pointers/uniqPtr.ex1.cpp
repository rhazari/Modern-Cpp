#include <iostream>
#include <memory>
#include <cassert>

int main(){

    std::unique_ptr<int> p1, p2;
    int *p3 = nullptr;

    p1 = std::make_unique<int>(10);
    assert(p1);
    assert(!p2);
    p3 = p1.get();
    std::cout<<*p3<<"\n";
    p3 = nullptr;

    p2 = move(p1);
    assert(!p1);
    assert(p2);

    p3 = p2.release();
    std::cout<<*p3<<"\n";
    assert(!p2);

    delete p3;
}