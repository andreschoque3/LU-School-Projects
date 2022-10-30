#pragma once

#include <string>

class StudentType
{
private:
	std::string studentFName;
	std::string studentLName;
	int testScore;
	char grade;


public:
	StudentType();
	StudentType(std::string f, std::string l);
	StudentType(std::string f, std::string l, char g, int s);
	~StudentType() {};

	void setFirstName(std::string n);
	void setLastName(std::string n);
	void setTestScore(int s);
	void setGrade(char g);
	std::string getFirstName();
	std::string getLastName();
	int getTestScore();
	char getGrade();

};
