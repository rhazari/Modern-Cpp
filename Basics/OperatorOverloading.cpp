#include <iostream>

using namespace std;

class Complex{
    int _x, _y;
public:
    Complex(): _x(0), _y(0){};

    Complex(int x, int y): _x(x), _y(y){}

    Complex operator+ (const Complex& c){
        Complex temp;
        temp._x = this->_x + c._x;
        temp._y = this->_y + c._y;
        return temp;
    }

    void display() const{
        cout<<_x<<": i"<<_y<<"\n";
    }
};

int main(){

    Complex c1(10, 12);
    Complex c2(21, 4);

    Complex c3 = c1 + c2;
    c3.display();
}