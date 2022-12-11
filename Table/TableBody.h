#pragma once

#include <vector>
#include <map>
#include "DataTypes/BaseDataType.h"

namespace Table
{
    class TableBody;
}

class Table::TableBody
{
protected:
    using string = std::string;
    using Row = std::vector<DataTypes::BaseDataType<std::string>*>;
public:
    using Body = std::vector<Row>;
private:
    Body _body;
public:
    TableBody(Body& body)
    {
        _body = body;
    }

    inline Row& operator[](const size_t& index)
    {
        return _body.at(index);
    }

    inline size_t Rows()
    {
        return _body.size();
    }

    inline size_t Cols()
    {
        return _body[0].size();
    }
private:
    void Validate(Body& body)
    {
        if (body.empty())
            throw std::exception();

        size_t firstVectorSize = body[0].size();

        for (size_t i = 1; i < body.size(); i++)
        {
            size_t currVectorSize = body[i].size();
            if(firstVectorSize != currVectorSize)
                throw std::exception();
        }
    }
};