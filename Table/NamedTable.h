#pragma once

#include <vector>
#include <map>
#include "TableBody.h"

namespace Table
{
    class NamedTable;
}

class Table::NamedTable : public Table::TableBody
{
    using string = std::string;
    using Base = Table::TableBody;
    using Field = std::vector<string>;
    using RowNames = Field;
    using ColNames = Field;
public:
    using Row = Base::Row;
    using Col = Base::Col;
    using Body = Table::TableBody;
    using RowNames = Field;
    using ColNames = Field;
private:
    static const string UnnamedField;

    RowNames _rowNames;
    ColNames _colNames;

    std::map<const string, Col> _cols;
public:
    NamedTable(Body& body, RowNames& rows, ColNames& cols) : Base(body)
    {
        HandleField(rows, Base::Rows());
        HandleField(cols, Base::Cols());
        _rowNames = rows;
        _colNames = cols;
    }

    Row& GetRowByName(const string& rowName);

    Col& GetColumnByName(const string& colName);

    Row& GetRowByIndex(const size_t rowIndex);

    Col& GetColumnByIndex(const size_t colIndex);
private:
    static void HandleField(RowNames& field, const size_t& expectedSize);

    template<class T>
    static size_t FindIndexOfElement(std::vector<T> arr, T element);
};

const std::string Table::NamedTable::UnnamedField = "Unnamed";