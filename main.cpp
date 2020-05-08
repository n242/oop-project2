#include <iostream>
#include <iomanip> // Set floating point precision
#include "Customer.h"
#include "BeverageItem.h"
#include "BeverageStore.h"

#define SODA "soda"
#define JUICE "juice"
#define BEER "beer"
#define WINE "wine"
#define TEA "tea"
#define CLUB_MEMBER_DISCOUNT 10

using namespace OOP_Hw2;

int main()
{
	// Set floating point printing precision to two decimal points
	std::cout << std::fixed << std::setprecision(2);
	{
		

		BeverageStore beverageStore(CLUB_MEMBER_DISCOUNT);

		Customer david("David", 25, 1);
		Customer moshe("Moshe", 42, 2);
		Customer oshrat("Oshrat", 16, 3);
		Customer miriam("Miriam", 25, 4);

		miriam = moshe;

		BeverageItem soda = BeverageItem::CreateNonAlcoholic(SODA, 4.0);
		BeverageItem juice = BeverageItem::CreateNonAlcoholic(JUICE, 6.0);
		BeverageItem beer = BeverageItem::CreateAlcoholic(BEER, 15.0);
		BeverageItem wine = BeverageItem::CreateAlcoholic(WINE, 30.0);

		//wine.SetPrice() += juice.GetPrice();

		beverageStore.AddBeverage(soda).AddBeverage(juice).AddBeverage(beer).AddBeverage(wine);
		beverageStore.AddClubMember(david.GetId()).AddClubMember(miriam.GetId());

		//beverageStore += wine;
		//BeverageItem tea += wine;

		beverageStore.BuyBeverage(WINE, david); // return value is ignored here
		beverageStore.BuyBeverage(JUICE, david);
		beverageStore.BuyBeverage(BEER, oshrat);
		beverageStore.BuyBeverage(WINE, oshrat);
		beverageStore.BuyBeverage(BEER, moshe);
		beverageStore.BuyBeverage(JUICE, moshe);
		beverageStore.BuyBeverage(SODA, miriam);
		beverageStore.BuyBeverage(TEA, miriam);

		std::cout << "Beverage-Store Bookkeeping" << std::endl;
		std::cout << "**************************" << std::endl;
		std::cout << beverageStore << std::endl;

		std::cout << "Total income: " << beverageStore.TotalIncome() << std::endl;
		std::cout << "memory leaks before: ";
		std::cout << _CrtDumpMemoryLeaks();
	}
	std::cout << " memory leaks after: ";
	std::cout << _CrtDumpMemoryLeaks();
	return 0;
}