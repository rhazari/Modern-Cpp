#include <memory>

class Container {
public:
    Container(const size_t size);

    Container(const Container& other);

    ~Container();

    Container& operator=(const Container& other);

    int& operator[] (const int index);

    const int& operator[] (const int index) const;

private:
    class _Impl;
    std::unique_ptr<_Impl> _pimpl;
};

#include "containerImpl.h"