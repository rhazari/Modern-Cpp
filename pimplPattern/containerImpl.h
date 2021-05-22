#include <memory>
#include <vector>

class Container::_Impl
{
public:
    _Impl(const size_t size){
        _vec.resize(size);
    }

    std::vector<int> _vec;
};

Container::Container(const size_t size):
    _pimpl (std::make_unique<_Impl>(size)){}

Container::Container(const Container& other):
    _pimpl (std::make_unique<_Impl>(other._pimpl->_vec.size())) {
        _pimpl->_vec = other._pimpl->_vec;
    }
    
Container::~Container() = default;

Container& Container::operator=(const Container& other){
    _pimpl->_vec = other._pimpl->_vec;
    return *this;
}

int& Container::operator[](const int index){
    return _pimpl->_vec[index];
}

const int& Container::operator[](const int index) const{
    return _pimpl->_vec[index];
}