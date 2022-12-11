#pragma once

namespace DataTypes
{
    namespace Interfaces
    {
        template<class T>
        class ISummable;
    }
}

template<class T>
class DataTypes::Interfaces::ISummable
{
public:
    virtual T Sum(const T& left, const T& right) = 0;
};