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
    using string = std::string;
public:
    using Row = std::vector<DataTypes::BaseDataType<std::string>*>;
    using Col = Row;
    using Body = std::vector<Row>;
private:
    Body _body;
public:
    TableBody(Body& body)
    {
        Validate(body);
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
    void Validate(Body& body);
};
