#include <iostream>
#include <fstream>
#include <string>
#include "Menu.h"
#include "EdibleConsumableProduct.h"
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

					cout << "Product Id (1 - 100): ";
					int productId;
					cin >> productId;

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

					EdibleConsumableProduct edibleConsumableProduct(
						productId, 
						productName, 
						reciverUnitName, 
						manualDescription, 
						createDate,
						expireDate);

					edibleConsumableProduct.insert();

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
		case '2':
		{
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
