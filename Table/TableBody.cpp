#include "pch.h"
#include "TableBody.h"

void Table::TableBody::Validate(Body & body)
{
    if (body.empty())
        throw std::exception();

    size_t firstVectorSize = body[0].size();

    for (size_t i = 1; i < body.size(); i++)
    {
        size_t currVectorSize = body[i].size();
        if (firstVectorSize != currVectorSize)
            throw std::exception();
    }
}   