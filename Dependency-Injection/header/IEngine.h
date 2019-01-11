#pragma once
#include <memory>

class IEngine{
    public:
        virtual void start() = 0;
        virtual void stop() = 0;
        virtual ~IEngine() = default;
};

// std::unique_ptr<IEngine> makeEngine();