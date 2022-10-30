#include <iostream>
using namespace std;

const double ROOM_DISCOUNT_LT_10 = 0.0;


int main()
{
	bool result;
	result = true;
	string gradeLevel = "Sopohmore";
	char gender = 'F';

	// ==, !=. <, >, <=, >= relational operators
	//logical operators &&, ||, !
	int x = 1;

	/*if (gradeLevel == "Sopohmore" || gender == 'F')
	{

		cout << "You get an A" << endl;
		cout << "yippie" << endl;
	}

	else
	{
		cout << "you don't" << endl;
		cout << "bummer" << endl;
	}*/

	int grade{ 0 };
	cout << "enter in a number grade: ";
	cin >> grade;
	char letterGrade;

	if (grade >= 90)
	{
		letterGrade = 'A';

	}
	else if (grade >= 80)
	{
		letterGrade = 'B';

	}
	else if (grade >= 70)
	{
		letterGrade = 'C';

	}
	else if (grade >= 60)
	{
		letterGrade = 'D';

	}
	else if (grade >= 50)
	{
		letterGrade = 'F';

	}

	switch (letterGrade)
	{
	case 'A':
		cout << "Excellent job" << endl;
		break;
	case 'B':
		cout << "Great job" << endl;
		break;
	case 'C':
		cout << "keep going" << endl;
		break;
	case 'D':
		cout << "Work harder" << endl;
		break;
	case 'F':
		cout << "failed change major" << endl;
		break;
	}
	cout << "Enter your gender (M or F):  ";
	cin >> gender;

	switch (gender)
	{
	case 'm':
	case 'M':
			cout << "you are a male" << endl;
			break;
	case 'f':
	case 'F':
		    cout << "you are a female" << endl;
		    break;
	default :
		cout << "wrong answer" << endl;
		break;

	}
	cout << "This is the end of my program" << endl;
	return 0;
}