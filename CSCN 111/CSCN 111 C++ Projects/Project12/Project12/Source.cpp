#include <iostream>
using namespace std;
const double MY_CONSTANT = 123.45;


void displayGeneralInfo();
int displayMenu();
void getInfo(int selection, bool &isMale, bool &isSophomore, int &age);

int main()
{
	bool isMale{ false };
	bool isSophomore{ false };
	int age{ 0 };

	int selection{ 0 };
	displayGeneralInfo();
	selection = displayMenu();
	while (selection != 4)
	{
		getInfo(selection, isMale, isSophomore, age);
		selection = displayMenu();
	}
	return 0;
}

void getInfo(int selection, bool &isMale, bool &isSophomore, int &age)
{
	switch (selection)
	{
	case 1:
			isMale = true;
			break;
	case 2:
		isSophomore = true;
		break;

	case 3:
		cout << "Enter your age: " << endl;
		cin >> age;

	}
	cout << "This is my general info." << endl;
	cout << "\t\tThis is my constant" << MY_CONSTANT << endl;
}
int displayMenu()
{
	int choice{ 0 };
	cout << "1 - Male" << endl;
	cout << "2 - You are a sophomore" << endl;
	cout << "3 - Enter Age" << endl;
	cout << "4- Quit" << endl;
	cout << "Selection:  " << endl;
	cin >> choice;
	return choice;
}