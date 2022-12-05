#pragma once

#include <string>
#include "IDataType.h"
#include "Operations/IOperation.h"

namespace DataTypes
{
    template<class TChild>
    class BaseDataType;
}

template<class TChild>
class DataTypes::BaseDataType : 
    public DataTypes::Interfaces::IDataType
    //, public Operations::Interfaces::IOperation<TChild>
{
    using string = std::string;

    string _object;
protected:
    BaseDataType(string& object)
    {
        _object = object;
    }
public:
    inline const string& GetObject()
    {
        return _object;
    };

    const string& SetObject(string& newObject)
    {
        Validate(newObject);
        _object = newObject;
    }

    void Execute(Operations::Interfaces::IOperation<string>& object)
    {
        object.ExecuteOperation(_object);
    }

    // Inherited via ITableDataType
    virtual void Validate(const string& object) = 0;
};