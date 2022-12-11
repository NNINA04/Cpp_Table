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
    public DataTypes::Interfaces::IMultiplyable<std::string>,
    public DataTypes::Interfaces::ISummable<std::string>
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
        for (const char& ch : object)
        {
            if (isdigit(ch) == false)
                throw std::exception("It's not a Integer");
        }
    }

    // Inherited via IMultiplyable
    virtual string Multiply(const string& left, const string& right) override
    {
        int n = left.size();
        int m = right.size();
        string ans(n + m, '0');
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--) {
                int p = (left[i] - '0') * (right[j] - '0') + (ans[i + j + 1] - '0');
                ans[i + j + 1] = p % 10 + '0';
                ans[i + j] += p / 10;
            }
        }
        for (int i = 0; i < m + n; i++)
            if (ans[i] != '0')return ans.substr(i);
        return "0";
    }

    // Inherited via ISummable
    virtual string Sum(const string& left, const string& right) override
    {
        string a = left;
        string b = right;

        if (a.size() < b.size())
            swap(a, b);

        int j = a.size() - 1;
        for (int i = b.size() - 1; i >= 0; i--, j--)
            a[j] += (b[i] - '0');

        for (int i = a.size() - 1; i > 0; i--)
        {
            if (a[i] > '9')
            {
                int d = a[i] - '0';
                a[i - 1] = ((a[i - 1] - '0') + d / 10) + '0';
                a[i] = (d % 10) + '0';
            }
        }
        if (a[0] > '9')
        {
            string k;
            k += a[0];
            a[0] = ((a[0] - '0') % 10) + '0';
            k[0] = ((k[0] - '0') / 10) + '0';
            a = k + a;
        }
        return a;
    }
};