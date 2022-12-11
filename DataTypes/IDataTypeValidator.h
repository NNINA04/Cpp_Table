#pragma once

#include <string>

namespace DataTypes
{
	namespace Interfaces
	{
		template<class T>
		class IDataTypeValidator;
	}
}

template<class T>
class DataTypes::Interfaces::IDataTypeValidator
{
public:
    virtual void Validate(const T& value) const = 0;
};