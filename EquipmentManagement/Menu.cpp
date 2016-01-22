#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu() {
}

void Menu::printMainMenu()
{
	cout << "1) Choose product type to manipulate" << endl;
	cout << "2) List All Products" << endl;
	cout << "3) Exit" << endl;
	cout << "Please make your choice : " << endl;
}

void Menu::printProductTypeMenu()
{
	cout << "Choose product type to manipulate :" << endl;
	cout << "1) EdibleConsumableProduct" << endl;
	cout << "2) ElectronicNonConsumableProduct" << endl;
	cout << "3) NonEdibleConsumableProduct" << endl;
	cout << "4) NonElectronicNonConsumableProduct" << endl;
	cout << "5) Back" << endl;
	cout << "Please make your choice : " << endl;
}

void Menu::printProductMenu(string type) {
	cout << "Product Type : " << type << endl;
	cout << "Choose your choice :" << endl;
	cout << "1) Add" << endl;
	cout << "2) Edit" << endl;
	cout << "3) Delete" << endl;
	cout << "4) List" << endl;
	cout << "5) Back" << endl;
	cout << "Please make your choice : " << endl;
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