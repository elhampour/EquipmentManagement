#ifndef ElectronicNonConsumableProduct_H
#define ElectronicNonConsumableProduct_H

#include <string>
#include "Product.h"
using namespace std;

class ElectronicNonConsumableProduct : public Product {
public:
	ElectronicNonConsumableProduct(int, string, string, string, string, string);

	void setReciverPersonName(string);
	void setBackupCompanyName(string);

	string getReciverPersonName();
	string getBackupCompanyName();

	void print() const;

private:
	string reciverPersonName;
	string backupCompanyName;
};

#endif