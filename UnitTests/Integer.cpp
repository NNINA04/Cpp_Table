#include "pch.h"
#include "CppUnitTest.h"
#include "DataTypes/Integer.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using DataTypes::Integer;

namespace UnitTests
{
    TEST_CLASS(IntegerTests)
    {
        string PositiveNumber = "1234";
        string NegativeNumber = "-1234";
        string NotNumber = "SomeString";
    public:
        TEST_METHOD(Constructor_WithCorrectParameters_DoesNotThrow)
        {
            Integer numb2(PositiveNumber);
            Integer numb1(NegativeNumber);
            Assert();
        }

        TEST_METHOD(Constructor_WithIncorrectParameters_ThrowsException)
        {
            auto lambda = [this]()
            {
                Integer numb(NotNumber);
            };
            Assert::ExpectException<exception>(lambda);
        }

        TEST_METHOD(GetObject_WithoutParameters_DoesNotThrow)
        {
            Integer numb1(PositiveNumber);
            Assert::AreEqual(PositiveNumber, numb1.GetObject());

            Integer numb2(NegativeNumber);
            Assert::AreEqual(NegativeNumber, numb2.GetObject());
        }

        TEST_METHOD(SetObject_WithParameters_SetsPassedValueWithoutAnyChanges)
        {
            Integer numb(PositiveNumber);
            numb.SetObject(NegativeNumber);
            Assert::AreEqual(NegativeNumber, numb.GetObject());
        }

        TEST_METHOD(Validate_WithParameters_DoesNotThrow)
        {
            Integer numb(PositiveNumber);

            numb.Validate(PositiveNumber);
            numb.Validate(NegativeNumber);

            Assert();
        }

        TEST_METHOD(Validate_WithParameters_ThrowsException)
        {
            Integer numb(PositiveNumber);

            auto lambda1 = [&]()
            {
                numb.Validate(NotNumber);
            };
            Assert::ExpectException<exception>(lambda1);

            auto lambda2 = [&]()
            {
                numb.Validate("4" + NotNumber);
            };
            Assert::ExpectException<exception>(lambda2);
        }

        TEST_METHOD(OperatorPlus_WithParameters_DoesNotThrow)
        {
            Integer numb1(PositiveNumber);
            Integer numb2(NegativeNumber);

            Integer* summedNumb = numb1 + numb2;

            Assert::AreEqual(string("0"), summedNumb->GetObject());
        }

        TEST_METHOD(OperatorMultiply_WithParameters_DoesNotThrow)
        {
            Integer numb1(PositiveNumber);
            Integer numb2(NegativeNumber);

            Integer* summedNumb = numb1 * numb2;

            Assert::AreEqual(string("-1522756"), summedNumb->GetObject());
        }
    };
}
