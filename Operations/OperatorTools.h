#pragma once

#include <array>
#include <exception>

namespace Operations
{
    template<class T, size_t TSize>
    class OperatorTools;
}

template<class T, size_t TSize>
class Operations::OperatorTools
{
    using Tools = std::array<T, TSize>;

    char _operator;
    Tools _tools;
public:
    OperatorTools(char operator_, Tools tools)
    {
        _operator = operator_;
        _tools = tools;
    }

    inline constexpr char& GetOperator()
    {
        return _operator;
    }

    const T& operator[](const size_t& index)
    {
        bool incorrectIndex = index < 0 || index >= TSize;
        if (incorrectIndex)
            throw std::exception();
        return _tools[index];
    }
};