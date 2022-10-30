/*
The cost to become a member of a fitness center is as follows:
	(a) the senior citizens discount is 30%;
	(b) if the membership is bought and paid for 12 or more months, the discount is 15%; and
	(c) if more than five personal training sessions are bought and paid for, the discount on each session is 20%.

Write a menu-driven program that determines the cost of a new membership. Your program must contain
	a function that displays the general information about the fitness center and its charges,
	a function to get all of the necessary information to determine the membership cost, and
	a function to determine the membership cost.

Use appropriate parameters to pass information in and out of a function. (Do not use any global variables.)

Malik, Ch 6, Programming Exercise 25 (page 463)

*/

//Include statements
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//Global declarations: Constants and type definitions only -- no variables
const float MONTHLY_MEMBERSHIP_RATE = 25.00;
const float PERSONAL_SESSION_RATE = 50.00;

const double SENIOR_CITIZEN_DISCOUNT = 0.30;
const double TWELVE_OR_MORE_MONTHS_MEMBERSHIP_DISCOUNT = 0.15;
const double FIVE_OR_MORE_PERSONAL_TRAINING_SESSIONS_DISCOUNT = 0.20;

void getInfo(int choice, bool& senirCitizen, bool& FiveOrMoreSess, bool& paidTwelveOrMoreMonths, int& PersonalTrainingSess);
double membershipCost(int PersonalTrainingSess, bool senirCitizen, bool sixOrMoreSess, bool paidTwelveOrMoreMonths);
void displayCenterInfo();
int displaymenu();


//Function prototypes
void wait();

int main()
{
	//In cout statement below substitute your name and lab number
	cout << "Andres Choque -- Lab 6" << endl << endl;

	//Variable declarations
	int input{ 0 };
	bool senirCitizen{ false };
	bool FiveOrMoreSess{ false };
	bool paidTwelveOrMoreMonths{ false };
	int PersonalTrainingSess{ 0 };
	double totalMembershipCost;

// double memberCost
	// int choice 
 

	//Program logic
	displayCenterInfo();
	while (input != 4)
	{
		input = displaymenu();
		getInfo(input, senirCitizen, FiveOrMoreSess, paidTwelveOrMoreMonths, PersonalTrainingSess);

	}
	totalMembershipCost = membershipCost(PersonalTrainingSess, senirCitizen, FiveOrMoreSess, paidTwelveOrMoreMonths);
	cout << "Your annual membership cost is: $" << setprecision(2) << fixed << totalMembershipCost << endl;


	//Closing program statements
	wait(); //Halts the program until the user is ready to finish
	return 0;
}
void getInfo(int choice, bool& senirCitizen, bool& FiveOrMoreSess, bool& paidTwelveOrMoreMonths, int& PersonalTrainingSess) 
{
	switch (choice) 
	{
	case 1:senirCitizen = true;
		break;
	case 2:paidTwelveOrMoreMonths = true;
		break;
	case 3: cout << "How many personal training sessions would you like? ";
		cin >> PersonalTrainingSess;
		if (PersonalTrainingSess >= 5)
			FiveOrMoreSess = true;
		break;
	case 4:
		break;

	}
}
double membershipCost(int PersonalTrainingSess, bool senirCitizen, bool sixOrMoreSess, bool paidTwelveOrMoreMonths)
{
	double TotCost;
	double monhtlyCost = MONTHLY_MEMBERSHIP_RATE;
	double annualCost = MONTHLY_MEMBERSHIP_RATE * 12;
	double discount; // discount variable for each instance
	double PersSessPrice;

	if (senirCitizen == true)
		discount = SENIOR_CITIZEN_DISCOUNT + 0.30;
	if (paidTwelveOrMoreMonths == true)
		discount = discount + 0.15;
	if (sixOrMoreSess == true)
		discount += 0.20;
	PersSessPrice = (PersonalTrainingSess * PERSONAL_SESSION_RATE) * (1 - FIVE_OR_MORE_PERSONAL_TRAINING_SESSIONS_DISCOUNT);
	TotCost = (discount) * (annualCost + PERSONAL_SESSION_RATE);

	return TotCost;
}
void displayCenterInfo() 
{
	cout << "***************************** SUPER FITNESS ******************************\n" << endl;
	cout << "Super Fitness is an old school fitness center dedicated to getting you" << endl;
	cout << "in the best possible shape in a way that is healthy and fun.  There" << endl;
	cout << "are no gimicks here. Just solid training.\n" << endl;
	cout << "Our monthy rates are $25.00, but we do offer the following discounts: " << endl;
	cout << "\ta) Senior Citizens (65 and older): \t\t\t\t30%" << endl;
	cout << "\tb) Prepaid Annual Membership: \t\t\t\t\t15%" << endl;
	cout << "\tc) Prepaid personal training sessions (5 or more) \t\t20%\n" << endl;
}
int displaymenu() 
{
	int userInput;
	cout << "Membership Options Menu: " << endl;
	cout << "\tEnter '1' if you are a Senior Citizen (30% discount) " << endl;
	cout << "\tEnter '2' if you are interesed prepaying for yout annual membership (15% discount)" << endl;
	cout << "\tEnter '3' if you are interested in Personal Training Sessions" << endl;
	cout << "\t   ($50.00 per session--5 or more sessions earns you a 20% reduction in Personal Training Rates" << endl;
	cout << "\tEnter '4' if you are done." << endl;
		cout << "Please enter the number of your option above: " << endl;
		cin >> userInput;
		return userInput;
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