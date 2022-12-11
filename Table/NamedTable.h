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
    using Col = Row;
    using Body = Table::TableBody;
    using RowNames = Field;
    using ColNames = Field;
private:
    const string UnnamedField = "Unnamed";

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

    Row& GetRow(const string& rowName)
    {
        if (rowName == UnnamedField)
            throw std::exception();

        size_t rowIndex = FindIndexOfElement(_rowNames, rowName);
        if (rowIndex == -1)
            throw std::exception();

        return (*this)[rowIndex];
    }

    Col& GetColumn(const string& colName)
    {
        if(colName == UnnamedField)
            throw std::exception();

        size_t colIndex = FindIndexOfElement(_colNames, colName);
        if (colIndex == -1)
            throw std::exception();

        Col col = GetColumnByIndex(colIndex);

        _cols[colName] = col;
        return col;
    }
private:
    void HandleField(RowNames& field, const size_t& expectedSize)
    {
        size_t fSize = field.size();

        for (size_t i = fSize; i < expectedSize; i++)
            field.push_back(UnnamedField);
    }

    template<class T>
    size_t FindIndexOfElement(std::vector<T> arr, T element)
    {
        for (size_t i = 0; i < arr.size(); i++)
        {
            const T& currElem = arr[i];
            if (currElem == element)
                return i;
        }
        return -1;
    }

    Col& GetColumnByIndex(const size_t colIndex)
    {
        Col col;
        for (size_t i = 0; i < this->Rows(); i++)
            col.push_back((*this)[i][colIndex]);
        return col;
    }
};