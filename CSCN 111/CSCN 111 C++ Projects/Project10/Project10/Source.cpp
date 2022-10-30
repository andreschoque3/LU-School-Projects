#include <iostream>
#include <ctime>
using namespace std;
int main()
{
	srand(time(0));
	cout << rand()%6 +1 << endl;

	cout << "this is the while loop" << endl;
	int x = 0;
	while (x < 5)
	{
		cout << x << endl;
		x++;
	}
	cout << "this is the for loop" << endl;
	int i;
	for (i = 10; i > 0; i=-2)
	{
		cout << i << endl;
	}
	cout << i << endl;
	return 0;
}