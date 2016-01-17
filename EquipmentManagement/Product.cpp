#include "Product.h"
#include <iostream>
using namespace std;

Product::Product(int id, string name, string rName, string mDescription) {
	setProductId(id);
	setProductName(name);
	setReciverUnitName(rName);
	setManualDescription(mDescription);
}

void Product::setProductId(int id)
{
	productId = id;
}

void Product::setProductName(string name)
{
	productName = name;
}

void Product::setReciverUnitName(string rName)
{
	reciverUnitName = rName;
}

void Product::setManualDescription(string mDescription)
{
	manualDescription = mDescription;
}

int Product::getProductId() {
	return productId;
}

string Product::getProductName() {
	return productName;
}

string Product::getReciverUnitName() {
	return reciverUnitName;
}

string Product::getManualDescription() {
	return manualDescription;
}

void Product::print() const {
	cout << "Product Id : " << productId
		<< "\nProduct Name : " << productName
		<< "\nReciver Unit Name : " << reciverUnitName
		<< "\nManual Description : " << manualDescription;
}