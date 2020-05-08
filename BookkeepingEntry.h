#pragma once
#include <string>
#include "DynamicArray.h"
#include "BeverageItem.h"
#include "Customer.h"

namespace OOP_Hw2 {

	class BookkeepingEntry
	{
		std::string customerName;
		std::string beverageName;
		double drinkPrice;
		bool wasApproved;

	public:
		//default c'tor: 
		BookkeepingEntry(const std::string& customerName, const std::string& beverageName, double drinkPrice, bool wasApproved) : customerName(customerName), beverageName(beverageName), drinkPrice(drinkPrice), wasApproved(wasApproved) {};
		//getters, defined as const so won't change recieved value
		bool wasPurchaseSuccessful() const;
		double GetBeveragePrice() const;
		const std::string& GetCustomerName() const;
		const std::string& GetBeverageName() const;

	};

}