#ifndef Product_H
#define Product_H

#include <string>
using namespace std;

class Product {
public:
	Product(int = 0, string = "", string = "", string = "");

	void setProductId(int);
	void setProductName(string);
	void setReciverUnitName(string);
	void setManualDescription(string);

	int getProductId() const;
	string getProductName()const;
	string getReciverUnitName()const;
	string getManualDescription()const;

	virtual void print() const;
	virtual void insert();

private:
	int productId;
	char productName[15];
	char reciverUnitName[15];
	char manualDescription[15];
};

#endif