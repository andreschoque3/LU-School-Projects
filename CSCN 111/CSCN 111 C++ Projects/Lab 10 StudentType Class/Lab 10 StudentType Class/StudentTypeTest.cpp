//StudentTypeTest.cpp -- driver used to test StudentType implementation.
//CSIS 111-<001>
//<"How to Create a Class.docx", "time.h, time.cpp, timeTest.cpp>


//Include statements
#include <iostream>
#include <string>
#include "StudentType.h"

using namespace std;

//Global declarations: Constants and type definitions only -- no variables

//Function prototypes
void wait();

//void studentType(StudentType& st2);

int main()
{
	//In cout statement below substitute your name and lab number
	cout << "Andres Choque -- Lab 10" << endl << endl;

	//Variable declarations
	StudentType st;
	st.setFirstName("Andres");
	st.setLastName("Choque");
	st.setTestScore(100);
	st.setGrade('A');
	cout << endl << endl;
	cout << st.getFirstName() << " " << st.getLastName() << endl << "Test Score: " << st.getTestScore() << endl << "Grade: " << st.getGrade() << endl << endl;
	
	//Program logic -- set your StudentType instance variables using your set functions
	// then display your student data using you StudentType get functions.

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