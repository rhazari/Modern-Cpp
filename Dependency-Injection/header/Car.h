#pragma once
#include "IEngine.h"
#include <memory>

class Car{
    public:
        Car(std::unique_ptr<IEngine>&& engine)
            :m_engine(std::move(engine)){}
        
        void Drive();
    private:
        std::unique_ptr<IEngine> m_engine;
};
