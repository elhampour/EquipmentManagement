#include "EdibleConsumableProduct.h"
#include <iostream>
#include <fstream>
using namespace std;

EdibleConsumableProduct::EdibleConsumableProduct(
	int id,
	string name,
	string rName,
	string mDescription,
	string cDate,
	string eDate) :
	Product(id, name, rName, mDescription) {
	setCreateDate(cDate);
	setExpireDate(eDate);
}

void EdibleConsumableProduct::setCreateDate(string cDate) {
	const char *lastNameValue = cDate.data();
	int length = cDate.size();
	length = (length < 15 ? length : 14);
	strncpy_s(createDate, lastNameValue, length);
	createDate[length] = '\0';
}

void EdibleConsumableProduct::setExpireDate(string eDate) {
	const char *lastNameValue = eDate.data();
	int length = eDate.size();
	length = (length < 15 ? length : 14);
	strncpy_s(expireDate, lastNameValue, length);
	expireDate[length] = '\0';
}

string EdibleConsumableProduct::getCreateDate() const {
	return createDate;
}

string EdibleConsumableProduct::getExpireDate() const {
	return expireDate;
}

void EdibleConsumableProduct::print() const {
	Product::print();
	cout << createDate << " " << expireDate << " " << "EC" << endl;
}

void EdibleConsumableProduct::insert() {

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

	cout << "Create Date : ";
	string createDate;
	cin >> createDate;
	setCreateDate(createDate);

	cout << "Expire Date : ";
	string expireDate;
	cin >> expireDate;
	setExpireDate(expireDate);

	fstream outCredit("EdibleConsumableProduct.dat", ios::in | ios::out | ios::binary);

	if (!outCredit)
	{
		cerr << "File could not be opened." << endl;
		system("pause");
		exit(1);
	}

	EdibleConsumableProduct edibleConsumableProduct;
	outCredit.seekg((getProductId() - 1)*sizeof(EdibleConsumableProduct));
	outCredit.read(reinterpret_cast<char *>(&edibleConsumableProduct),
		sizeof(EdibleConsumableProduct));

	if (edibleConsumableProduct.getProductId() == 0) {
		EdibleConsumableProduct edibleConsumableProduct(
			getProductId(),
			getProductName(),
			getReciverUnitName(),
			getManualDescription(),
			createDate,
			expireDate);

		outCredit.seekp((getProductId() - 1) * sizeof(EdibleConsumableProduct));
		outCredit.write(reinterpret_cast<const char *>(&edibleConsumableProduct),
			sizeof(EdibleConsumableProduct));
	}
	else {
		cerr << "Product #" << edibleConsumableProduct.getProductId() << " already contains information." << endl;
		system("pause");
	}
}

void EdibleConsumableProduct::update() {
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

	cout << "Create Date : ";
	string createDate;
	cin >> createDate;
	setCreateDate(createDate);

	cout << "Expire Date : ";
	string expireDate;
	cin >> expireDate;
	setExpireDate(expireDate);

	fstream outCredit("EdibleConsumableProduct.dat", ios::in | ios::out | ios::binary);

	if (!outCredit)
	{
		cerr << "File could not be opened." << endl;
		system("pause");
		exit(1);
	}

	outCredit.seekg((getProductId() - 1) * sizeof(EdibleConsumableProduct));
	EdibleConsumableProduct edibleConsumableProduct;
	outCredit.read(reinterpret_cast<char *>(&edibleConsumableProduct), sizeof(EdibleConsumableProduct));

	if (edibleConsumableProduct.getProductId() != 0)
	{
		outCredit.seekp((getProductId() - 1) * sizeof(EdibleConsumableProduct));
		EdibleConsumableProduct toupdate(
			getProductId(),
			getProductName(),
			getReciverUnitName(),
			getManualDescription(),
			createDate,
			expireDate);
		outCredit.write(reinterpret_cast<const char *>(&toupdate),
			sizeof(EdibleConsumableProduct));
	}
	else {
		cerr << "Product #" << getProductId() << " has no information." << endl;
		system("pause");
	}
}

void EdibleConsumableProduct::removeRecord() {
	cout << "Please fill the needed information!" << endl;

	cout << "Product Id (1 - 100): ";
	int productId;
	cin >> productId;
	setProductId(productId);

	fstream outCredit("EdibleConsumableProduct.dat", ios::in | ios::out | ios::binary);

	if (!outCredit)
	{
		cerr << "File could not be opened." << endl;
		system("pause");
		exit(1);
	}

	EdibleConsumableProduct edibleConsumableProduct;
	outCredit.seekg((getProductId() - 1)*sizeof(EdibleConsumableProduct));
	outCredit.read(reinterpret_cast<char *>(&edibleConsumableProduct),
		sizeof(EdibleConsumableProduct));

	if (edibleConsumableProduct.getProductId() != 0) {
		EdibleConsumableProduct blankEdibleConsumableProduct;

		outCredit.seekp((getProductId() - 1) * sizeof(EdibleConsumableProduct));
		outCredit.write(reinterpret_cast<const char *>(&blankEdibleConsumableProduct),
			sizeof(EdibleConsumableProduct));
	}
	else {
		cerr << "Product #" << edibleConsumableProduct.getProductId() << " has no information." << endl;
		system("pause");
	}
}

void EdibleConsumableProduct::printAll() {
	fstream outCredit("EdibleConsumableProduct.dat", ios::in | ios::out | ios::binary);
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
		"Create Date" << " " <<
		"Expire Date" << " " <<
		"Type" << endl;

	for (int index = 1; index <= 100; index++)
	{
		EdibleConsumableProduct edibleConsumableProduct;
		outCredit.seekg((index - 1)*sizeof(EdibleConsumableProduct));
		outCredit.read(reinterpret_cast<char *>(&edibleConsumableProduct),
			sizeof(EdibleConsumableProduct));

		if (edibleConsumableProduct.getProductId() != 0) {
			edibleConsumableProduct.print();
		}
	}
}

void EdibleConsumableProduct::init() {
	ofstream outCredit("EdibleConsumableProduct.dat", ios::binary);
	if (!outCredit)
	{
		cerr << "File could not be opened." << endl;
		exit(1);
	}
	EdibleConsumableProduct blankEdibleConsumableProduct;
	for (int i = 0; i < 100; i++)
		outCredit.write(reinterpret_cast<const char *>(&blankEdibleConsumableProduct),
			sizeof(EdibleConsumableProduct));
}
