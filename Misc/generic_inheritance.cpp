#include <cassert>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>

// using object_t = int;

class object_t;

template<typename T>
void draw(const T& x, std::ostream& out, size_t position){
    out<<std::string(position, ' ')<<x<<'\n';
}

class object_t{
public:
    template <typename T>
    object_t(T x) : _self(new model<T>(std::move(x)))
    { }

    // object_t(const object_t& x) 
    //     :_self(x._self->copy())
    //     {}

    // object_t(object_t&& x) noexcept = default;

    // object_t& operator=(const object_t& x){ 
    //     object_t tmp(x); 
    //     *this = std::move(tmp); 
    //     return *this; 
    // }

    // object_t& operator=(object_t&&) noexcept = default;

    friend void draw(const object_t& obj, std::ostream& out, size_t position){
        obj._self->_draw(out, position);
    }

private:
    struct concept_t {
        virtual ~concept_t() = default;
//        virtual concept_t* copy_() const = 0;
        virtual void _draw(std::ostream&, size_t) const = 0;
    };

    template <typename T>
    struct model : concept_t {
        model(T x) : _data(std::move(x)) { }

//        concept_t* copy_() const
//        {
//            return new model(*this);
//        }

        void _draw(std::ostream& out, size_t position) const
        {
            draw(_data, out, position);
        }

        T _data;
    };

    std::shared_ptr<const concept_t> _self;
};


using document_t = std::vector<object_t>;

void draw(const document_t& x, std::ostream& out, size_t position){
    out<<std::string(position,' ')<<"<document>"<<'\n';
    for(const auto& var: x){
        draw(var, out, position+2);
    }
    out<<std::string(position,' ')<<"</document>"<<'\n';
}

class my_class_t {
    /* ... */
};

void draw(const my_class_t&, std::ostream& out, size_t position)
{
    out << std::string(position, ' ') << "my_class_t" <<'\n';
}

int main(){
    document_t document;

    document.reserve(5);

    document.emplace_back(0);
    document.emplace_back(std::string("Hello"));
    document.emplace_back(document);
    document.emplace_back(my_class_t{});

    // reverse(document.begin(), document.end());

    draw(document, std::cout, 0);
}