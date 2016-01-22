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
	// copy at most 15 characters from string to lastName
	const char *lastNameValue = name.data();
	int length = name.size();
	length = (length < 15 ? length : 14);
	strncpy_s(productName, lastNameValue, length);
	productName[length] = '\0'; // append null character to lastName
}

void Product::setReciverUnitName(string rName)
{
	const char *lastNameValue = rName.data();
	int length = rName.size();
	length = (length < 15 ? length : 14);
	strncpy_s(reciverUnitName, lastNameValue, length);
	reciverUnitName[length] = '\0'; // append null character to lastName
}

void Product::setManualDescription(string mDescription)
{
	const char *lastNameValue = mDescription.data();
	int length = mDescription.size();
	length = (length < 15 ? length : 14);
	strncpy_s(manualDescription, lastNameValue, length);
	manualDescription[length] = '\0'; // append null character to lastName
}

int Product::getProductId() const {
	return productId;
}

string Product::getProductName() const{
	return productName;
}

string Product::getReciverUnitName() const {
	return reciverUnitName;
}

string Product::getManualDescription() const {
	return manualDescription;
}

void Product::print() const {
	cout << productId << "            " << productName << "              " << reciverUnitName << "                   " << manualDescription<< "                    ";
}

void Product::insert() {
	//to be ovveriden
}

void Product::update() {
	//to be ovveriden
}

void Product::removeRecord() {
	//to be ovveriden
}

void Product::printAll() {
	//to be ovveriden
}

void Product::init() {
	//to be ovveriden
}