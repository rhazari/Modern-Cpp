#include <iostream>

template <class T>
class Shape{
public:
    void interface(){
        static_cast<T*>(this)->draw();
    }

    void draw(){
        std::cout<<"Draw from Base\n";
    }
};

class Square: public Shape<Square>{
public:
    void draw() {
        std::cout<<"Draw from Square\n";
    }
};

class Rectangle: public Shape<Rectangle>{
public:
    void draw() {
        std::cout<<"Draw from Rectangle\n";
        
    }
};

class Triangle: public Shape<Triangle>{
public:
    void draw() {
        std::cout<<"Draw from Triangle\n";
    }
};

struct Polygon: Shape<Polygon> {};

template <class T>
void execute(T& base){
    base.interface();
}

int main() {
    Square s;
    Rectangle r;
    Triangle t;
    Polygon p;

    execute(s);
    execute(r);
    execute(t);
    execute(p);
}