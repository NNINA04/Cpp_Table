#pragma once

#include "Table/TableBody.h"
#include "DataTypes/Integer.h"

using namespace Table;
using namespace DataTypes;

TableBody::Body Body
{
    {new Integer("1000"), new Integer("1000"), new Integer("1000"), new Integer("1000")},
    {new Integer("1000"), new Integer("1000"), new Integer("1000"), new Integer("1000")},
    {new Integer("10"),   new Integer("6"),    new Integer("6"),    new Integer("2")},
    {new Integer("100"),  new Integer("500"),  new Integer("750"),  new Integer("100")},
};