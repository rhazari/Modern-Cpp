#include <iostream>

using namespace std;

class Shallow{
    int _x;
    int* _y;
public:
    Shallow(){
        _y = new int;
    }

    Shallow(int x, int y){
        _x = x;
        _y = new int;
        *_y = y;
    }

    void setX(int x){
        _x = x;
    }

    void setY(int y){
        *_y = y;
    }

    Shallow(const Shallow& s): _x(s._x), _y(s._y){}

    void display() const{
        cout<<_x<<" "<<*_y<<"\n";
    }
};

class Deep{
    int _x;
    int* _y;
public:
    Deep(){
        _y = new int;
    }

    Deep(int x, int y){
        _x = x;
        _y = new int;
        *_y = y;
    }

    void setX(int x){
        _x = x;
    }

    void setY(int y){
        *_y = y;
    }

    int getX() const{
        return _x;
    }

    int getY() const{
        return *_y;
    }

    Deep(const Deep& s){
        _x = s._x;
        _y = new int;
        *_y = s.getY();
    }

    void display() const{
        cout<<_x<<" "<<*_y<<"\n";
    }
};



int main(){

    Shallow s1(10, 12);
    Shallow s2(s1);

    s1.display();
    s2.display();

    s1.setY(21);

    s1.display();
    s2.display();

    Deep s3(5, 6);
    Deep s4(s3);

    s3.display();
    s4.display();

    s3.setY(11);

    s3.display();
    s4.display();

}