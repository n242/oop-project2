#include "BeverageStore.h"

namespace OOP_Hw2
{
	BeverageStore& BeverageStore::AddClubMember(int id)
	{
		idsArr += id;
		return *this;
	}

	BeverageStore& BeverageStore::AddBeverage(const BeverageItem& beverage)
	{
		beverageArr += beverage;
		return *this;
	}

	
	bool BeverageStore::BuyBeverage(const std::string& beverageName, const Customer& customer)
	{
		BookkeepingEntry* tempEntry;
		double updatedPrice;
		Customer tempCustomer = customer;
		for (int i = 0; i < beverageArr.getCurrNumOfElements(); i++)
		{
			if (beverageArr[i].GetName() == beverageName)
			{
				if ((customer.GetAge() >= 18) || ( (customer.GetAge() < 18) && (beverageArr[i].isAlcoholic() == false) ) )// legal age and drink
				{
					int tempId = customer.GetId(); // check if hes a club member
					bool isClubMember = false;
					for (int j = 0; j < idsArr.getCurrNumOfElements(); j++)
					{
						if (idsArr[j] == tempId)
							isClubMember = true;
					}
					if (isClubMember == true)// if is club member apply discount
					{
						updatedPrice = ( beverageArr[i].GetPrice() * ( (100-clubMembersDiscountPercent) / 100) );
					}
					else
					{
						updatedPrice = beverageArr[i].GetPrice();
					}
					tempEntry = new BookkeepingEntry(customer.GetCustomerName(), beverageName, updatedPrice, true);
					bookkeepingArr+=*tempEntry; //adding new entry to bookKeepingEntry that could buy
					delete tempEntry; // delete allocated array
					return true;
				}
			}
		}
 			//add to bookkeeping array that couldn't buy
			tempEntry = new BookkeepingEntry(customer.GetCustomerName(), beverageName, 0.0, false);
			bookkeepingArr+=*tempEntry;
			delete tempEntry; // delete allocated array
			return false;
		
	}

	double BeverageStore::TotalIncome() const
	{
		double sum = 0.0;
		for (int i = 0; i < bookkeepingArr.getCurrNumOfElements(); i++)
		{
			if(bookkeepingArr[i].wasPurchaseSuccessful() == true)
				sum += bookkeepingArr[i].GetBeveragePrice();
		}
		return sum;
	}

		//print bookkeeping entry
		std::ostream& operator<<(std::ostream& outputStream, const BeverageStore& beverageStore)
		{
			for (int i = 0; i < beverageStore.bookkeepingArr.getCurrNumOfElements(); i++)
			{
				outputStream << i +1 << ") " << beverageStore.bookkeepingArr[i].GetCustomerName();
				if (beverageStore.bookkeepingArr[i].wasPurchaseSuccessful() == true)
				{
					outputStream << " bought" <<" '"<<beverageStore.bookkeepingArr[i].GetBeverageName() << "'" <<" with " <<
						beverageStore.bookkeepingArr[i].GetBeveragePrice() << " shekels\n";
				}
				else
					outputStream << " request for buying" <<" '"<< beverageStore.bookkeepingArr[i].GetBeverageName() << "' " <<"was rejected\n";
			}
			return outputStream;
		}
}
