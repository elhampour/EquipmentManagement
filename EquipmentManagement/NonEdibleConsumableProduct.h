#ifndef NonEdibleConsumableProduct_H
#define NonEdibleConsumableProduct_H

#include <string>
#include "Product.h"
using namespace std;

class NonEdibleConsumableProduct : public Product {
public:
	NonEdibleConsumableProduct(int, string, string, string, string);

	void setReciverPersonName(string);

	string getReciverPersonName();

	void print() const;

private:
	string reciverPersonName;
};

#endif