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
	createDate[length] = '\0'; // append null character to lastName
}

void EdibleConsumableProduct::setExpireDate(string eDate) {
	const char *lastNameValue = eDate.data();
	int length = eDate.size();
	length = (length < 15 ? length : 14);
	strncpy_s(expireDate, lastNameValue, length);
	expireDate[length] = '\0'; // append null character to lastName
}

string EdibleConsumableProduct::getCreateDate() const{
	return createDate;
}

string EdibleConsumableProduct::getExpireDate() const {
	return expireDate;
}

void EdibleConsumableProduct::print() const {
	Product::print();
	cout << "\nCreate Date  : " << createDate
		<< "\nExpire Date : " << expireDate << endl;
}

void EdibleConsumableProduct::insert() {

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

	if (edibleConsumableProduct.getProductId()==0) {
		EdibleConsumableProduct edibleConsumableProduct(
			getProductId(),
			getProductName(),
			getReciverUnitName(),
			getManualDescription(),
			createDate,
			expireDate);

		outCredit.seekp((getProductId() - 1) * sizeof(EdibleConsumableProduct));
		outCredit.write(reinterpret_cast< const char * >(&edibleConsumableProduct),
			sizeof(EdibleConsumableProduct));
	}
	else {
		cerr << "Product #" << edibleConsumableProduct.getProductId() << " already contains information." << endl;
		system("pause");
	}

	
}