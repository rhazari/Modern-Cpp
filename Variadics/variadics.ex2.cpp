#include <iostream>
#include <string>
#include <initializer_list>

template <class T>
void func(T t) {
    std::cout << t <<" ";
}

template <class T>
void func2( initializer_list<T> list ){
    for(const auto& elem : list ){
        std::cout << elem <<" ";
    }
}

template<class T, class... Args>
void func(T t, Args... args) { // recursive variadic function
    std::cout << t <<" ";

    func(args...) ;
}

template <class T>
T adder(T v){
    std::cout << __PRETTY_FUNCTION__ << "\n";
    return v;
}

template<class T, class... Args>
T adder(T first, Args ...args){
    std::cout << __PRETTY_FUNCTION__ << "\n";
    return first + adder(args...);
}

int main(){
    std::string str1( "Hello" ), str2( "world" );
    std::cout<<"\n";
    func(1,2.5,'a',str1);
    std::cout<<"\n";
    func2( {10, 20, 30, 40 }) ;
    std::cout<<"\n";
    func2( {str1, str2 } ) ;
    std::cout<<"\n";

    auto sum = adder(1, 2.3, 3, 8, 7);
    std::cout<<sum<<"\n";

    std::string s1 = "x", s2 = "aa", s3 = "bb", s4 = "yy";
    auto ssum = adder(s1, s2, s3, s4);
    std::cout<<ssum<<"\n";
} 