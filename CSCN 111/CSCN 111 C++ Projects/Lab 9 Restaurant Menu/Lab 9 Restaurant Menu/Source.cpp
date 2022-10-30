/*
	Write a program to help a local restaurant automate its breakfast billing system. The 	program should do the following:

	1. Show the customer the different breakfast items offered by the restaurant.

	2. Allow the customer to select more than one item from the menu.

	3. Calculate and print the bill.

	Use an array menuList of type MenuItemType. MenuItemType consists of three components:
		menuItem of type string,
		menuPrice of type double, and
		isOrdered of type bool.

	Your program must contain at least the following functions:

	1. Function getData: This function loads the data into the array menuList.

	2. Function showMenu: This function shows the different items offered by the restaurant and tells the user how to select the items.

	3. Function printCheck: This function calculates and prints the check. (Note that the billing amount should include a 5% tax.)

	Format your output with two decimal places. The name of each item in the output must be left justified. You may assume that the user
	selects only one item of a particular type.

	Algorithm:

		main
		{
			GetData
			do {
				showMenu
			} while not done
			printCheck
		}
*/

//Include statements
#include <iostream>
#include <string>
#include <iomanip>
#include<fstream>

using namespace std;

//Global declarations: Constants and type definitions only -- no variables
const int NoOfItems = 8;

struct MenuItemType
{
	string menuItem;
	double menuPrice;
	bool isOrdered{ false };
};
//Function prototypes
void getData(MenuItemType mList[], int listSize);
void showMenu(MenuItemType mList[], int listSize);
void printCheck(MenuItemType mList[], int listSize, double taxRate);
void makeSelection(MenuItemType mList[], int listSize);
bool endProgram(MenuItemType mList[], int listSize);

void wait();	

int main()
{
	//In cout statement below substitute your name and lab number
	cout << "Andres Choque -- Lab 9" << endl << endl;

	//Variable declarations
	double taxRate = 0.05;
	int i = 0;
	bool end = false;
	bool invalid = false;
	int listSize = NoOfItems;
	MenuItemType mList[NoOfItems];
	string exit;
	fstream infile;

	//Program logic
	getData(mList, listSize);
	showMenu(mList, listSize);

	if (endProgram(mList, listSize) == true)
		system("cls");
	else
		do
		{
			showMenu(mList, listSize);

			makeSelection(mList, listSize);



		} while (!endProgram(mList, listSize));


	printCheck(mList, listSize, taxRate);

	//Closing program statements
	wait(); //Halts program until the user is ready to finish
	return 0;
}

void getData(MenuItemType mList[], int listSize)
{
	fstream infile;
	infile.open("menu.txt");
	if (!infile)
		printf("Could not open file");
	else
	{

		for (int i = 0; i < listSize; ++i)
		{
			getline(infile, mList[i].menuItem);
			infile >> mList[i].menuPrice;
			infile.ignore();

		}
		printf("File Loaded \n");
	}

	infile.close();
}

void showMenu(MenuItemType mList[], int listSize)
{
	printf("Welcome to Johnny's Restaurant \n");
	printf("----Today's Menu---- \n");
	for (int i{}; i < listSize; ++i)
	{
		cout << i + 1 << "." << setw(14) << left << mList[i].menuItem << setw(10) << right << setprecision(2) << fixed << showpoint << "$" << mList[i].menuPrice << endl;
	}
	cout << endl;

	for (int i{}; i < listSize; ++i)
	{
		if (mList[i].isOrdered == true)
			cout << "Enter Item Number: " << i + 1 << endl;
		else
			;
	}
}

void printCheck(MenuItemType mList[], int listSize, double taxRate)
{
	double total;
	double subTotal = 0;
	int i = 0;
	cout << endl;

	printf("Welcome to Johnny's Restaurant \n");
	for (int i{}; i < listSize; ++i)
	{
		if (mList[i].isOrdered == true)
		{
			cout << setw(16) << left << mList[i].menuItem << setw(10) << right << setprecision(2) << fixed << showpoint << "$" << mList[i].menuPrice << endl;
			subTotal = mList[i].menuPrice + subTotal;
		}
		else
			;
	}
	total = (subTotal * taxRate) + subTotal;


	cout << "------------------------------" << endl;
	cout << setw(16) << left << "Subtotal" << setw(10) << right << setprecision(2) << fixed << showpoint << "$" << subTotal << endl;
	cout << setw(16) << left << "Tax" << setw(10) << right << setprecision(2) << fixed << showpoint << "$" << subTotal * taxRate << endl;
	cout << "------------------------------" << endl;
	cout << setw(16) << left << "Amount Due" << setw(10) << right << setprecision(2) << fixed << showpoint << "$" << total << endl << endl;
}

void makeSelection(MenuItemType mList[], int listSize)
{
	int itemNumber;
	printf("Enter Item Number: ");
	cin >> itemNumber;
	while (cin.fail())
	{
		printf("Invalid Entry. Please Try Again \n");
		cin.clear();
		cin.ignore(256, '\n');
		cin >> itemNumber;
	}

	if (itemNumber <= listSize && itemNumber > 0)
	{
		if (mList[itemNumber - 1].isOrdered == false)
			mList[itemNumber - 1].isOrdered = true;
		else
			printf("Item Already Ordered. Please Try Again \n");
	}
	else
		printf("Invalid Entry. Please Try Again \n");

}

bool endProgram(MenuItemType mList[], int listSize)
{
	bool invalid{ false };
	string exit;
	bool end{ false };
	int i{};
	int end_1{ 0 };
	for (int i{}; i < listSize; ++i)
	{
		if (mList[i].isOrdered == true)
			end_1 = end_1 + 1;
		else
			;
	}

	if (end_1 >= listSize)
		end = true;
	else;

	if (end == false)
	{
		do
		{
			invalid = false;
			cout << endl << endl;
			cout << "Do you want to make a selection? (Y/y) for Yes (N/n) for No: " << endl;
			cin >> exit;
			if (exit == "Y" || exit == "y")
				end = false;
			else if (exit == "N" || exit == "n")
				end = true;
			else
			{
				cout << "Invalid Entry Please Try Again. " << endl;
				invalid = true;
			}
		} while (invalid);
	}
	else
		printf("All Items Selected. \n \n");

	if (end == false)
		system("cls");
	else
	{
		system("cls");
		cout << "Andres Choque -- Lab 9" << endl << endl;

		printf("Welcome to Johnny's Restaurant \n");
		for (int i{}; i < listSize; ++i)
		{
			cout << i + 1 << "." << setw(14) << left << mList[i].menuItem << setw(10) << right << setprecision(2) << fixed << showpoint << "$" << mList[i].menuPrice << endl;
		}
		cout << endl;

		for (int i{}; i < listSize; ++i)
		{
			if (mList[i].isOrdered == true)
				cout << "Enter Item Number: " << i + 1 << endl;
			else;
		}
	}
	return end;
}

//Function Definitions
void wait()
{
	//The following if-statement checks to see how mnay characters are in the cin's buffer
	//If the buffer has characters in it, the clear and ignore methods get rid of them.
	if (cin.rdbuf()->in_avail() > 0) //If the buffer is empty skip clear and ignore
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Clear the input buffer
	}
	char ch;
	cout << "Press the Enter key to continue ... ";
	cin.get(ch);
}