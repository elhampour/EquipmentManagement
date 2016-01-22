#include "ElectronicNonConsumableProduct.h"
#include <iostream>
#include <fstream>
using namespace std;

ElectronicNonConsumableProduct::ElectronicNonConsumableProduct(
	int id, 
	string name, 
	string rName, 
	string mDescription, 
	string rpName, 
	string bcName) :
	Product(id, name, rName, mDescription) {
	setReciverPersonName(rpName);
	setBackupCompanyName(bcName);
}

void ElectronicNonConsumableProduct::setReciverPersonName(string rpName) {

	const char *lastNameValue = rpName.data();
	int length = rpName.size();
	length = (length < 15 ? length : 14);
	strncpy_s(reciverPersonName, lastNameValue, length);
	reciverPersonName[length] = '\0';
}

void ElectronicNonConsumableProduct::setBackupCompanyName(string bcName) {
	const char *lastNameValue = bcName.data();
	int length = bcName.size();
	length = (length < 15 ? length : 14);
	strncpy_s(backupCompanyName, lastNameValue, length);
	backupCompanyName[length] = '\0';
}

string ElectronicNonConsumableProduct::getReciverPersonName() const{
	return reciverPersonName;
}

string ElectronicNonConsumableProduct::getBackupCompanyName() const {
	return backupCompanyName;
}

void ElectronicNonConsumableProduct::print() const {
	Product::print();
	cout << reciverPersonName << " " << backupCompanyName << " " << "ENC" << endl;
}

void ElectronicNonConsumableProduct::insert() {

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
	string reciverPersonName;
	cin >> reciverPersonName;
	setReciverPersonName(reciverPersonName);

	cout << "Backup Company Name: ";
	string backupCompanyName;
	cin >> backupCompanyName;
	setBackupCompanyName(backupCompanyName);

	fstream outCredit("ElectronicNonConsumableProduct.dat", ios::in | ios::out | ios::binary);

	if (!outCredit)
	{
		cerr << "File could not be opened." << endl;
		system("pause");
		exit(1);
	}

	ElectronicNonConsumableProduct electronicNonConsumableProduct;
	outCredit.seekg((getProductId() - 1)*sizeof(ElectronicNonConsumableProduct));
	outCredit.read(reinterpret_cast<char *>(&electronicNonConsumableProduct),
		sizeof(ElectronicNonConsumableProduct));

	if (electronicNonConsumableProduct.getProductId() == 0) {
		ElectronicNonConsumableProduct electronicNonConsumableProduct(
			getProductId(),
			getProductName(),
			getReciverUnitName(),
			getManualDescription(),
			reciverPersonName,
			backupCompanyName);

		outCredit.seekp((getProductId() - 1) * sizeof(ElectronicNonConsumableProduct));
		outCredit.write(reinterpret_cast<const char *>(&electronicNonConsumableProduct),
			sizeof(ElectronicNonConsumableProduct));
	}
	else {
		cerr << "Product #" << electronicNonConsumableProduct.getProductId() << " already contains information." << endl;
		system("pause");
	}
}

void ElectronicNonConsumableProduct::update() {
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
	string reciverPersonName;
	cin >> reciverPersonName;
	setReciverPersonName(reciverPersonName);

	cout << "Backup Company Name: ";
	string backupCompanyName;
	cin >> backupCompanyName;
	setBackupCompanyName(backupCompanyName);

	fstream outCredit("ElectronicNonConsumableProduct.dat", ios::in | ios::out | ios::binary);

	if (!outCredit)
	{
		cerr << "File could not be opened." << endl;
		system("pause");
		exit(1);
	}

	outCredit.seekg((getProductId() - 1) * sizeof(ElectronicNonConsumableProduct));
	ElectronicNonConsumableProduct electronicNonConsumableProduct;
	outCredit.read(reinterpret_cast<char *>(&electronicNonConsumableProduct), sizeof(ElectronicNonConsumableProduct));

	if (electronicNonConsumableProduct.getProductId() != 0)
	{
		outCredit.seekp((getProductId() - 1) * sizeof(ElectronicNonConsumableProduct));
		ElectronicNonConsumableProduct toupdate(
			getProductId(),
			getProductName(),
			getReciverUnitName(),
			getManualDescription(),
			reciverPersonName,
			backupCompanyName);
		outCredit.write(reinterpret_cast<const char *>(&toupdate),
			sizeof(ElectronicNonConsumableProduct));
	}
	else {
		cerr << "Product #" << getProductId() << " has no information." << endl;
		system("pause");
	}
}

void ElectronicNonConsumableProduct::removeRecord() {
	cout << "Please fill the needed information!" << endl;

	cout << "Product Id (1 - 100): ";
	int productId;
	cin >> productId;
	setProductId(productId);

	fstream outCredit("ElectronicNonConsumableProduct.dat", ios::in | ios::out | ios::binary);

	if (!outCredit)
	{
		cerr << "File could not be opened." << endl;
		system("pause");
		exit(1);
	}

	ElectronicNonConsumableProduct electronicNonConsumableProduct;
	outCredit.seekg((getProductId() - 1)*sizeof(ElectronicNonConsumableProduct));
	outCredit.read(reinterpret_cast<char *>(&electronicNonConsumableProduct),
		sizeof(ElectronicNonConsumableProduct));

	if (electronicNonConsumableProduct.getProductId() != 0) {
		ElectronicNonConsumableProduct blank;

		outCredit.seekp((getProductId() - 1) * sizeof(ElectronicNonConsumableProduct));
		outCredit.write(reinterpret_cast<const char *>(&blank),
			sizeof(ElectronicNonConsumableProduct));
	}
	else {
		cerr << "Product #" << electronicNonConsumableProduct.getProductId() << " has no information." << endl;
		system("pause");
	}
}

void ElectronicNonConsumableProduct::printAll() {
	fstream outCredit("ElectronicNonConsumableProduct.dat", ios::in | ios::out | ios::binary);
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
		"Backup Company Name" << " " <<
		"Type" << endl;

	for (int index = 1; index <= 100; index++)
	{
		ElectronicNonConsumableProduct electronicNonConsumableProduct;
		outCredit.seekg((index - 1)*sizeof(ElectronicNonConsumableProduct));
		outCredit.read(reinterpret_cast<char *>(&electronicNonConsumableProduct),
			sizeof(ElectronicNonConsumableProduct));

		if (electronicNonConsumableProduct.getProductId() != 0) {
			electronicNonConsumableProduct.print();
		}
	}
}

void ElectronicNonConsumableProduct::init() {
	ofstream outCredit("ElectronicNonConsumableProduct.dat", ios::binary);
	if (!outCredit)
	{
		cerr << "File could not be opened." << endl;
		exit(1);
	}
	ElectronicNonConsumableProduct electronicNonConsumableProduct;
	for (int i = 0; i < 100; i++)
		outCredit.write(reinterpret_cast<const char *>(&electronicNonConsumableProduct),
			sizeof(ElectronicNonConsumableProduct));
}