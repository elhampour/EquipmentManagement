#ifndef Menu_H
#define Menu_H

#include <string>
using namespace std;

class Menu {
public:
	Menu();

	void printMainMenu();
	void printProductTypeMenu();
	void printProductMenu(string);

	void printChoiceMessage();
	void printProductChoice();
	void printAddProductMenu();
};

#endif