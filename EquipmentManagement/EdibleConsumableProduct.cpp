#include "EdibleConsumableProduct.h"
#include <iostream>
using namespace std;

EdibleConsumableProduct::EdibleConsumableProduct(
	int id, string name, string rName, string mDescription, string cDate, string eDate) :
	Product(id, name, rName, mDescription) {
	setCreateDate(cDate);
	setExpireDate(eDate);
}

void EdibleConsumableProduct::setCreateDate(string cDate) {
	createDate = cDate;
}

void EdibleConsumableProduct::setExpireDate(string eDate) {
	expireDate = eDate;
}

string EdibleConsumableProduct::getCreateDate() {
	return createDate;
}

string EdibleConsumableProduct::getExpireDate() {
	return expireDate;
}

void EdibleConsumableProduct::print() const {
	Product::print();
	cout << "\nCreate Date  : " << createDate
		<< "\nExpire Date : " << expireDate << endl;
}