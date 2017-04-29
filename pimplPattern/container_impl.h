#include <memory>
#include <vector>

using namespace std;

class Container::Impl_
{
public:
	Impl_(const size_t size){
		vec.resize(size);
	}

	vector<int> vec;
};

Container::Container(const size_t size):
	pimpl (make_unique<Impl_>(size)){}

Container::Container(const Container& other):
	pimpl (make_unique<Impl_>(other.pimpl->vec.size()))
	{
		pimpl->vec = other.pimpl->vec;
	}
	
Container::~Container() = default;

Container& Container::operator=(const Container& other)
{
	pimpl->vec = other.pimpl->vec;
	return *this;
}

int& Container::operator[](const int index)
{
	return pimpl->vec[index];
}

const int& Container::operator[](const int index) const
{
	return pimpl->vec[index];
}