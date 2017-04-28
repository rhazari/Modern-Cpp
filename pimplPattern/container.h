#include <memory>
using namespace std;

class Container
{
public:
	Container(const size_t size);

	Container(const Container& other);

	Container& operator=(const Container& other);

	int& operator[] (const int index);

	const int& operator[] (const int index) const;

private:
	class Impl_;
	unique_ptr<Impl_> pimpl;
};

#include "container_impl.h"