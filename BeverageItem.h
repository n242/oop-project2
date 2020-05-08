#pragma once
#include <string>


namespace OOP_Hw2 {

	class BeverageItem
	{
		std::string name;
		double price;
		bool isDrinkAlcoholic;
		
		// default private c'tor
		BeverageItem(const std::string& name, double price, bool isDrinkAlcoholic) : name(name), price(price), isDrinkAlcoholic(isDrinkAlcoholic){}
		
	public:
		static BeverageItem CreateAlcoholic(const std::string& name, double price);
		static BeverageItem CreateNonAlcoholic(const std::string& name, double price);

		const std::string& GetName() const;
		double GetPrice() const;
		bool isAlcoholic() const;

		void SetPrice(double newPrice);

		// no dynamic allocation or assignment operators, so no need for big three. 
	};



}

