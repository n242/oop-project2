#pragma once
#include <string>
#include "BookkeepingEntry.h"

#define  DEFAULT_DISCOUNT 0.0

namespace OOP_Hw2 {

	class BeverageStore
	{
		double clubMembersDiscountPercent;
		//creating dynamic arrays
		DynamicArray<BeverageItem> beverageArr;
		DynamicArray<int> idsArr; // array for club members only
		DynamicArray<BookkeepingEntry> bookkeepingArr;

		// no dynamic memory or assignment operator, so no need to apply big 3. 

	public:
		
		BeverageStore(double discount = DEFAULT_DISCOUNT) : clubMembersDiscountPercent(discount) {};
		BeverageStore& AddClubMember(int id); //returns this to store that activated method
		BeverageStore& AddBeverage(const BeverageItem& beverage); //returns this to store that activated method
		bool BuyBeverage(const std::string& beverageName, const Customer& customer); 
		//returns true if customer is allowed to buy drink - above 18 id it's alcoholic, else - false.
		double TotalIncome() const ;
		friend std::ostream& operator<<(std::ostream& outputStream, const BeverageStore& beverageStore);//print operator for class BeverageStore, prints all info in bookkeeping. 

		//no memory allocation here (only in dynamic array) so no need to apply big 3
	
	};

}
