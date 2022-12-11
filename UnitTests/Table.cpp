#include "pch.h"
#include "CppUnitTest.h"
#include "Table/NamedTable.h"
#include "Table/TableBody.h"
#include "DataTypes/Integer.h"
#include "DataTypes/BaseDataType.h"
#include <vector>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

using Table::TableBody;
using Table::NamedTable;
using DataTypes::Integer;
using DataTypes::BaseDataType;

namespace UnitTests
{
    TEST_CLASS(NamedTableTests)
    {
        static vector<vector<BaseDataType<string>*>> _body;
    private:
        vector<string> RowNames{ "Price", "Area", "Rooms", "MetersToSea" };
        vector<string> ColNames; // Without names
        TableBody Body{ _body };
    public:
        TEST_METHOD(Constructor_WithParameters_DoesNotThrow)
        {
            NamedTable nt(Body, RowNames, ColNames);
            Assert();
        }
    };

    vector<vector<BaseDataType<string>*>> NamedTableTests::_body
    {
        {new Integer("1000"), new Integer("1000"), new Integer("1000"), new Integer("1000")},
        {new Integer("1000"), new Integer("1000"), new Integer("1000"), new Integer("1000")},
        {new Integer("10"),   new Integer("6"),    new Integer("6"),    new Integer("2")},
        {new Integer("100"),  new Integer("500"),  new Integer("750"),  new Integer("100")},
    };
}
