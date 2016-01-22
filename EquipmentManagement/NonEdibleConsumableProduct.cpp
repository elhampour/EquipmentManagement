#include "NonEdibleConsumableProduct.h"
#include <iostream>
#include <fstream>
using namespace std;

NonEdibleConsumableProduct::NonEdibleConsumableProduct(
	int id, 
	string name, 
	string rName, 
	string mDescription, 
	string rpName) :
	Product(id, name, rName, mDescription) {
	setReciverPersonName(rpName);
}

void NonEdibleConsumableProduct::setReciverPersonName(string rpName) {
	const char *lastNameValue = rpName.data();
	int length = rpName.size();
	length = (length < 15 ? length : 14);
	strncpy_s(reciverPersonName, lastNameValue, length);
	reciverPersonName[length] = '\0';
}

string NonEdibleConsumableProduct::getReciverPersonName() const{
	return reciverPersonName;
}

void NonEdibleConsumableProduct::print() const {
	Product::print();
	cout << reciverPersonName << " " << "NEC" << endl;
}

void NonEdibleConsumableProduct::insert() {

	cout << "Please fill the needed information!" << endl;

	cout << "Product Id (1 - 100): ";
	int productId;
	cin >> productId;
	setProductId(productId);

	cout << "Product Name : ";
	string productName;
	cin >> productName;
	setProductName(productName);

	cout << "Reciver Unit Name : ";
	string reciverUnitName;
	cin >> reciverUnitName;
	setReciverUnitName(reciverUnitName);

	cout << "Manual Description : ";
	string manualDescription;
	cin >> manualDescription;
	setManualDescription(manualDescription);

	cout << "Reciver Person Name : ";
	string reciver;
	cin >> reciver;
	setReciverPersonName(reciver);

	fstream outCredit("NonEdibleConsumableProduct.dat", ios::in | ios::out | ios::binary);

	if (!outCredit)
	{
		cerr << "File could not be opened." << endl;
		system("pause");
		exit(1);
	}

	NonEdibleConsumableProduct nonEdibleConsumableProduct;
	outCredit.seekg((getProductId() - 1)*sizeof(NonEdibleConsumableProduct));
	outCredit.read(reinterpret_cast<char *>(&nonEdibleConsumableProduct),
		sizeof(NonEdibleConsumableProduct));

	if (nonEdibleConsumableProduct.getProductId() == 0) {
		NonEdibleConsumableProduct nonEdibleConsumableProduct(
			getProductId(),
			getProductName(),
			getReciverUnitName(),
			getManualDescription(),
			reciverPersonName);

		outCredit.seekp((getProductId() - 1) * sizeof(NonEdibleConsumableProduct));
		outCredit.write(reinterpret_cast<const char *>(&nonEdibleConsumableProduct),
			sizeof(NonEdibleConsumableProduct));
	}
	else {
		cerr << "Product #" << nonEdibleConsumableProduct.getProductId() << " already contains information." << endl;
		system("pause");
	}
}

void NonEdibleConsumableProduct::update() {
	cout << "Please fill the needed information!" << endl;

	cout << "Product Id (1 - 100): ";
	int productId;
	cin >> productId;
	setProductId(productId);

	cout << "Product Name : ";
	string productName;
	cin >> productName;
	setProductName(productName);

	cout << "Reciver Unit Name : ";
	string reciverUnitName;
	cin >> reciverUnitName;
	setReciverUnitName(reciverUnitName);

	cout << "Manual Description : ";
	string manualDescription;
	cin >> manualDescription;
	setManualDescription(manualDescription);

	cout << "Reciver Person Name : ";
	string reciver;
	cin >> reciver;
	setReciverPersonName(reciver);

	fstream outCredit("NonEdibleConsumableProduct.dat", ios::in | ios::out | ios::binary);

	if (!outCredit)
	{
		cerr << "File could not be opened." << endl;
		system("pause");
		exit(1);
	}

	outCredit.seekg((getProductId() - 1) * sizeof(NonEdibleConsumableProduct));
	NonEdibleConsumableProduct nonEdibleConsumableProduct;
	outCredit.read(reinterpret_cast<char *>(&nonEdibleConsumableProduct), sizeof(NonEdibleConsumableProduct));

	if (nonEdibleConsumableProduct.getProductId() != 0)
	{
		outCredit.seekp((getProductId() - 1) * sizeof(NonEdibleConsumableProduct));
		NonEdibleConsumableProduct toupdate(
			getProductId(),
			getProductName(),
			getReciverUnitName(),
			getManualDescription(),
			reciverPersonName);
		outCredit.write(reinterpret_cast<const char *>(&toupdate),
			sizeof(NonEdibleConsumableProduct));
	}
	else {
		cerr << "Product #" << getProductId() << " has no information." << endl;
		system("pause");
	}
}

void NonEdibleConsumableProduct::removeRecord() {
	cout << "Please fill the needed information!" << endl;

	cout << "Product Id (1 - 100): ";
	int productId;
	cin >> productId;
	setProductId(productId);

	fstream outCredit("NonEdibleConsumableProduct.dat", ios::in | ios::out | ios::binary);

	if (!outCredit)
	{
		cerr << "File could not be opened." << endl;
		system("pause");
		exit(1);
	}

	NonEdibleConsumableProduct nonEdibleConsumableProduct;
	outCredit.seekg((getProductId() - 1)*sizeof(NonEdibleConsumableProduct));
	outCredit.read(reinterpret_cast<char *>(&nonEdibleConsumableProduct),
		sizeof(NonEdibleConsumableProduct));

	if (nonEdibleConsumableProduct.getProductId() != 0) {
		NonEdibleConsumableProduct blank;

		outCredit.seekp((getProductId() - 1) * sizeof(NonEdibleConsumableProduct));
		outCredit.write(reinterpret_cast<const char *>(&blank),
			sizeof(NonEdibleConsumableProduct));
	}
	else {
		cerr << "Product #" << nonEdibleConsumableProduct.getProductId() << " has no information." << endl;
		system("pause");
	}
}

void NonEdibleConsumableProduct::printAll() {
	fstream outCredit("NonEdibleConsumableProduct.dat", ios::in | ios::out | ios::binary);
	if (!outCredit)
	{
		cerr << "File could not be opened." << endl;
		system("pause");
		exit(1);
	}

	cout <<
		"Product Id" << " " <<
		"Product Name" << " " <<
		"Reciver Unit Name" << " " <<
		"Manual Description" << " " <<
		"Reciver Person Name" << " " <<
		"Type" << endl;

	for (int index = 1; index <= 100; index++)
	{
		NonEdibleConsumableProduct nonEdibleConsumableProduct;
		outCredit.seekg((index - 1)*sizeof(NonEdibleConsumableProduct));
		outCredit.read(reinterpret_cast<char *>(&nonEdibleConsumableProduct),
			sizeof(NonEdibleConsumableProduct));

		if (nonEdibleConsumableProduct.getProductId() != 0) {
			nonEdibleConsumableProduct.print();
		}
	}
}

void NonEdibleConsumableProduct::init() {
	ofstream outCredit("NonEdibleConsumableProduct.dat", ios::binary);
	if (!outCredit)
	{
		cerr << "File could not be opened." << endl;
		exit(1);
	}
	NonEdibleConsumableProduct nonEdibleConsumableProduct;
	for (int i = 0; i < 100; i++)
		outCredit.write(reinterpret_cast<const char *>(&nonEdibleConsumableProduct),
			sizeof(NonEdibleConsumableProduct));
}