#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu() {
}

void Menu::printMainMenu()
{
	cout << "1) Add a product" << endl;
	cout << "6) Exit" << endl;
}

void Menu::printChoiceMessage() 
{
	cout << "Please make your choice : " << endl;
}

void Menu::printProductChoice()
{
	cout << "Please choose the product type to add : " << endl;
}

void Menu::printAddProductMenu() {
	cout << "1) EdibleConsumableProduct" << endl;
	cout << "2) ElectronicNonConsumableProduct" << endl;
	cout << "3) NonEdibleConsumableProduct" << endl;
	cout << "4) NonElectronicNonConsumableProduct" << endl;
	cout << "5) Back to Main Menu" << endl;
}