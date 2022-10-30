#include "StudentType.h"
#include <string>
#include <iostream>


//Your class implementation functions go below
StudentType::StudentType()
{
	studentFName = (" ");
	studentLName = (" ");
	testScore =	100;
	grade = ' ';
	
}

StudentType::StudentType(std::string f, std::string l)
{
	studentFName = f;
	studentLName = l;
}

StudentType::StudentType(std::string f, std::string l, char g, int s)
{
	studentFName = f;
	studentLName = l;
	testScore = s;
	grade = g;
}

void StudentType::setFirstName(std::string n)
{
	studentFName = n;
}

void StudentType::setLastName(std::string n)
{
	studentLName = n;
}

void StudentType::setTestScore(int s)
{
	if (testScore <= 0 || testScore > 100)
	{
		std::cout << "Test scores must be between 0 and 100" << std::endl;
		testScore = 0;
	}
	else
		testScore = s;
}

void StudentType::setGrade(char g)
{
	if (g == 'A' || g == 'a' || g == 'B' || g == 'b' || g == 'C' || g == 'c' || g == 'D' || g == 'd' || g == 'F' || g == 'f')
		grade = g;
	else
	{
		std::cout << "Enter Grade using single character letter (A,B,C,D, or F)" << std::endl;
		grade = g;
	}
}

std::string StudentType::getFirstName()
{
	return studentFName;
}

std::string StudentType::getLastName()
{
	return studentLName;
}

int StudentType::getTestScore()
{
	return testScore;
}

char StudentType::getGrade()
{
	return grade;
}