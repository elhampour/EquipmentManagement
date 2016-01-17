#ifndef Menu_H
#define Menu_H

#include <string>
using namespace std;

class Menu {
public:
	Menu();

	void printMainMenu();
	void printChoiceMessage();
	void printProductChoice();
	void printAddProductMenu();
};

#endif