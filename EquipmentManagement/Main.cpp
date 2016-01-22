#include <iostream>
#include <fstream>
#include <string>
#include "Menu.h"
#include "EdibleConsumableProduct.h"
#include "ElectronicNonConsumableProduct.h"
#include "NonEdibleConsumableProduct.h"
#include "NonElectronicNonConsumableProduct.h"
using namespace std;

//int main() {
//
//	ofstream outCredit("EdibleConsumableProduct.dat", ios::binary);
//		// exit program if ofstream could not open file
//		if (!outCredit)
//		{
//		cerr << "File could not be opened." << endl;
//		exit(1);
//		} // end if
//	EdibleConsumableProduct blankEdibleConsumableProduct; // constructor zeros out each data member
//		 // output 100 blank records to file
//		 for (int i = 0; i < 100; i++)
//		 outCredit.write(reinterpret_cast< const char *>(&blankEdibleConsumableProduct),
//			 sizeof(EdibleConsumableProduct));
//	return 0;
//};

int main()
{
	while (true) {
		system("cls");

		Menu menu;
		menu.printMainMenu();

		char userChoice;
		cin >> userChoice;
		switch (userChoice)
		{
		case '1':
		{
			bool productChoiceWhile = true;

			while (productChoiceWhile) {
				system("cls");
				menu.printProductTypeMenu();
				
				char productChoice;
				cin >> productChoice;

				switch (productChoice)
				{
				case '1': {
					bool edibleConsumableProductWhile = true;
					while (edibleConsumableProductWhile) {
						system("cls");
						menu.printProductMenu("EdibleConsumableProduct");
						char edibleConsumableProductChoice;
						cin >> edibleConsumableProductChoice;
						EdibleConsumableProduct edibleConsumableProduct;
						switch (edibleConsumableProductChoice)
						{
						case '1': {
							edibleConsumableProduct.insert();
							break;
						}
						case '2': {
							edibleConsumableProduct.update();
							break;
						}
						case '3': {
							edibleConsumableProduct.removeRecord();
							break;
						}
						case '4': {
							edibleConsumableProduct.printAll();
							system("pause");
							break;
						}
						case '5': {
							cout << "5";
							edibleConsumableProductWhile = false;
							break;
						}
						default: {
							cout << "your choice is not right" << endl;
							break;
						}
						}
					}
					break;
				}
				case '2': {
					bool electronicNonConsumableProductWhile = true;
					while (electronicNonConsumableProductWhile) {
						system("cls");
						menu.printProductMenu("Electronic Non Consumable Product");
						char electronicNonConsumableProductChoice;
						cin >> electronicNonConsumableProductChoice;
						ElectronicNonConsumableProduct electronicNonConsumableProduct;
						switch (electronicNonConsumableProductChoice)
						{
						case '1': {
							electronicNonConsumableProduct.insert();
							break;
						}
						case '2': {
							electronicNonConsumableProduct.update();
							break;
						}
						case '3': {
							electronicNonConsumableProduct.removeRecord();
							break;
						}
						case '4': {
							electronicNonConsumableProduct.printAll();
							system("pause");
							break;
						}
						case '5': {
							cout << "5";
							electronicNonConsumableProductWhile = false;
							break;
						}
						default: {
							cout << "your choice is not right" << endl;
							break;
						}
						}
					}
					break;
				}
				case '3': {
					bool nonEdibleConsumableProductWhile = true;
					while (nonEdibleConsumableProductWhile) {
						system("cls");
						menu.printProductMenu("Non Edible Consumable Product");
						char nonEdibleConsumableProductChoice;
						cin >> nonEdibleConsumableProductChoice;
						NonEdibleConsumableProduct nonEdibleConsumableProduct;
						switch (nonEdibleConsumableProductChoice)
						{
						case '1': {
							nonEdibleConsumableProduct.insert();
							break;
						}
						case '2': {
							nonEdibleConsumableProduct.update();
							break;
						}
						case '3': {
							nonEdibleConsumableProduct.removeRecord();
							break;
						}
						case '4': {
							nonEdibleConsumableProduct.printAll();
							system("pause");
							break;
						}
						case '5': {
							cout << "5";
							nonEdibleConsumableProductWhile = false;
							break;
						}
						default: {
							cout << "your choice is not right" << endl;
							break;
						}
						}
					}
					break;
				}
				case '4': {
					bool nonElectronicNonConsumableProductWhile = true;
					while (nonElectronicNonConsumableProductWhile) {
						system("cls");
						menu.printProductMenu("NonElectronic NonConsumable Product");
						char nonElectronicNonConsumableProductChoice;
						cin >> nonElectronicNonConsumableProductChoice;
						NonElectronicNonConsumableProduct nonElectronicNonConsumableProduct;
						switch (nonElectronicNonConsumableProductChoice)
						{
						case '1': {
							nonElectronicNonConsumableProduct.insert();
							break;
						}
						case '2': {
							nonElectronicNonConsumableProduct.update();
							break;
						}
						case '3': {
							nonElectronicNonConsumableProduct.removeRecord();
							break;
						}
						case '4': {
							nonElectronicNonConsumableProduct.printAll();
							system("pause");
							break;
						}
						case '5': {
							cout << "5";
							nonElectronicNonConsumableProductWhile = false;
							break;
						}
						default: {
							cout << "your choice is not right" << endl;
							break;
						}
						}
					}
					break;
				}
				case '5': {
					productChoiceWhile = false;
					break;
				}
				default: {
					cout << "your choice is not right" << endl;
					break;
				}
				}
			}
			break;
		}
		case '2': {
			EdibleConsumableProduct showAllEdibleConsumableProduct;
			ElectronicNonConsumableProduct showAllElectronicNonConsumableProduct;
			NonEdibleConsumableProduct showALlNonEdibleConsumableProduct;
			NonElectronicNonConsumableProduct showAllNonElectronicNonConsumableProduct;

			showAllEdibleConsumableProduct.printAll();
			showAllElectronicNonConsumableProduct.printAll();
			showALlNonEdibleConsumableProduct.printAll();
			showAllNonElectronicNonConsumableProduct.printAll();

			system("pause");

			break;
		}
		case '3': {
			EdibleConsumableProduct showAllEdibleConsumableProduct;
			ElectronicNonConsumableProduct showAllElectronicNonConsumableProduct;
			NonEdibleConsumableProduct showALlNonEdibleConsumableProduct;
			NonElectronicNonConsumableProduct showAllNonElectronicNonConsumableProduct;

			showAllEdibleConsumableProduct.init();
			showAllElectronicNonConsumableProduct.init();
			showALlNonEdibleConsumableProduct.init();
			showAllNonElectronicNonConsumableProduct.init();

			system("pause");
			break;
		}
		case '4': {
			return 0;
			break;
		}
		default: {
			cout << "your choice is not right" << endl;
			break;
		}
		}
	}

	return 0;
}

