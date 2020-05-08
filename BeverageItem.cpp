#include "BeverageItem.h"

namespace OOP_Hw2
{
	BeverageItem BeverageItem::CreateAlcoholic(const std::string& name, double price)
	{
		BeverageItem drink(name, price, true);
		return drink;
	}

	BeverageItem BeverageItem::CreateNonAlcoholic(const std::string& name, double price)
	{
		BeverageItem drink(name, price, false);
		return drink;
	}

	const std::string& BeverageItem::GetName() const
	{
		if (this == nullptr)
			throw std::exception("GetName on empty array");
		return name;
	}

	double BeverageItem::GetPrice() const
	{
		if (this == nullptr)
			throw std::exception("GetPrice on empty array");
		if (price < 0)
			throw std::exception("price is illegal");
		return price;
	}


	bool BeverageItem::isAlcoholic() const
	{
		if (this == nullptr)
			throw std::exception("isAlcoholic on empty array");
		if (isDrinkAlcoholic == true)
			return true;
		return false;
	}

	void BeverageItem::SetPrice(double newPrice)
	{
		if (newPrice < 0)
			throw std::exception("SetPrice illegal");
		this->price = newPrice;
	}

}

