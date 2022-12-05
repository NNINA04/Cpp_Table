#pragma once

#include <exception>
#include "BaseDataType.h"

namespace DataTypes
{
    class Integer;
}

class DataTypes::Integer : public BaseDataType<Integer>
{
    using Base = BaseDataType<Integer>;
    using string = std::string;
    using exception = std::exception;

public:
    Integer(string& object) : Base(object) 
    {
        Validate(object);
    }

    // Inherited via BaseTableDataType
    virtual void Validate(const string& object) override
    {
        for (const char& ch : object)
        {
            if (isdigit(ch) == false)
                throw exception("It's not a Integer");
        }
    }
};