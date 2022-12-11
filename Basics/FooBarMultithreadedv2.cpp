#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

class FooBar {
private:
    int n;
    mutex mx_;
    condition_variable cv_;
    bool print_ = true;

    void printFoo(){
        cout<<"Foo ";
    }

    void printBar(){
        cout<<"Bar ";
    }

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo() {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lk(mx_);
            cv_.wait(lk, [this]{
                return print_;
            });
            print_ = false;
            cv_.notify_all();
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
        }
    }

    void bar() {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lk(mx_);
            cv_.wait(lk, [this]{
                return !print_;
            });
            print_ = true;
            cv_.notify_all();
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
        }
    }
};

int main(){
    FooBar foobar(15);
    thread th1(&FooBar::foo, &foobar);
    thread th2(&FooBar::bar, &foobar);

    th1.join();
    th2.join();
}
