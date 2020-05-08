#pragma once
#include <iostream>

#define DEFAULT_INIT_STORAGE_SIZE 4

namespace OOP_Hw2 {

	template <typename T>
	class DynamicArray
	{
		T** dynmanicArr;
		int arraySize;
		int emptySpace = 0;
	public:
		//default c'tor
		DynamicArray(int arraySize = DEFAULT_INIT_STORAGE_SIZE); // defining default array size 4

		//copy c'tor
		DynamicArray(const DynamicArray& other);

		//d'tor
		~DynamicArray();

		//assignment operators
		const T& operator+=(const T& object1); // adding given object of type T
		const T& operator=(const T& object1); //
		T& operator[](int index);
		const T& operator[](int index) const; // creating operator overloading for const type
		bool operator==(const T& object1) const;

		void duplicateArr(); //duplicating array size if it's full
		int getCurrNumOfElements() const; // getting current number of elements in array
		
	};

	//default c'tor
	template<typename T>
	DynamicArray<T>::DynamicArray(int arraySize)
	{
		this->arraySize = arraySize;
		emptySpace = 0;

		dynmanicArr = new T * [arraySize];
		for (int i = 0; i < arraySize; i++)
		{
			dynmanicArr[i] = nullptr;
		}
	}

	//copy c'tor
	template <typename T>
	DynamicArray<T>::DynamicArray(const DynamicArray& other)
	{
		dynmanicArr = new T * [other.arraySize];
		arraySize = other.arraySize;
		emptySpace = other.emptySpace;
		for (int i = 0; i < emptySpace; i++)
		{
			if(other.dynmanicArr[i]!=nullptr)
				dynmanicArr[i] = new T(*other.dynmanicArr[i]);
		}
		for (int i = emptySpace; i < arraySize; i++ ) 
		{
				dynmanicArr[i] = nullptr;
		}
	}

	template <typename T>
	DynamicArray<T>::~DynamicArray()
	{
		for (int i = 0; i < emptySpace; i++)
		{
			if (dynmanicArr[i] != nullptr)
				delete dynmanicArr[i];
		}
		delete[] dynmanicArr;
	}

	template <typename T>
	T& DynamicArray<T>::operator[](int index) // has to allow to change arr[index]
	{
		if (index < 0 || index > arraySize)
		{
			std::cout << "error operator []" << std::endl;
			exit(1);
		}
		return *dynmanicArr[index];
	}

	template <typename T>
	const T& DynamicArray<T>::operator[](int index) const // has to allow to change arr[index]
	{
		if (index < 0 || index > arraySize)
		{
			std::cout << "error operator []" << std::endl;
			exit(1);
		}
		return *dynmanicArr[index];
	}
	

	template <typename T>
	bool DynamicArray<T>::operator==(const T& object1) const
	{
		if (this != object1)
			return false;
		return true;
	}

	template <typename T>
	const T& DynamicArray<T>::operator+=(const T& object1)
	{
		if (emptySpace == arraySize) // if array is full - duplicate first, then go back here
		{
			duplicateArr();
		}
		dynmanicArr[emptySpace] = new T(object1);
		emptySpace++;
		return **dynmanicArr;
	}

	template <typename T>
	const T& DynamicArray<T>::operator=(const T& object1)
	{
		if (this != object1)
		{
			for (int i = 0; i < emptySpace; i++)// delete current, the allocate new space and copy there
			{
				if (dynmanicArr[i] != nullptr)
					delete dynmanicArr[i];
			}
			delete[] dynmanicArr; 
			arraySize = object1.arraySize;
			emptySpace = object1.emptySpace;
			dynmanicArr = new T * [arraySize];
			for (int i = 0; i < arraySize; i++)
			{
				dynmanicArr[i] = new T(*object1.dynamicArr[i]);
			}
		}
		return *this;
	}


	template <typename T>
	void DynamicArray<T>::duplicateArr()
	{
		T** tempArray = new T * [arraySize * 2]; // creating new array
		for (int i = 0; i < arraySize; i++)
		{
			tempArray[i] = dynmanicArr[i]; // copying values there
		}
		for (int j = emptySpace; j < (arraySize * 2); j++)
		{
			tempArray[j] = nullptr; // setting empty sells to nullptr 
		}
		delete[] dynmanicArr; // deleting original
		arraySize *= 2;
		dynmanicArr = tempArray;
	}

	template <typename T>
	int DynamicArray<T>:: getCurrNumOfElements() const
	{
		if(emptySpace>=0)
			return emptySpace;
		else
		{
			std::cout << "error getCurrNumberOfElements";
			return -1;
		}
	}

}

