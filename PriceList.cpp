#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "PriceList.h"
#include "PriceListItem.h"
/*PriceList to get the prices, and the tax rate percentage for taxable items when constructed*/

using namespace std;

// Load information from a text file with the given filename.
void PriceList::createPriceListFromDatafile(string filename) {
	ifstream myfile(filename);
	cout << "Create Price" << endl;

	if (myfile.is_open()) {
		cout << "Successfully opened file " << filename << endl;
		string name;
		string code;
		double price;
		bool taxable;
		while (myfile >> name >> code >> price >> taxable) {
			// cout << code << " " << taxable << endl;
			addEntry(name, code, price, taxable);
		}
		myfile.close();
	}
	else
		throw invalid_argument("Could not open file " + filename);
}

// return true only if the code is valid
//Done
PriceList::PriceList()
{
	size = 1000000;
	itemName_ = new string[size];
	code_ = new string[size];
	price_ = new double[size];
	taxable_ = new bool[size];
	length_ = 0;
}
//Done
void PriceList::addEntry(string itemName, string code, double price, bool taxable) {
	// TO BE COMPLETED
	itemName_[length_] = itemName;
	code_[length_] = code;
	price_[length_] = price;
	taxable_[length_] = taxable;
	length_++;
}
//Done
PriceList::~PriceList()
{
	delete[] itemName_;
	delete[] code_;
	delete[] price_;
	delete[] taxable_;	
}
//Done
bool PriceList::isValid(string code) const {
	// TO BE COMPLETED
	//for(
	for (int i = 0; i < length_; i++)

	{
		if (code_[i] == code)
			return true;
	}
	return false;
}
//THROW EXCEPTION AND CATCH
PriceListItem PriceList::getItem(string code) const {
	// TO BE COMPLETED
	for (int i = 0; i < length_; i++)
	{

			if (code_[i] == code)
			{
				PriceListItem ReturnInfo(itemName_[i], code_[i], price_[i], taxable_[i]);
				return ReturnInfo;
			}
			
		
	}
}
//Assigment operator
//Done
PriceList& PriceList::operator = (const PriceList &array_)
{
	if (this != &array_)
	{
		delete[] itemName_;
		delete[] code_;
		delete[] price_;
		delete[] taxable_;
		size = array_.size;
		length_ = array_.length_;
		itemName_ = new string[size];
		code_ = new string[size];
		price_ = new double[size];
		taxable_ = new bool[size];
		for (int i = 0; i < length_; i++)
		{
			itemName_[i] = array_.itemName_[i];
			code_[i] = array_.code_[i];
			price_[i] = array_.price_[i];
			taxable_[i] = array_.taxable_[i];
		}

	}
	return(*this);
}
//Copy construcotr
//Done

PriceList::PriceList(const PriceList& Copy)
{
	size = Copy.size;
	length_ = Copy.length_;
	itemName_=new string[size];
	code_ = new string[size];
	price_ = new double[size];
	taxable_=new bool[size];
	for (int i = 0; i < length_; i++)
	{
		itemName_[i] = Copy.itemName_[i];
		
		code_[i] = Copy.code_[i];

		price_[i] = Copy.price_[i];
		taxable_[i] = Copy.taxable_[i];
	}
}
