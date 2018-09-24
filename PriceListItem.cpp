 #include "PriceListItem.h"

//The information of each item is its price, barcode, item name, and whether it is taxable
//these are kept together in Class PriceListItem.


PriceListItem::PriceListItem(const string &itemName, const string &code, double price, bool taxable) {
	// Assigns passed values to private members of PriceListItem
	Itemname = itemName;
	Code = code;
	Price = price;
	Taxable = taxable;
}

PriceListItem::PriceListItem() {
	// Default Constructor
	Itemname = "NULL";
	Code = "NULL";
	Price = 0;
	Taxable = false;
}

// Following 4 functions simply return requested variable
string PriceListItem::getItemName() {
	return Itemname;
}

string PriceListItem::getCode() {
	return Code;
}

double PriceListItem::getPrice() {
	return Price;
}

bool PriceListItem::isTaxable() {
	return Taxable;
}


