#ifndef EdibleConsumableProduct_H
#define EdibleConsumableProduct_H

#include <string>
#include "Product.h"
using namespace std;

class EdibleConsumableProduct : public Product {
public:
	EdibleConsumableProduct(int, string, string, string, string, string);

	void setCreateDate(string);
	void setExpireDate(string);

	string getCreateDate();
	string getExpireDate();

	void print() const;

private:
	string createDate;
	string expireDate;
};

#endif