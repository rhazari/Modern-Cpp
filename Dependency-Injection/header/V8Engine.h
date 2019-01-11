#pragma once
#include "IEngine.h"
#include <iostream>
#include <memory>

class V8Engine: public IEngine{
    public:
        void start() override;

        void stop() override;
};

// std::unique_ptr<IEngine> makeEngine(){
//     return std::make_unique<V8Engine>();
// }

