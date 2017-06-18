#include <iostream>
#include <memory>

using namespace std;

int main()
{
    // OLD, problem with dangling pointer
    // PROBLEM: ref will point to undefined data!
    int* ptr = new int(10);
    int* ref = ptr;
    delete ptr;

    // empty definition
    shared_ptr<int> sptr;

    // takes ownership of pointer
    sptr.reset(new int);
    *sptr = 10;

    // get pointer to data without taking ownership
    weak_ptr<int> weak1 = sptr;

    // deletes managed object, acquires new pointer
    sptr.reset(new int);
    *sptr = 5;

    // get pointer to new data without taking ownership
    weak_ptr<int> weak2 = sptr;

    // weak1 is expired!

    if(auto tmp = weak1.lock())
        cout << *tmp << endl;
    else
        cout << "weak1 is expired"<<endl;

    // weak2 points to new data (5)
    if(auto tmp = weak2.lock())
        cout << *tmp <<endl;
    else
        cout << "weak2 is expired"<<endl;

    return 0;
}