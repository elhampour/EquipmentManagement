#ifndef ElectronicNonConsumableProduct_H
#define ElectronicNonConsumableProduct_H

#include <string>
#include "Product.h"
using namespace std;

class ElectronicNonConsumableProduct : public Product {
public:
	ElectronicNonConsumableProduct(int = 0, string = "", string = "", string = "", string = "", string = "");

	void setReciverPersonName(string);
	void setBackupCompanyName(string);

	string getReciverPersonName() const;
	string getBackupCompanyName() const;

	void print() const;
	void insert();
	void update();
	void removeRecord();
	void printAll();

private:
	char reciverPersonName[15];
	char backupCompanyName[15];
};

#endif