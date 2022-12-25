#include <iostream>
#include <cstring>
#include <functional>
#include <vector>
#include <algorithm>

#define SIZE 10000

class Widget{
private:
    int *_arr;
public:

    Widget()
        : _arr(new int[SIZE]){}

    ~Widget(){
        delete []_arr;
    }
    
    Widget(const Widget& other)
        : _arr(new int[SIZE]){
        std::cout<<"Copy constructor\n";
        std::memcpy(_arr, other._arr, SIZE * sizeof(int));
    }

    Widget& operator =(const Widget& other){
        if(this == &other){
            return *this;
        }
        std::cout<<"Copy assignment\n";
        std::memcpy(_arr, other._arr, SIZE * sizeof(int));
        return *this;
    }

    Widget(Widget&& other): _arr(std::move(other._arr)){
        std::cout<<"Move constructor\n";
    }

    Widget& operator =(Widget&& other){
        if(this == &other){
            return *this;
        }

        _arr = std::move(other._arr);
        std::cout<<"Move assignment\n";
        return *this;
    }

    bool operator <(const Widget &other) const{
        return std::less<const Widget*>()(this, &other);
    }
};

int main(){
    std::vector<Widget> vec(10);
    std::sort(std::begin(vec), std::end(vec));
    return 0;
}