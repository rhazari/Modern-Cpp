#include <iostream>
#include <stdexcept>
#include <algorithm>

template <typename T>
class MyVector {
private:
    T* data_;
    size_t size_;
    size_t capacity_;

public:
    // Default Constructor
    MyVector() : data_(nullptr), size_(0), capacity_(0) {}

    // Destructor
    ~MyVector() {
        delete[] data_;
    }

    // Add element to the end
    void push_back(const T& value) {
        if (size_ == capacity_) {
            size_t new_capacity = (capacity_ == 0) ? 1 : capacity_ * 2;
            reserve(new_capacity);
        }
        data_[size_++] = value;
    }

    // Remove the last element
    void pop_back() {
        if (size_ > 0) {
            size_--;
        }
    }

    // Access operator
    T& operator[](size_t index) {
        return data_[index];
    }

    const T& operator[](size_t index) const {
        return data_[index];
    }

    // Size and Capacity getters
    size_t size() const { return size_; }
    size_t capacity() const { return capacity_; }

    // Resize the vector's capacity
    void reserve(size_t new_capacity) {
        if (new_capacity <= capacity_) return;

        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < size_; i++) {
            new_data[i] = data_[i];
        }

        delete[] data_;
        data_ = new_data;
        capacity_ = new_capacity;
    }
};

int main() {
    MyVector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    std::cout << "Vector Size: " << vec.size() << "\n";
    std::cout << "Element at index 1: " << vec[1] << "\n";

    return 0;
}
