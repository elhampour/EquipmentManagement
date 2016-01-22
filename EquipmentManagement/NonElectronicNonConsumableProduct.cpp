#include "NonElectronicNonConsumableProduct.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

NonElectronicNonConsumableProduct::NonElectronicNonConsumableProduct(
	int id, 
	string name, 
	string rName, 
	string mDescription, 
	string rpName, 
	int ml) :
	Product(id, name, rName, mDescription) {
	setReciverPersonName(rpName);
	setMinimumLifeTime(ml);
}

void NonElectronicNonConsumableProduct::setReciverPersonName(string rpName) {
	const char *lastNameValue = rpName.data();
	int length = rpName.size();
	length = (length < 15 ? length : 14);
	strncpy_s(reciverPersonName, lastNameValue, length);
	reciverPersonName[length] = '\0';
}

void NonElectronicNonConsumableProduct::setMinimumLifeTime(int ml) {
	minimumLifeTime = ml;
}

string NonElectronicNonConsumableProduct::getReciverPersonName() const{
	return reciverPersonName;
}

int NonElectronicNonConsumableProduct::getMinimumLifeTime() const {
	return minimumLifeTime;
}

void NonElectronicNonConsumableProduct::print() const {
	Product::print();
	cout << "Reciver Person Name : " << reciverPersonName << endl;
	cout << "Minimum Life Time : " << minimumLifeTime << endl;
	cout << "Type : " << "NonElectronic NonConsumable Product" << endl;
	cout << "-------------------------- " << endl;
}

void NonElectronicNonConsumableProduct::insert() {

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

	cout << "Reciver Person Name: ";
	string reciverPersonName;
	cin >> reciverPersonName;
	setReciverPersonName(reciverPersonName);

	cout << "Minimum Life Time : ";
	int minimumLifeTime;
	cin >> minimumLifeTime;
	setMinimumLifeTime(minimumLifeTime);

	fstream outCredit("NonElectronicNonConsumableProduct.dat", ios::in | ios::out | ios::binary);

	if (!outCredit)
	{
		cerr << "File could not be opened." << endl;
		system("pause");
		exit(1);
	}

	NonElectronicNonConsumableProduct nonElectronicNonConsumableProduct;
	outCredit.seekg((getProductId() - 1)*sizeof(NonElectronicNonConsumableProduct));
	outCredit.read(reinterpret_cast<char *>(&nonElectronicNonConsumableProduct),
		sizeof(NonElectronicNonConsumableProduct));

	if (nonElectronicNonConsumableProduct.getProductId() == 0) {
		NonElectronicNonConsumableProduct nonElectronicNonConsumableProduct(
			getProductId(),
			getProductName(),
			getReciverUnitName(),
			getManualDescription(),
			reciverPersonName,
			minimumLifeTime);

		outCredit.seekp((getProductId() - 1) * sizeof(NonElectronicNonConsumableProduct));
		outCredit.write(reinterpret_cast<const char *>(&nonElectronicNonConsumableProduct),
			sizeof(NonElectronicNonConsumableProduct));
	}
	else {
		cerr << "Product #" << nonElectronicNonConsumableProduct.getProductId() << " already contains information." << endl;
		system("pause");
	}
}

void NonElectronicNonConsumableProduct::update() {
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

	cout << "Reciver Person Name: ";
	string reciverPersonName;
	cin >> reciverPersonName;
	setReciverPersonName(reciverPersonName);

	cout << "Minimum Life Time : ";
	int minimumLifeTime;
	cin >> minimumLifeTime;
	setMinimumLifeTime(minimumLifeTime);

	fstream outCredit("NonElectronicNonConsumableProduct.dat", ios::in | ios::out | ios::binary);

	if (!outCredit)
	{
		cerr << "File could not be opened." << endl;
		system("pause");
		exit(1);
	}

	outCredit.seekg((getProductId() - 1) * sizeof(NonElectronicNonConsumableProduct));
	NonElectronicNonConsumableProduct nonElectronicNonConsumableProduct;
	outCredit.read(reinterpret_cast<char *>(&nonElectronicNonConsumableProduct), sizeof(NonElectronicNonConsumableProduct));

	if (nonElectronicNonConsumableProduct.getProductId() != 0)
	{
		outCredit.seekp((getProductId() - 1) * sizeof(NonElectronicNonConsumableProduct));
		NonElectronicNonConsumableProduct toupdate(
			getProductId(),
			getProductName(),
			getReciverUnitName(),
			getManualDescription(),
			reciverPersonName,
			minimumLifeTime);
		outCredit.write(reinterpret_cast<const char *>(&toupdate),
			sizeof(NonElectronicNonConsumableProduct));
	}
	else {
		cerr << "Product #" << getProductId() << " has no information." << endl;
		system("pause");
	}
}

void NonElectronicNonConsumableProduct::removeRecord() {
	cout << "Please fill the needed information!" << endl;

	cout << "Product Id (1 - 100): ";
	int productId;
	cin >> productId;
	setProductId(productId);

	fstream outCredit("NonElectronicNonConsumableProduct.dat", ios::in | ios::out | ios::binary);

	if (!outCredit)
	{
		cerr << "File could not be opened." << endl;
		system("pause");
		exit(1);
	}

	NonElectronicNonConsumableProduct nonElectronicNonConsumableProduct;
	outCredit.seekg((getProductId() - 1)*sizeof(NonElectronicNonConsumableProduct));
	outCredit.read(reinterpret_cast<char *>(&nonElectronicNonConsumableProduct),
		sizeof(NonElectronicNonConsumableProduct));

	if (nonElectronicNonConsumableProduct.getProductId() != 0) {
		NonElectronicNonConsumableProduct blank;

		outCredit.seekp((getProductId() - 1) * sizeof(NonElectronicNonConsumableProduct));
		outCredit.write(reinterpret_cast<const char *>(&blank),
			sizeof(NonElectronicNonConsumableProduct));
	}
	else {
		cerr << "Product #" << nonElectronicNonConsumableProduct.getProductId() << " has no information." << endl;
		system("pause");
	}
}

void NonElectronicNonConsumableProduct::printAll() {
	fstream outCredit("NonElectronicNonConsumableProduct.dat", ios::in | ios::out | ios::binary);
	if (!outCredit)
	{
		cerr << "File could not be opened." << endl;
		system("pause");
		exit(1);
	}
	
	for (int index = 1; index <= 100; index++)
	{
		NonElectronicNonConsumableProduct nonElectronicNonConsumableProduct;
		outCredit.seekg((index - 1)*sizeof(NonElectronicNonConsumableProduct));
		outCredit.read(reinterpret_cast<char *>(&nonElectronicNonConsumableProduct),
			sizeof(NonElectronicNonConsumableProduct));

		if (nonElectronicNonConsumableProduct.getProductId() != 0) {
			nonElectronicNonConsumableProduct.print();
		}
	}
}

void NonElectronicNonConsumableProduct::init() {
	ofstream outCredit("NonElectronicNonConsumableProduct.dat", ios::binary);
	if (!outCredit)
	{
		cerr << "File could not be opened." << endl;
		exit(1);
	}
	NonElectronicNonConsumableProduct nonElectronicNonConsumableProduct;
	for (int i = 0; i < 100; i++)
		outCredit.write(reinterpret_cast<const char *>(&nonElectronicNonConsumableProduct),
			sizeof(NonElectronicNonConsumableProduct));
}