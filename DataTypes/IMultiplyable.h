#pragma once

namespace DataTypes
{
    namespace Interfaces
    {
        template<class T>
        class IMultiplyable;
    }
}

template<class T>
class DataTypes::Interfaces::IMultiplyable
{
public:
    virtual T Multiply(const T& left, const T& right) = 0;
};