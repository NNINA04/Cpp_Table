#pragma once

namespace Operations
{
	namespace Interfaces
	{
		template<class T>
		class IOperation;
	}
}

template<class T>
class Operations::Interfaces::IOperation
{
public:
    virtual void ExecuteOperation(T& object) = 0;
};