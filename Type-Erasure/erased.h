# https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Type_Erasure
#include <memory>

class TypeErased{
public:
    template<typename T>
    TypeErased(T&& value){
        *this = value;
    }

    template<typename T>
    TypeErased& operator=(T&& value){
         _value.reset(new Model<T>(value));
         return *this;
    }

    void printName () const{
         _value->printName();
    }

private:
    struct Concept{
        virtual ~Concept(){}
        virtual void printName() const = 0;
    };

    template<typename T>
    struct Model: Concept {
        Model(T const& value): _val(value){}

        void printName() const override{
            _val.printName();
        }

        T _val;
    };

private:
    std::unique_ptr<Concept>  _value;
};