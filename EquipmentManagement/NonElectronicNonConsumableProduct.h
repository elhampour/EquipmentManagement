#ifndef NonElectronicNonConsumableProduct_H
#define NonElectronicNonConsumableProduct_H

#include <string>
#include "Product.h"
using namespace std;

class NonElectronicNonConsumableProduct : public Product {
public:
	NonElectronicNonConsumableProduct(int, string, string, string, string, int);

	void setReciverPersonName(string);
	void setMinimumLifeTime(int);

	string getReciverPersonName();
	int getMinimumLifeTime();

	void print() const;

private:
	string reciverPersonName;
	int minimumLifeTime;
};

#endif