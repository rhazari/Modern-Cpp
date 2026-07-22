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

    // Constructor with initial size and value
    MyVector(size_t size, const T& value = T()) : data_(new T[size]), size_(size), capacity_(size) {
        std::fill_n(data_, size_, value);
    }

    // Initializer List Constructor
    MyVector(std::initializer_list<T> init) 
        : data_(new T[init.size()]), size_(init.size()), capacity_(init.size()) {
        std::copy(init.begin(), init.end(), data_);
    }

    // Copy Constructor
    MyVector(const MyVector& other)
        : data_(new T[other.capacity_]), size_(other.size_), capacity_(other.capacity_) {
        std::copy(other.data_, other.data_ + size_, data_);
    }

    // Move Constructor
    MyVector(MyVector&& other) noexcept
        : data_(other.data_), size_(other.size_), capacity_(other.capacity_) {
        other.data_ = nullptr;
        other.size_ = other.capacity_ = 0;
    }


    // Destructor
    ~MyVector() {
        delete[] data_;
    }

     // Copy Assignment Operator
    MyVector& operator=(const MyVector& other) {
        if (this != &other) {
            MyVector temp(other);
            swap(temp);
        }
        return *this;
    }

    // Move Assignment Operator
    MyVector& operator=(MyVector&& other) noexcept {
        if (this != &other) {
            delete[] data_;
            data_ = other.data_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            other.data_ = nullptr;
            other.size_ = other.capacity_ = 0;
        }
        return *this;
    }

    void swap(MyVector& other) noexcept {
        std::swap(data_, other.data_);
        std::swap(size_, other.size_);
        std::swap(capacity_, other.capacity_);
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

     // Access operator with bounds checking
    T& operator[](size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }

    const T& operator[](size_t index) const {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }

    // Size and Capacity getters
    size_t size() const { return size_; }
    size_t capacity() const { return capacity_; }
    bool empty() const { return size_ == 0; }

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

    // Resize the vector
    void resize(size_t new_size, const T& value = T()) {
        if (new_size > capacity_) {
            reserve(new_size);
        }
        if (new_size > size_) {
            std::fill(data_ + size_, data_ + new_size, value);
        }
        size_ = new_size;
    }

    // Clear the vector
    void clear() {
        size_ = 0;
    }
};

int main() {
    MyVector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    std::cout << "Vector Size: " << vec.size() << "\n";
    std::cout << "Element at index 1: " << vec[1] << "\n";


    // Test various features
    MyVector<int> vec1 = {1, 2, 3};  // initializer list
    vec1.push_back(4);
    
    MyVector<int> vec2 = vec1;  // copy constructor
    vec2[0] = 10;
    
    MyVector<int> vec3 = std::move(vec1);  // move constructor
    
    try {
        std::cout << vec3[10];  // throws out_of_range
    } catch (const std::out_of_range& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
    
    return 0;
}
