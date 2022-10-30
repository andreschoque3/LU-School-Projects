// Andres Choque -- Lab 2B Grade Book

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student
{
public:
	Student(string studentName);
	void setName(string studentName);
	void setScores();
	void print();

private:
	string studentName;
	int scores[5];
	int numberOfScoresEntered = 0;
};

class GradeBook
{
public:
	GradeBook(string gradebookname);
	void addStudent(string studentName);
	int countTheStudents();
	void list();

private:
	vector <Student> students;
	string gradebookname;
	int numberOfStudents = 0;

};

//--------------------------------Definitions-------------------------------------
GradeBook::GradeBook(string inCommingGradeBookName)
{
	gradebookname = inCommingGradeBookName;
}

void GradeBook::addStudent(string studentName)
{
	cout << "We are adding a student now";
	Student studentInGradeBook(	studentName);
	students.push_back(studentInGradeBook);
	students[numberOfStudents].setScores();
    numberOfStudents++;
}

int GradeBook::countTheStudents()
{
	return numberOfStudents;
}

void GradeBook::list()
{
	system("CLS");
	cout << "These are the scores for the students.\n";
	for (int i = 0; i < numberOfStudents; i++)
		students[i].print();
}

Student::Student(string studentName)
{
	setName(studentName);
}

void Student::setName(string studentNameFromConstructor)
{
	studentName = studentNameFromConstructor;
}

void Student::setScores()
{
	system("CLS");
	int score = 0;
	do
	{
		cout << "Enter score: " << (numberOfScoresEntered + 1) << " (Enter -1 to Quit): ";
		cin >> score;
		if (score != -1)
			scores[numberOfScoresEntered++] = score;
		if (numberOfScoresEntered == 3)
			cout << "\nYou've entered the maximum number of scores.\n";
	} while ((score != -1) && (numberOfScoresEntered < 3));
	
}

void Student::print()
{
	system("CLS");
	cout << "Student: " << studentName << endl;
	for (int i = 0; i < numberOfScoresEntered; i++)
		cout << "Score: " << i + 1 << ": " << scores[i] << endl;
	getchar();
	getchar();

}

//----------------------------------Driver----------------------------------------
int main()
{
	string gradebookname;
	string studentname;
	char choice = ' ';
	const int MAX_STUDENTS = 3;
	int rosterCount = 0;
	cout << "\n\nGradebook system\n\n";
	cout << "\n\nEnter the name if the Gradebook: ";
	cin >> gradebookname;
	GradeBook MyGradebook(gradebookname);
	cout << "\n\nEnter Add (A) List (L) or Quit (Q): ";
	cin >> choice;
	choice = toupper(choice);
	while (choice != 'Q')
	{
		switch (choice)
		{
		case 'A':
			rosterCount = MyGradebook.countTheStudents();
			if (rosterCount < MAX_STUDENTS)
			{
				cout << "\nEnter the name of the student: ";
				cin >> studentname;
				MyGradebook.addStudent(studentname);
			}
			else
			{
				cout << "Maximum amount of Students Reached.\n\n";
			}
			break;
		case 'L':
			cout << "\nList of students in the Gradebook\n";
			MyGradebook.list(); 
			break;
		default:
			cout << "\nPlease enter A, L, or Q\n";
			break;
		}
		cout << "\n\nEnter Add (A) List (L) or Quit (Q): ";
		cin >> choice;
		choice = toupper(choice);
	}
	cout << "\nThanks for using MyGradebook \n";
	return 0;
}

