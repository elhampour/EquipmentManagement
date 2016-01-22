#ifndef EdibleConsumableProduct_H
#define EdibleConsumableProduct_H

#include <string>
#include "Product.h"
using namespace std;

class EdibleConsumableProduct : public Product {
public:
	EdibleConsumableProduct(int = 0, string = "", string = "", string = "", string = "", string = "");

	void setCreateDate(string);
	void setExpireDate(string);

	string getCreateDate() const;
	string getExpireDate()const;

	void print() const;
	void insert();
	void update();
	void removeRecord();
	void printAll();
private:
	char createDate[15];
	char expireDate[15];
};

#endif