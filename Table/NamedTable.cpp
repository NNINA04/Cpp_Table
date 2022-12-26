#include "pch.h"

Table::NamedTable::Row& Table::NamedTable::GetRowByName(const string& rowName)
{
    if (rowName == UnnamedField)
        throw std::exception();

    size_t rowIndex = FindIndexOfElement(_rowNames, rowName);

    return (*this)[rowIndex];
}

Table::NamedTable::Col& Table::NamedTable::GetColumnByName(const string& colName)
{
    if (colName == UnnamedField)
        throw std::exception();

    if (_cols.contains(colName))
        return _cols[colName];

    size_t colIndex = FindIndexOfElement(_colNames, colName);
    Col col = GetColumnByIndex(colIndex); // Почему-то тут вылетает ошибка

    return _cols[colName] = col; // Caching into the map
}

Table::NamedTable::Row& Table::NamedTable::GetRowByIndex(const size_t rowIndex)
{
    return (*this)[rowIndex];
}

Table::NamedTable::Col& Table::NamedTable::GetColumnByIndex(const size_t colIndex)
{
    string strColIndex = std::to_string(colIndex);
    if (_cols.contains(strColIndex))
        return _cols[strColIndex];

    Col col;
    for (size_t i = 0; i < this->Rows(); i++)
        col.push_back((*this)[i][colIndex]);

    return _cols[strColIndex] = col;
}

void Table::NamedTable::HandleField(RowNames& field, const size_t& expectedSize)
{
    for (size_t i = field.size(); i < expectedSize; i++)
        field.push_back(UnnamedField);
}

template<class T>
static size_t Table::NamedTable::FindIndexOfElement(std::vector<T> arr, T element)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        const T& currElem = arr[i];
        if (currElem == element)
            return i;
    }
    return -1;
}