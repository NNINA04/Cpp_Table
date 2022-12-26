#include "pch.h"
#include "CppUnitTest.h"
#include "Table/TableBody.h"
#include "AuxiliaryObjects.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using Table::TableBody;

namespace UnitTests
{
    TEST_CLASS(TableBodyTests)
    {
    public:
        TEST_METHOD(Constructor_WithParameters_DoesNotThrow)
        {
            TableBody tb{ Body };
            Assert();
        }

        TEST_METHOD(Constructor_WithIncorrectPameters_ThrowsException)
        {
            auto lambda1 = []() 
            {
                TableBody tb{ TableBody::Body() };
            };
            Assert::ExpectException<exception>(lambda1); // Empty

            auto lambda2 = []()
            {
                TableBody::Body body = 
                {
                    {new Integer("1")},
                    {new Integer("1"), new Integer("2")}
                };
                TableBody tb{ body };
            };
            Assert::ExpectException<exception>(lambda2); // Different sizes
        }

        TEST_METHOD(OperatorOfIndexing_WithParameters_DoesNotThrow)
        {
            TableBody tb{ Body };

            for (size_t i = 0; i < Body.size(); i++)
            {
                TableBody::Row expectedRow = Body[i];
                TableBody::Row actualRow = tb[i];

                Assert::AreEqual(expectedRow.size(), actualRow.size());

                for (size_t j = 0; j < expectedRow.size(); j++)
                {
                    string expected = expectedRow[j]->GetObject();
                    string actual = actualRow[j]->GetObject();
                    Assert::AreEqual(expected, actual);
                }
            }
        }

        TEST_METHOD(Rows_WithoutParameters_DoesNotThrow)
        {
            TableBody tb{ Body };
            Assert::AreEqual(Body.size(), tb.Rows());
        }

        TEST_METHOD(Cols_WithoutParameters_DoesNotThrow)
        {
            TableBody tb{ Body };
            Assert::AreEqual(Body[0].size(), tb.Cols());
        }
    };
}
