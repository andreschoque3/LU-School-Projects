#include <iostream>
#include <string>
using namespace std;

int main()
{
	char a, b;
	a = 'A';
	b = 'a';
	//if (!(a < b))
		//cout << "a is less than b" << endl;
	//else
		//cout << "a is not less than b" << endl;

	//string s1 = "Hello there";
	//string s2 = "help";

	//cout << boolalpha << (s1 == s2) << endl;

	double x = 1.0;
	double y = 1.0/3 + double(1)/3 + double(1)/3;
	cout << boolalpha << (x == y) << endl;
	return 0;
}