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

    Vector& operator= (const Vector& vec) {
        std::cout<<"Copy Assignment\n";
        if(this != &vec){
            if(_size != vec._size){
                _size = vec._size;
                _arr.reset(new T[_size]);
            }
            std::copy(&vec._arr[0], &vec._arr[0] + _size, &_arr[0]);
        }
        return *this;
    }

    Vector(Vector&& vec) noexcept {
        std::cout<<"Move Constructor\n";
        _size = vec._size;
        _arr = std::move(vec._arr);
        vec._arr = nullptr;
    }

    Vector& operator= (Vector&& vec) noexcept {
        std::cout<<"Move Assignment\n";
        _size = vec._size;
        _arr = std::move(vec._arr);
        vec._arr = nullptr;
        return *this;
    }

    void displayContent(){
        for(int k = 0; k <_size; ++k){
            std::cout<<_arr[k]<<" ";
        }
        std::cout<<"\n";
    }
};

int main(){
    {
        std::cout<<"Original Content\n";
        Vector<int> vec(10);
        vec.displayContent();

        Vector<int> vec1(vec);
        vec1.displayContent();

        Vector<int> vec2(std::move(vec));
        vec2.displayContent();
    }
    std::cout<<"\n =========== \n";
    {
        std::cout<<"Original Content\n";
        Vector<int> vec(10);
        vec.displayContent();
        Vector<int> vec1(5);
        vec1 = vec;
        vec1.displayContent();
        Vector<int> vec2(5);
        vec2 = std::move(vec);
        vec2.displayContent();
    }
}

