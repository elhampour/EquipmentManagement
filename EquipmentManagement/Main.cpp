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
	while (true) {
		system("cls");
		cout << "1) Choose product type to manipulate" << endl;
		cout << "2) List All Products" << endl;
		cout << "3) Exit" << endl;
		cout << "Please make your choice : " << endl;

		char userChoice;
		cin >> userChoice;
		switch (userChoice)
		{
		case '1':
		{
			bool productChoiceWhile = true;

			while (productChoiceWhile) {
				system("cls");
				cout << "Choose product type to manipulate :" << endl;

				cout << "1) EdibleConsumableProduct" << endl;
				cout << "2) ElectronicNonConsumableProduct" << endl;
				cout << "3) NonEdibleConsumableProduct" << endl;
				cout << "4) NonElectronicNonConsumableProduct" << endl;
				cout << "5) Back" << endl;

				cout << "Please make your choice : " << endl;
				char productChoice;
				cin >> productChoice;

				switch (productChoice)
				{
				case '1': {
					bool edibleConsumableProductWhile = true;
					while (edibleConsumableProductWhile) {
						system("cls");
						cout << "Product Type : EdibleConsumableProduct" << endl;
						cout << "Choose your choice :" << endl;
						cout << "1) Add" << endl;
						cout << "2) Edit" << endl;
						cout << "3) Delete" << endl;
						cout << "4) List" << endl;
						cout << "5) Back" << endl;

						cout << "Please make your choice : " << endl;
						char edibleConsumableProductChoice;
						cin >> edibleConsumableProductChoice;

						switch (edibleConsumableProductChoice)
						{
						case '1': {
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
							break;
						}
						case '2': {
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

							edibleConsumableProduct.update();

							break;
						}
						case '3': {
							cout << "Please fill the needed information!" << endl;

							cout << "Product Id (1 - 100): ";
							int productId;
							cin >> productId;

							EdibleConsumableProduct edibleConsumableProduct(productId);

							edibleConsumableProduct.removeRecord();

							break;
						}
						case '4': {
							EdibleConsumableProduct showAllEdibleConsumableProduct;
							showAllEdibleConsumableProduct.printAll();

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
						cout << "Product Type : ElectronicNonConsumableProduct" << endl;
						cout << "Choose your choice :" << endl;
						cout << "1) Add" << endl;
						cout << "2) Edit" << endl;
						cout << "3) Delete" << endl;
						cout << "4) List" << endl;
						cout << "5) Back" << endl;

						cout << "Please make your choice : " << endl;
						char electronicNonConsumableProductChoice;
						cin >> electronicNonConsumableProductChoice;

						switch (electronicNonConsumableProductChoice)
						{
						case '1': {
							cout << "1";
							break;
						}
						case '2': {
							cout << "2";
							break;
						}
						case '3': {
							cout << "3";
							break;
						}
						case '4': {
							cout << "4";
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
						cout << "Product Type : NonEdibleConsumableProduct" << endl;
						cout << "Choose your choice :" << endl;
						cout << "1) Add" << endl;
						cout << "2) Edit" << endl;
						cout << "3) Delete" << endl;
						cout << "4) List" << endl;
						cout << "5) Back" << endl;

						cout << "Please make your choice : " << endl;
						char nonEdibleConsumableProductChoice;
						cin >> nonEdibleConsumableProductChoice;

						switch (nonEdibleConsumableProductChoice)
						{
						case '1': {
							cout << "1";
							break;
						}
						case '2': {
							cout << "2";
							break;
						}
						case '3': {
							cout << "3";
							break;
						}
						case '4': {
							cout << "4";
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
						cout << "Product Type : NonElectronicNonConsumableProduct" << endl;
						cout << "Choose your choice :" << endl;
						cout << "1) Add" << endl;
						cout << "2) Edit" << endl;
						cout << "3) Delete" << endl;
						cout << "4) List" << endl;
						cout << "5) Back" << endl;

						cout << "Please make your choice : " << endl;
						char nonElectronicNonConsumableProductChoice;
						cin >> nonElectronicNonConsumableProductChoice;

						switch (nonElectronicNonConsumableProductChoice)
						{
						case '1': {
							cout << "1";
							break;
						}
						case '2': {
							cout << "2";
							break;
						}
						case '3': {
							cout << "3";
							break;
						}
						case '4': {
							cout << "4";
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
			showAllEdibleConsumableProduct.printAll();

			system("pause");
			break;
		}
		case '3': {
			return 0;
			break;
		}
		default: {
			cout << "your choice is not right" << endl;
			break;
		}
		}
	}

	/*Menu menu;
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
	}*/

	return 0;
}

