#pragma once
#include "BookkeepingEntry.h"


namespace OOP_Hw2
{
	bool BookkeepingEntry::wasPurchaseSuccessful() const 
	{
		if (this == nullptr)
			throw std::exception("wasPurchaseSuccessful on empty array");
		if (wasApproved == true)
			return true;
		else
			return false;
	}
	double  BookkeepingEntry::GetBeveragePrice() const
	{
		if (this == nullptr)
			throw std::exception("GetBeveragePrice on empty array");
		if (drinkPrice > 0.0)
			return drinkPrice;
		else
		{
			std::cout << "beverage price illegal";
			return 0.0;
		}
	}
	const std::string& BookkeepingEntry::GetCustomerName() const
	{
		if(this==nullptr)
			throw std::exception("GetName on empty array");
		return customerName;
	}
	const std::string& BookkeepingEntry::GetBeverageName() const
	{
		if (this == nullptr)
			throw std::exception("GetBeverageName on empty array");
		return beverageName;
	}
}
