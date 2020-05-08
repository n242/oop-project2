#pragma once
#include <string>

namespace OOP_Hw2 {

	class Customer
	{	
		std::string customerName;
		double age;
		int id;

	public:
		//default c'tor
		Customer(const std::string& customerName, double age, int id) : customerName(customerName), age(age), id(id){}
		//getters:
		const std::string& GetCustomerName() const; // getters so have to return const so no one will change it
		double GetAge() const;
		int GetId() const;
	};

}

