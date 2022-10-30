#include <iostream>
#include <string>
using namespace std;

struct Student
{
	string name;
	int age;
	double gpa;
};

int main()
{
	Student s;
	
	cout << "Enter a student's name";
	cin >> s.name;
	cout << "Enter a student's age";
	cin >> s.age;
	cout << "Enter a student's gpa";
	cin >> s.gpa;

	cout << s.name << '\t' << s.age << '\t' << s.gpa << endl;

	

	

	system("pause");
	return 0;
}
