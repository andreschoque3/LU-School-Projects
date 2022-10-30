/*
	Imagine we are using a two-dimensional array as the basis for creating the game battle- ship. In the game of battleship a ‘~’ character entry in the array represents ocean (i.e., not a ship), a ‘#’ character represents a place in the ocean where part of a ship is present, and a ‘H’ character represents a place in the ocean where part of a ship is present and has been hit by a torpedo. Thus, a ship with all ‘H’ characters means the ship has been sunk. Declare a two-dimensional char array that is 25 by 25 that represents the entire ocean and an If statement that prints “HIT” if a torpedo hits a ship given the coordinates X and Y. Write a C++ program that will read in a file representing a game board with 25 lines where each line has 25 characters corresponding to the description above.

	You should write a function called Fire that will take an X and Y coordinate and print “HIT” if a ship is hit and “MISS” if a ship is missed. If a ship is HIT you should update the array with an ‘H’ character to indicate the ship was hit. If a ship is hit that has already been hit at that location you should print “HIT AGAIN”. You should write a second function called FleetSunk that will determine if all the ships have been sunk. Your C++ program must then call these functions until all the ships have been sunk at which point the program should display “The fleet was destroyed!”.

	Your game loop logic (the main logic of a game) should like like the following:

	do {
		Fire(x, y, gameBoard);
	} while(!FleetSunk(gameBoard));
*/

//Include statements
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Global declarations: Constants and type definitions only -- no variables

char Fire(int x, int y, char GameBoard[25][25]);
bool FleetSunk(const char GameBoard[25][25], int& shipsRemaining);

//Function prototypes
void wait();

int main()
{
	//In cout statement below substitute your name and lab number
	cout << "Andres Choque -- Lab 8" << endl << endl;

	//Variable declarations
	const int NumRows = 25;
	const int NumCols = 25;
	char GameBoard[NumRows][NumCols];
	ifstream inputfile;
	inputfile.open("Board.txt");
	if (!inputfile)
	{
		cout << "Unable to read file. " << endl;
	}
	else
	{
		cout << "Game file is loaded." << endl;
		const int NumRows = 25;
		const int NumCols = 25;
		char GameBoard[NumRows][NumCols];
		
		for (int row = 0; row < NumRows; ++row)
			for (int col = 0; col < NumCols; ++col)
				inputfile.get(GameBoard[row][col]);
		inputfile.close();;

	}
	//Program logic

	/*for (int row = 0; row < NumRows; ++row)
	{
		for (int col = 0; col < NumCols; ++col) 
		{
			cout << GameBoard[row][col];
		}
		cout << endl;
	}
	cout << endl << endl;*/
	// I commented this out because the gameboard was not displying on the command prompt

	/*inputfile.open("Board.txt"); // this was the only way I found to display the gameboard

	for (int row = 0; row < NumRows; ++row)
		for (int col = 0; col < NumCols; ++col)
			inputfile >> GameBoard[row][col];
	inputfile.close();;*/

	bool end = false;
	int ShipsRemaining = 0;

	for (int row = 0; row < NumRows; ++row)
	{
		for (int col = 0; col < NumCols; ++col)
		{
			if (GameBoard[row][col] == '#')
			{
				cout << '~';
				ShipsRemaining = ShipsRemaining + 1;
			}
			else
				cout << GameBoard[row][col];
		}
		cout << endl;
	}
	cout << "Ships remaining is: " << ShipsRemaining << endl;

	do
	{
		ShipsRemaining = 0;
		int x;
		int y;
		int rx = 0;
		int ry = 0;

		cout << "Enter X and Y coordinates (1-25) separated by a space. " << endl;
		cin >> rx;
		x = rx - 1;
		cin >> ry;
		y = ry - 1;

		system("cls");

		GameBoard[x][y] = Fire(x, y, GameBoard);
		for (int row = 0; row < NumRows; ++row)
		{
			for (int col = 0; col < NumCols; ++col)
			{
				if (GameBoard[row][col] == '#')
				{
					cout << '~';
					ShipsRemaining = ShipsRemaining + 1;
				}
				else
					cout << GameBoard[row][col];
			}
			cout << endl;
		}
	} while (!FleetSunk(GameBoard, ShipsRemaining));

	//Closing program statements
	wait(); //Halts the program until the user is ready to finish
	return 0;
}

char Fire(int x, int y, char GameBoard[25][25])
{
	int ShipsRemaining = 0;
	char Fire = '~';
	const int NumRows = 25;
	const int NumCols = 25;

	if (GameBoard[x][y] == '#')
	{
		cout << "HIT" << endl;
		Fire = 'H';
	}
	else if (GameBoard[x][y] == 'H')
	{
		cout << "HIT AGAIN" << endl;
		Fire = 'H';
	}
	else if (GameBoard[x][y] == 'M')
	{
		cout << "MISS AGAIN" << endl;
		Fire = 'M';
	}
	else
	{
		cout << "MISS" << endl;
		Fire = 'M';
	}
	return Fire; // I could not find another way

}

bool FleetSunk(const char Gameboard[25][25], int& ShipsRemaining)
{
	bool end;
	const int NumRows = 25;
	const int NumCols = 25;

	for (int row = 0; row < NumRows; ++row)
	{
		for (int col = 0; col < NumCols; ++col)
		{
			if (Gameboard[row][col] == '#')
			{
				ShipsRemaining = ShipsRemaining + 1;
			}
			else;

		}
	}
	if (ShipsRemaining == 0)
	{
		end = true;
		cout << "The Fleet was destroyed!" << endl;
	}
	else
		end = false;

	return end;
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