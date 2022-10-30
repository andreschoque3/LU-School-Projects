#include <string>
#include <iostream>
//#include "stdafx.h"

#include "BSTNode.h"
#include "BST.h"

int main()
{
	BST<int, string> one;
	one.insert(77, "seventy - seven");
	one.insert(70, "seventy");
	one.insert(75, "seventy-five");
	one.insert(66, "sixty-six");
	one.insert(79, "seventy-nine");
	one.insert(68, "sixty-eight");
	one.insert(67, "sixty-seven");
	one.insert(69, "sixty-nine");
	one.insert(90, "ninety");
	one.insert(85, "eighty-five");
	one.insert(83, "eighty-three");
	one.insert(87, "eighty-seven");
	one.insert(65, "sixty - five");

	cout << "Printing Tree . . . " << endl;
	one.print();
	cout << endl << endl;
	cout << "Printing Tree Values in Sequential Order . . . " << endl;
	one.printInOrder();
	cout << endl << endl;
	cout << "Printing Tree Values in Reverse Sequential Order . . . " << endl;
	one.printReverse();
	system("pause");
	return 0;
}