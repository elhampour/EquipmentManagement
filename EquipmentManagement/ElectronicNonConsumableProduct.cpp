#include "ElectronicNonConsumableProduct.h"
#include <iostream>
using namespace std;

ElectronicNonConsumableProduct::ElectronicNonConsumableProduct(
	int id, string name, string rName, string mDescription, string rpName, string bcName) :
	Product(id, name, rName, mDescription) {
	setReciverPersonName(rpName);
	setBackupCompanyName(bcName);
}

void ElectronicNonConsumableProduct::setReciverPersonName(string rpName) {
	reciverPersonName = rpName;
}

void ElectronicNonConsumableProduct::setBackupCompanyName(string bcName) {
	backupCompanyName = bcName;
}

string ElectronicNonConsumableProduct::getReciverPersonName() {
	return reciverPersonName;
}

string ElectronicNonConsumableProduct::getBackupCompanyName() {
	return backupCompanyName;
}

void ElectronicNonConsumableProduct::print() const {
	Product::print();
	cout << "\nReciver Person Name : " << reciverPersonName
		<< "\nBackup Company Name : " << backupCompanyName << endl;
}