#include "GroceryBill.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Default Constructor
GroceryBill::GroceryBill() {
	counting = 0;
	total = 0;
	gsize = 1000000;
	gItemName = new string[gsize];
	gCode = new string[gsize];
	gPrice = new double[gsize];
	gTaxable = new bool[gsize];
}

// Destructor
GroceryBill::~GroceryBill() {
	delete [] gItemName ;
	delete [] gCode ;
	delete [] gPrice ;
	delete [] gTaxable;	
}

// Constructor that takes in passed over pointer and tax rate. 
GroceryBill::GroceryBill(const PriceList *priceList, double taxRate) {
		total = 0;
		counting = 0;
		gsize = 1000000;
		gItemName = new string[gsize];
		gCode = new string[gsize];
		gPrice = new double[gsize];
		gTaxable = new bool[gsize];
		Code = "NULL";
		quantity_ = 0;
		plistptr = priceList;
		taxrate_ = (1+taxRate/100);
}

// Adds in barcode and quantity to private members
void GroceryBill::scanItem(string scanCode, double quantity) {
	gCode[counting] = scanCode;
	quantity_ = quantity;
	if (plistptr->isValid(gCode[counting]) == false)
		throw runtime_error("Item not found");

	// creates a placeholder PriceListItem object with data at *priceList then assigns it to GroceryBill parallel arrays
	PriceListItem temp = plistptr->getItem(gCode[counting]);
	gCode[counting] = temp.getCode();
	gItemName[counting] = temp.getItemName();
	gPrice[counting] = temp.getPrice();
	gTaxable[counting] = temp.isTaxable();

	// Adds tax if necessary
	if (temp.isTaxable() == true) {
		total = total + (gPrice[counting] * taxrate_)*quantity_;
	}
	else {
		total = total + gPrice[counting]*quantity_;
	}
	counting++;
}
	  
// Scan multiple codes an numbers separated by space: the first is the code (an integer), the second the quantity (a float/double)
// Example line from texd quantities from the given text file
// Each line contains twot file:
// 15000000 1.5
void GroceryBill::scanItemsFromFile(string filename) {
	// HINT: Look at code in PriceList::createPriceListFromDatafile(string filename)
	
	ifstream myfile1(filename);

	if (myfile1.is_open()) {
		cout << "Successfully opened file " << filename << endl;
		
		string code;
		double quantity;
		while (myfile1 >> code >> quantity) {
			scanItem(code, quantity);
		//	cout << code << quantity << "LOADED" << endl;
		}
		myfile1.close();
	}
}

// return the total cost of all items scanned
double GroceryBill::getTotal() {
	return total;
}

// Print the bill to cout. Each line contains the name of an item, total price, and the letter "T" if tax was addded. 
// The last line shows the total.
// An example:
//Plastic_Wrap	1.60547 T
//Sugar_white	5.475
//Waffles_frozen	5.16
//Oil_Canola_100%_pure	2.69
//Potatoes_red	13.446
//TOTAL 	28.3765
void GroceryBill::printBill() {
	for (int i = 0; i < counting; i++) {
		cout << gItemName[i] << "  "
			<< gCode[i] << "  "
			<< gPrice[i] << "  ";
		if (gTaxable[i] == 1)
			cout << "T" <<endl;
		else
			cout << endl;
	}
	cout << "Total Price: " << fixed << setprecision(2) << total << endl;
}

