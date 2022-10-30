#include <iostream>
#include <string>

using namespace std;

int main()
{
	string password;
	int numPrompts = 0;
	/*do 
	{
		cout << "Enter your password:  ";
		cin >> password;
		numPrompts++;

	} while (password != "password" && numPrompts <5);
	if (numPrompts == 5 && password != "password")
		cout << "You're locked out." << endl;
	else
		cout << "Welcome." << endl;*/

	/*cout << "Enter yor password:  ";
	cin >> password; //priming read
	while (password != "password")
	{
		cout << "Enter your password:  ";
		cin >> password;
	}*/

	//int a;
	//cout << "Enter in a value (integer);  ";
	/*cin >> a;
	while (cin.fail())
	{
		cout << "You did not enter a number" << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Enter in a value (integer):  ";
		cin >> a;
	}
	cout << "Finally" << endl;*/
	//running total
	int looper{ 0 };
	int number;
	int runningTotal{ 0 };

	while (looper < 10)
	{
		cout << "Enter a number:  ";
	    cin >> number;
		runningTotal += number;
		looper++;
	}
	cout << "Running total:  " << runningTotal << endl;
	cout << "Average :  " << double(runningTotal) / looper << endl;

	/*int x{ 7 };

	do
	{
		cout << x << endl;
		x++;

	} while (x < 5);

	/*while (x < 5)
	{
		cout << x << endl;
		//x++;
	}*/
	//cout << "Loop is done" << endl;

	return 0;
}