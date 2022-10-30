/******************************************************************************
(Apartment problem) A real estate office handles, say, 50 apartment units.
When the rent is, say, $600 per month, all the units are occupied. However,
for each, say, $40 increase in rent, one unit becomes vacant. Moreover, each
occupied unit requires an average of $27 per month for maintenance. How many
units should be rented to maximize the profit?

Write a program that reads the following from an input file (provided)

	The total number of units.

	The rent to occupy all the units.

	The Amount to maintain a rented unit (maintenance fee).

And prompts the user to enter the following:

	The increase in rent that results in a vacant unit.

The program then outputs the number of units to be rented to maximize the profit.
Algorithm:
	while (profit goes up)
	{
		increase the monthly rent
		decrease number of units rented by one
		calculate the profit which is (rent - maintenance fee) * number of units rented
	}
	output the results (remember to back out the last changes made to monthly rent,
	number of units, and profit above -- why do you need to back out the last changes)
		number of units rented
		monthly rent
		total profit

Malik, Ch 6, Programming Exercise 28 (page 345)
******************************************************************************/
//Include statements
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
//include any missing standard libraries required to complete the program

using namespace std;

//Global declarations: Constants and type definitions only -- no variables

//Function prototypes
void wait();

int main()
{
	//In cout statement below substitute your name and lab number
	cout << "<Andres Choque> -- Lab 5" << endl << endl;

	//Variable declarations
	ifstream input;
	int totUnits; //total number of units
	double rentCost; //rent to occupy all the units
	double maintCost; //maintanence cost
	double vacantIUnit; //increase in rent that results in a vacant unit
	double oldProfit = 0; //old profit from the given values
	double oldRentPerUnit = 0; //old value for rent cost
	double newRentPerUnit = 0; //new value for rent cost
	double newProfit = 0; //new profit from the values
	double profitIncrease = 0; //the increase in profit
	double profit = 0; //the value of profit

	input.open("input.dat");
	input >> totUnits;
	input >> rentCost;
	input >> maintCost;
	input.close();

	cout << "Amount of rent increase that causes vacant units:  " << endl;
	cin >> vacantIUnit;

	//Program logic
	do
	{
		oldProfit = ((rentCost)-maintCost) * totUnits;
		rentCost = rentCost + vacantIUnit;
		totUnits = totUnits - 1;
		newProfit = (rentCost - maintCost) * totUnits;
		profitIncrease = newProfit - oldProfit;

	} while (profitIncrease > 0);

	profit = oldProfit;

	cout << endl;

	if (profitIncrease == 0)
	{
		cout << "In the values selected there are two different room filled amounts that maximize the profit." << endl;
		cout << "The rent per unit value of: $" << rentCost << " causes the same amount of profit with less rooms" << endl;
		cout << "To be maintained than a value of $" << rentCost - vacantIUnit << "." << endl;
		cout << endl;
		cout << "The number of rooms rented in order to maximize profit is: " << totUnits + 1 << endl;
		cout << "The Monthly rent is: $" << setprecision(2) << showpoint << fixed << rentCost << endl;
		cout << "The total profit is: $" << setprecision(2) << showpoint << fixed << oldProfit << endl;
	}
	else
	{
		cout << "The number of rooms rented in order to maximize profit is: " << totUnits + 1 << endl;
		cout << "The monthly rent is: $" << setprecision(2) << showpoint << fixed << rentCost - vacantIUnit << endl;
		cout << "The total profit is: $" << setprecision(2) << showpoint << fixed << profit << endl;
	}

	//Closing program statements
	wait(); //Halts the program until the user is ready to finish
	return 0;
}

//Function Definitions
void wait()
{
	//The following if-statement checks to see how many characters are in cin's buffer
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
