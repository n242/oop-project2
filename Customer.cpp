#include "Customer.h"

namespace OOP_Hw2
{
	const std::string& Customer:: GetCustomerName() const	
	{
		if(this==nullptr)
			throw std::exception("GetName on empty array");
		return customerName;
	}

	double Customer::GetAge() const
	{
		if (this == nullptr)
			throw std::exception("GetAge on empty array");
		if(age<0)
			throw std::exception("Age is illegal");
		return age;
	}

	int Customer::GetId() const
	{
		if (this == nullptr)
			throw std::exception("GetID on empty array");
		return id;
	}

}
