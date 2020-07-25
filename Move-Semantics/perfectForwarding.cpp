#include <iostream>
#include <vector>

class Foo{
public:
    Foo() = default;

    Foo(int i):
        m_i(i)
    {}

    Foo(int i, bool b):
        m_i(i), m_b(b)
    {}

    Foo(int i, bool b, float f):
        m_i(i), m_b(b), m_f(f)
    {}

    int m_i;
    bool m_b;
    float m_f;
};

class Bar{
public:
    template<typename ... Args>
    void AddFoo(Args&& ... args){
        vec.emplace_back(std::forward<Args>(args) ...);
    }

private:
    std::vector<Foo> vec; 
};

int main(){

    Bar B;
    B.AddFoo(1);
    B.AddFoo(2, true);
    B.AddFoo(3, false, 3.142);
}