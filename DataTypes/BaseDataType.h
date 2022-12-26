#pragma once

#include <string>
#include "IDataTypeValidator.h"

namespace DataTypes
{
    template<class T>
    class BaseDataType;
}

template<class T>
class DataTypes::BaseDataType : public DataTypes::Interfaces::IDataTypeValidator<T>
{
    T _value;
protected:
    BaseDataType(T& value)
    {
        _value = value;
    }
public:
    inline const T& GetObject() const
    {
        return _value;
    };

    const void SetObject(const T& newObject)
    {
        Validate(newObject);
        _value = newObject;
    }

    // Inherited via IDataTypeValidator
    virtual void Validate(const T& value) const = 0;
};