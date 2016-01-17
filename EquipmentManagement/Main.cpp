#include <iostream>
#include <fstream>
#include <string>
#include "Menu.h"
#include "EdibleConsumableProduct.h"
using namespace std;

int main()
{
	Menu menu;
	menu.printMainMenu();

	while (true)
	{
		menu.printChoiceMessage();

		char userChoice;
		cin >> userChoice;
		switch (userChoice)
		{
		case '1':
		{
			system("cls");

			menu.printProductChoice();
			menu.printAddProductMenu();
			menu.printChoiceMessage();

			char userProductChoice;

			bool productWhile = true;
			while (productWhile) {
				cin >> userProductChoice;
				switch (userProductChoice)
				{
				case '1':
				{
					cout << "EdibleConsumableProduct" << endl;
					cout << "Please fill the needed information!" << endl;

					cout << "Product Name : ";
					string productName;
					cin >> productName;

					cout << "Reciver Unit Name : ";
					string reciverUnitName;
					cin >> reciverUnitName;

					cout << "Manual Description : ";
					string manualDescription;
					cin >> manualDescription;

					cout << "Create Date : ";
					string createDate;
					cin >> createDate;

					cout << "Expire Date : ";
					string expireDate;
					cin >> expireDate;

					EdibleConsumableProduct edibleConsumableProduct(1, productName, reciverUnitName, manualDescription, createDate, expireDate);
					edibleConsumableProduct.print();

					system("cls");
					menu.printProductChoice();
					menu.printAddProductMenu();
					menu.printChoiceMessage();
				}
				break;
				case '2':
					cout << "ElectronicNonConsumableProduct" << endl;
					break;
				case '3':
					cout << "NonEdibleConsumableProduct" << endl;
					break;
				case '4':
					cout << "NonElectronicNonConsumableProduct" << endl;
					break;
				case '5':
					productWhile = false;
					system("cls");
					menu.printMainMenu();
					break;
				default:
					cout << "your choice is not right" << endl;
					break;
				}
			}
			break;
		}
		case '6':
			cout << "your choice is 6" << endl;
			return 0;
		default:
			cout << "your choice is not right" << endl;
			break;
		}
	}

	return 0;
}
