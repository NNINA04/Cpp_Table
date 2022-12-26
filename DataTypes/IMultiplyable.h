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
    virtual T* operator*(const T& other) = 0;
};