#pragma once

#include "IOperation.h"
#include "OperatorTools.h"

namespace Operations
{
    template<class T>
    class Multiplier;
}

template<class T>
class Operations::Multiplier : public Operations::Interfaces::IOperation<T>
{
    using OperationTools = OperatorTools<T, 1>;

    OperationTools* _tools;
public:
    Multiplier(OperationTools& tools)
    {
        _tools = &tools;
    }

    // Inherited via IOperation
    virtual void ExecuteOperation(T& object) override
    {
        object += _tools[0]; // TEST
    }
};