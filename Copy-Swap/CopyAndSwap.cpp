#include <vector>

struct Widget{
    std::vector<int> _vec;

    Widget() = default;
    ~Widget() = default;

    Widget(const Widget&) = default;
    Widget(Widget&&) = default;

    void swap(Widget &other) noexcept{
        // enable ADL; useful for custom types
        using std::swap;
        // Swap all members
        swap(_vec, other._vec);
    }

    Widget& operator =(const Widget& other){
        // We make a temporary copy here so that any exception during 
        // this operation will not affect the original object
        Widget temp{other};
        temp.swap(*this);
        return *this;
    }

    Widget& operator =(Widget&&) = default;
};


// Free function for ADL
void swap(Widget& a, Widget& b){
    a.swap(b);
}

int main(){
    return 0;
}