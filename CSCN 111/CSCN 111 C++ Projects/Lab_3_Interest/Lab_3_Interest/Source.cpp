/* Interest.cpp -- See assignment instructions below for the purpose of this assignment.

Interest on a credit card's unpaid balance is calculated using the average daily balance.
Suppose that netBalance is the balance shown in the bill, payment is the payment made,
d1 is the number of days in the billing cycle, and d2 is the number of days payment is 
made before billing cycle. Then, the average daily balance is:

	averageDailyBalance = (netBalance * d1 - payment * d2)/d1; 
	
If the interest rate per month is, say, 0.0512, then the interest on the unpaid balance is:

	interest = averageDailyBalance * 0.0512;
	
Write a program that accepts as input netBalance, payment, d1, d2, and interest rate per
month from the provided input file "input.dat". Place input.dat in the same directory as
your .cpp file when you create your Visual Studios project.

the program outputs the interest.

Format your output to two decimal places.

*/
//CSIS 111<001>

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

//Global Declarations: Constants and type defintions only -- no variables

//Function prototypes
void wait();

int main()
{
	cout << "<Andres Choque> -- Lab <03>" << endl << endl;
	//Variables
	double netBalance, payment, interestRatePerMonth, averageDailyBalance, interest;
	int d1, d2;
	ifstream in;

	//Open the input file using in.open()
	
		//Get input for netBalance, payment, d1, d2, and interest per month using "in"
		//variable. 

		//Calculate averageDailyBalance using the formula in the heading above

		//Calculate interest using the formula in the heading above

		//Output the interest formatted to two decimal places
		//		Formatting cout
		//		cout "The interest is $##.##" replacing ##.## with the actual interest calculated
		//setprecision() fixed showpoint 
	ifstream fin;
	in.open("input.dat");
	//cout << "Enter Net Balance:  ";
	cin >> netBalance;
	//cout << "Enter payment Made:  ";
	cin >> payment;
	//cout << "Enter the number of days in the billing cycle:  ";
	cin >> d1;
	//cout << "Enter the number of days payment is made before billing cycle:  ";
	cin >> d2;
	//cout << "Enter interest per month:  ";
	cin >> interestRatePerMonth;

	averageDailyBalance = (netBalance * d1 - payment * d2) / d1;
	interest = averageDailyBalance * interestRatePerMonth;

	cout << endl << "Interest is $ " << interest << endl;
	cout << setprecision(2) << fixed << showpoint;

	//Close the program 
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
		cin.ignore(numeric_limits<streamsize>::max(), 'n\n'); //Clear the input buffer
	}
	char ch;
	cout << "Press the Enter key to continue ... ";
	cin.get(ch);
}
