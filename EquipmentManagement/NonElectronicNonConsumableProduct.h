#ifndef NonElectronicNonConsumableProduct_H
#define NonElectronicNonConsumableProduct_H

#include <string>
#include "Product.h"
using namespace std;

class NonElectronicNonConsumableProduct : public Product {
public:
	NonElectronicNonConsumableProduct(int = 0, string = "", string = "", string = "", string = "", int = 0);

	void setReciverPersonName(string);
	void setMinimumLifeTime(int);

	string getReciverPersonName() const;
	int getMinimumLifeTime()const;

	void print() const;
	void insert();
	void update();
	void removeRecord();
	void printAll();
	void init();
private:
	char reciverPersonName[15];
	int minimumLifeTime;
};

#endif