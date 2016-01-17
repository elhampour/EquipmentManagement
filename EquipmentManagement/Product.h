#ifndef Product_H
#define Product_H

#include <string>
using namespace std;

class Product {
public:
	Product(int, string, string, string);

	void setProductId(int);
	void setProductName(string);
	void setReciverUnitName(string);
	void setManualDescription(string);

	int getProductId();
	string getProductName();
	string getReciverUnitName();
	string getManualDescription();

	virtual void print() const;

private:
	int productId;
	string productName;
	string reciverUnitName;
	string manualDescription;
};

#endif