#include "NonElectronicNonConsumableProduct.h"
#include <iostream>
using namespace std;

NonElectronicNonConsumableProduct::NonElectronicNonConsumableProduct(
	int id, string name, string rName, string mDescription, string rpName, int ml) :
	Product(id, name, rName, mDescription) {
	setReciverPersonName(rpName);
	setMinimumLifeTime(ml);
}

void NonElectronicNonConsumableProduct::setReciverPersonName(string rpName) {
	reciverPersonName = rpName;
}

void NonElectronicNonConsumableProduct::setMinimumLifeTime(int ml) {
	minimumLifeTime = ml;
}

string NonElectronicNonConsumableProduct::getReciverPersonName() {
	return reciverPersonName;
}

int NonElectronicNonConsumableProduct::getMinimumLifeTime() {
	return minimumLifeTime;
}

void NonElectronicNonConsumableProduct::print() const {
	Product::print();
	cout << "\nReciver Person Name : " << reciverPersonName
		<< "\nMinimum Life Time(Month) : " << minimumLifeTime << endl;
}