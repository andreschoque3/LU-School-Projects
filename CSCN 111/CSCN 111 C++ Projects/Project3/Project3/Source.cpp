#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
void wait();
int main()
{
	string name;
	int grade;
	// to read IN data from a file
	//ifstram fin; //inputFile, inFile
	//fin.open('Grade.txt')
	ifstream fin;
	fin.open("Grade.txt");
	int grade;
	int x = 9;
	int y = 2;
	int z = pow(x, y);
	cout << pow(x, y) << endl;

	char c;
	cout << "enter a character";
	c = cin.get();
	cout << c;
	cin.ignore(14,  '\n');
	cin.get(c);
	cout << c;

	cout << c << endl;



	//fin >> name >> grade
	fin >> name >> grade;
	cout << name << endl;
	cout << grade << endl;
	/*cout << boolalpha << fin.fail() << endl;*/
	fin.close();

	// to output data in a file
	ofstream fout;
	fout.open("out.txt");
	fout << name;
	fout.close();










	cout << setw(20) << setprecision(3) << showpoint << 23.0325 << endl;
	cout << setw(20) << setprecision(3) << showpoint << 1.54 << endl;


	return 0;
}
//Function Definition
void wait()
{
	//The following if-statement checks to see how many characters
	//If the buffer has characters in it, the clear all ignore
	if (cin.rdbuf()->in_avail() > 0) //if the buffer is empty
	{

	}
}