#include <iostream>
#include <variant>
#include <vector>
#include <array>
#include "Table/TableBody.h"
#include "DataTypes/IDataType.h"
#include "Operations/OperatorTools.h"
#include "DataTypes/Integer.h"
#include "Operations/Multiplier.h"

using namespace std;
using DataTypes::Interfaces::IDataType;
using Operations::OperatorTools;
using DataTypes::Integer;
using Operations::Multiplier;


int main()
{
    array<string, 1> arr{ "5" };
    OperatorTools opT('*', arr);
    Multiplier mult(opT);


    string two = "2";
    Integer i(two);

    i.Execute(mult);

    cout << i.GetObject();
}