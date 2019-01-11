#include "../header/Car.h"
#include "../header/V8Engine.h"

#include <memory>

class MockEngine: public IEngine{
    public:
        void start() override {
            std::cout<<"Start the Mock Engine!"<<"\n";
        }
        void stop() override {
            std::cout<<"Stop the Mock Engine!"<<"\n";
        }
};

void Test(){
    Car car(std::make_unique<MockEngine>());

    car.Drive();
}

int main(){
    Car car(std::make_unique<V8Engine>());

    car.Drive();

    Test();
}