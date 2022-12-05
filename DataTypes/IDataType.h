#pragma once

#include <string>

namespace DataTypes
{
	namespace Interfaces
	{
		class IDataType;
	}
}

class DataTypes::Interfaces::IDataType
{
public:
    virtual void Validate(const std::string& object) = 0;
};