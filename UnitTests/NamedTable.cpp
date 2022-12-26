#include "pch.h"
#include "CppUnitTest.h"
#include "Table/NamedTable.h"
#include "AuxiliaryObjects.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using Table::TableBody;
using Table::NamedTable;

namespace UnitTests
{
    TEST_CLASS(NamedTableTests)
    {
        TableBody TableBody{ Body };

        vector<string> RowNames{ "Price", "Area", "Rooms", "MetersToSea" };
        vector<string> ColNames{ "SomeColName" }; // One col name it's OK!
    public:
        TEST_METHOD(Constructor_WithParameters_DoesNotThrow)
        {
            NamedTable nt(TableBody, RowNames, ColNames);
            Assert();
        }

        TEST_METHOD(GetRowByName_WithParameters_DoesNotThrow)
        {
            NamedTable nt(TableBody, RowNames, ColNames);

            for (size_t i = 0; i < RowNames.size(); i++)
            {
                NamedTable::Row expectedRow = TableBody[i];
                NamedTable::Row actualRow = nt.GetRowByName(RowNames[i]);

                for (size_t j = 0; j < expectedRow.size(); j++)
                {
                    string expected = expectedRow[i]->GetObject();
                    string actual = actualRow[i]->GetObject();
                    Assert::AreEqual(expected, actual);
                }
            }
        }

        TEST_METHOD(GetColumnByName_WithParameters_DoesNotThrow)
        {
            NamedTable nt(TableBody, RowNames, ColNames);

            NamedTable::Col expectedCol;
            for (size_t i = 0; i < TableBody.Rows(); i++)
                expectedCol.push_back(TableBody[i][0]);

            // Only first index has valid column name in the current case
            NamedTable::Col actualCol = nt.GetColumnByName(ColNames[0]);

            for (size_t i = 0; i < expectedCol.size(); i++)
            {
                string expected = expectedCol[i]->GetObject();
                string actual = actualCol[i]->GetObject();
                Assert::AreEqual(expected, actual);
            }
        }
    
        TEST_METHOD(GetRowByIndex_WithParameters_DoesNotThrow)
        {
            NamedTable nt(TableBody, RowNames, ColNames);

            for (size_t i = 0; i < nt.Rows(); i++)
            {
                NamedTable::Row expectedRow = TableBody[i];
                NamedTable::Row actualRow = nt.GetRowByIndex(i);

                for (size_t j = 0; j < expectedRow.size(); j++)
                {
                    string expected = expectedRow[i]->GetObject();
                    string actual = actualRow[i]->GetObject();
                    Assert::AreEqual(expected, actual);
                }
            }
        }

        TEST_METHOD(GetColumnByIndex_WithParameters_DoesNotThrow)
        {
            NamedTable nt(TableBody, RowNames, ColNames);

            for (size_t j = 0; j < nt.Cols(); j++)
            {
                NamedTable::Col expectedCol;
                for (size_t i = 0; i < TableBody.Rows(); i++)
                    expectedCol.push_back(TableBody[i][j]);

                // Only first index has valid column name in the current case
                NamedTable::Col actualCol = nt.GetColumnByIndex(j);

                for (size_t i = 0; i < expectedCol.size(); i++)
                {
                    string expected = expectedCol[i]->GetObject();
                    string actual = actualCol[i]->GetObject();
                    Assert::AreEqual(expected, actual);
                }
            }
        }
    };
}
