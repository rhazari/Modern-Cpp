#include <iostream>
#include <ctime>
#include <memory>
#include <algorithm>

template <class T>
class Vector{
    int _size;
    std::unique_ptr<T[]> _arr = nullptr;

public:
    Vector(int size){
        _size = size;
        _arr = std::make_unique<T[]>(_size);
        for(int k = 0; k < _size; ++k){
            _arr[k] = rand()%_size;
        }
    }

    Vector(const Vector& vec){
        std::cout<<"Copy Constructor\n";
        _size = vec._size;
        _arr = std::make_unique<T[]>(_size);
        for(int k = 0; k < _size; ++k){
            _arr[k] = vec._arr[k];
        }
    }

    Vector(Vector&& vec) noexcept {
        std::cout<<"Move Constructor\n";
        _size = vec._size;
        _arr = std::move(vec._arr);
        vec._arr = nullptr;
    }

    void displayContent(){
        for(int k = 0; k <_size; ++k){
            std::cout<<_arr[k]<<" ";
        }
        std::cout<<"\n";
    }
};

// Reference Collapsing Rules (C++ 11)
// - T& &   ==> T&
// - T& &&  ==> T&
// - T&& &  ==> T&
// - T&& && ===> T&&

// Implementation of std::forward()
// template <class T>
// T&& forward(typename remove_reference<T>:: type& arg){
//     return static_cast<T&&>(arg);
// }

template <class T, class U>
Vector<T> relay(U&& arg){
    return Vector<T>(std::forward<U>(arg));
}

int main(){
    std::cout<<"Original Content\n";
    Vector<int> vec(10);
    vec.displayContent();

    Vector<int> vec1 = relay<int>(vec);
    vec1.displayContent();

    Vector<int> vec2 = relay<int>(std::move(vec));
    vec2.displayContent();
}