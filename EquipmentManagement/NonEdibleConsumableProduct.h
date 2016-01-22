#ifndef NonEdibleConsumableProduct_H
#define NonEdibleConsumableProduct_H

#include <string>
#include "Product.h"
using namespace std;

class NonEdibleConsumableProduct : public Product {
public:
	NonEdibleConsumableProduct(int = 0, string = "", string = "", string = "", string = "");

	void setReciverPersonName(string);

	string getReciverPersonName() const;

	void print() const;
	void insert();
	void update();
	void removeRecord();
	void printAll();
	void init();
private:
	char reciverPersonName[15];
};

#endif