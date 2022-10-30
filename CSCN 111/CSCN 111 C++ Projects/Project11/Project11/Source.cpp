#include <iostream>

using namespace std;
//void square(double );
//void squareTwoNumbers(int&, int&);

void abc()
int myGlobal = 7;

int main()
{
	/*int myGlobal = 5;

	cout << myGlobal << endl;
	abc();*/
}
/*three parts of a function:
 return data type
 name of function
 parameters
 */

/*double square(double n)
{
	return n * n;
}
*/


	

	system("pause");
	return 0;
}

void abc()
{
	static int x{ 1 };
	x++;
	cout << x << endl;
}
