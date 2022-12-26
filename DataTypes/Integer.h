#pragma once

#include <exception>
#include <type_traits>
#include "BaseDataType.h"
#include "IMultiplyable.h"
#include "ISummable.h"  

namespace DataTypes
{
    class Integer;
}

class DataTypes::Integer :
    public BaseDataType<std::string>,
    public DataTypes::Interfaces::ISummable<Integer>,
    public DataTypes::Interfaces::IMultiplyable<Integer>
{
    using string = std::string;
    using Base = BaseDataType<string>;
public:
    Integer(string object) : Base(object)
    {
        Validate(object);
    }

    // Inherited via BaseTableDataType
    virtual void Validate(const string& object) const override
    {
        char firstCh = object[0];
        bool negativeOrPositive = firstCh == '-' || isdigit(firstCh);
        if (negativeOrPositive == false)
            throw std::exception("It's not an Integer or negative symbol");

        for (size_t i = 1; i < object.size(); i++)
        {
            char currentCh = object[i];
            if (isdigit(currentCh) == false)
                throw std::exception("It's not an Integer");
        }
    }

    // Inherited via ISummable
    Integer* operator+(const Integer& other)
    {
        string firstStrNumb = this->GetObject();
        string secondStrNumb = other.GetObject();

        int firstNumb = std::stoi(firstStrNumb);
        int secondNumb = std::stoi(secondStrNumb);

        int sum = firstNumb + secondNumb;

        string strSum = std::to_string(sum);

        return new Integer(strSum);
    }

    // Inherited via IMultiplyable
    Integer* operator*(const Integer& other)
    {
        string firstStrNumb = this->GetObject();
        string secondStrNumb = other.GetObject();

        int firstNumb = std::stoi(firstStrNumb);
        int secondNumb = std::stoi(secondStrNumb);

        int mult = firstNumb * secondNumb;

        string strMult = std::to_string(mult);

        return new Integer(strMult);
    }
};
