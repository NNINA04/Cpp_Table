#pragma once

// Make a condition to pass in ctor only the same count of elements in vectors
template<class TCols>
class Table
{
    using Rows = vector<string>;
    using Cols = vector<TCols>;

    Rows* _rows;
    Cols* _cols;
public:
    Table(const Rows& rows, const Cols& cols) noexcept
    {
        _rows = &rows;
        _cols = &cols;
    }


};