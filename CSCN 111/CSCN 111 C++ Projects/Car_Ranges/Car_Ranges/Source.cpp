// car_range.cpp -- Write a program that prompts the capacity, in gallons, of an automobile fuel tank
//       and the miles per gallon the automobile can be driven. The program outputs the number of miles
//       the automobile can be driven without refueling.
//CSIS 111-<001>
//<Sources>


//Include statements
#include <iostream>
#include <string>

using namespace std;

//Global declarations: Constants and type definitions only -- no variables

//Function prototypes
void wait();

int main()
{
	cout << "<Andres Choque -- Lab <02>" << endl << endl;

	//Variable declarations
	int tankCapacity;
	int milesPerGallon;
	int range;

	// program logic
	 //		Prompt user for tank capacity and miles per gallon
	cout << "Gas tank capacity: ";
	cin >> tankCapacity;

	//		Calculate the car's range and assign it to the variable range
	cout << "Miles per gallon: ";  
	cin >> milesPerGallon;

	double numberOfmiles;

	numberOfmiles = (double)tankCapacity / (double)milesPerGallon;

	//		Ouput the cars range as well as what the user entered.
	cout << "Number of miles the vehicle can drive without refueling";
	cin >> numberOfmiles; 

	//Closing program statements
	wait();
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
		cin.ignore(numeric_limits<streamsize>::max(), '/n'); //clear the input buffer
	}
	char ch;
	cout << "Press the Enter key to continue ...";
	cin.get(ch);
}