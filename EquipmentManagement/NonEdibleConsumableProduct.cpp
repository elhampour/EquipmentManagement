#include "NonEdibleConsumableProduct.h"
#include <iostream>
using namespace std;

NonEdibleConsumableProduct::NonEdibleConsumableProduct(
	int id, string name, string rName, string mDescription, string rpName) :
	Product(id, name, rName, mDescription) {
	setReciverPersonName(rpName);
}

void NonEdibleConsumableProduct::setReciverPersonName(string rpName) {
	reciverPersonName = rpName;
}

string NonEdibleConsumableProduct::getReciverPersonName() {
	return reciverPersonName;
}

void NonEdibleConsumableProduct::print() const {
	Product::print();
	cout << "\nReciver Person Name : " << reciverPersonName << endl;
}