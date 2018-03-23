#include <iostream>
#include <string>
#include <initializer_list>

using namespace std;

template <class T>
void func(T t) {
    cout << t <<" ";
}

template <class T>
void func2( initializer_list<T> list ){
    for( auto elem : list ){
        cout << elem <<" ";
    }
}

template<class T, class... Args>
void func(T t, Args... args) { // recursive variadic function
    cout << t <<" ";

    func(args...) ;
}

template <class T>
T adder(T v){
    cout << __PRETTY_FUNCTION__ << endl;
    return v;
}

template<class T, class... Args>
T adder(T first, Args ...args){
    cout << __PRETTY_FUNCTION__ << endl;
    return first + adder(args...);
}

int main(){
    string str1( "Hello" ), str2( "world" );
    cout<<endl;
    func(1,2.5,'a',str1);
    cout<<endl;
    func2( {10, 20, 30, 40 }) ;
    cout<<endl;
    func2( {str1, str2 } ) ;
    cout<<endl;

    auto sum = adder(1, 2.3, 3, 8, 7);
    cout<<sum<<endl;

    string s1 = "x", s2 = "aa", s3 = "bb", s4 = "yy";
    auto ssum = adder(s1, s2, s3, s4);
    cout<<ssum<<endl;

    return 0;
} 