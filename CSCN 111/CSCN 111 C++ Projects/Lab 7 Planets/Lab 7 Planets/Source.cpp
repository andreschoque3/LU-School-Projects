//<Lab 7 Planets> -- brief statement as to the file’s purpose
//CSIS 111-<001>
//<Sources if necessary>


//Include statements
#include <iostream>
#include <string>

using namespace std;

//Global declarations: Constants and type definitions only -- no variables

enum PlanetType{ MERCURY, VENUS, EARTH, MOON, MARS, JUPITER, SATURN, URANUS, NEPTUNE, PLUTO };

bool ValidPlanet(string userInput, PlanetType& planet); //The function determines if the input is valid if not, it clears the input

float CalculateWeight(PlanetType planet, float& weight); //This function calculates the weight using the switch function
//Function prototypes
void wait();

int main()
{
	//In cout statement below substitute your name and lab number
	cout << "Andres Choque -- Lab 7" << endl << endl;

	//Variable declarations
	float weight = 0;
	string PlanetName;
	PlanetType planet;
	bool validPlanet = false;
	float NewWeight;

	//Program logic
	cout << "Enter in your weight on Earth: (in lbs)" << endl;
	cin >> weight;
	cout << endl;
	
	do 
	{
		cout << "Enter a planet name: (Corectly)" << endl;
		cin >> PlanetName;
		cout << endl;

		cout << endl;
	} while (!ValidPlanet(PlanetName, planet));

	NewWeight = CalculateWeight(planet, weight);

	cout << "Your weight on the planet " << PlanetName << " is " << NewWeight << " lbs. " << endl;
	//Closing program statements
	wait(); //Halts the program until the user is ready to finish
	return 0;
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
bool ValidPlanet(string userInput, PlanetType& planet) //using the bool to determine whether the input is valid using the if and else if functions
{
	if (userInput == "MERCURY")
	{
		planet = MERCURY; 
		return 1;
	}
	else if (userInput == "VENUS")
	{
		planet = VENUS;
		return 1;
	}
	else if (userInput == "EARTH")
	{
		planet = EARTH;
		return 1;
	}
	else if (userInput == "MOON")
	{
		planet = MOON;
		return 1;
	}
	else if (userInput == "MARS")
	{
		planet = MARS;
		return 1;
	}
	else if (userInput == "JUPITER")
	{
		planet = JUPITER;
		return 1;
	}
	else if (userInput == "SATURN")
	{
		planet = SATURN;
		return 1;
	}
	else if (userInput == "URANUS")
	{
		planet = URANUS;
		return 1;
	}
	else if (userInput == "NEPTUNE")
	{
		planet = NEPTUNE;
		return 1;
	}
	else if (userInput == "PLUTO")
	{
		planet = PLUTO;
		return 1;
	}
	else
	{
		cout << "ENTER A NAME OF A VALID PLANET IN ALL CAPITAL LETTERS" << endl;
		return 0;
	}
}
float CalculateWeight(PlanetType planet, float& weight) //using the float to determine the weight using the switch function
{
	switch (planet)
	{
	case MERCURY:
		weight = weight * 0.4155;
		break;
	case VENUS:
		weight = weight * 0.8975;
		break;
	case EARTH:
		weight = weight;
		break;
	case MOON:
		weight = weight * 0.166;
		break;
	case MARS:
		weight = weight * 0.3507;
		break;
	case JUPITER:
		weight = weight * 2.5374;
		break;
	case SATURN:
		weight = weight * 1.0677;
		break;
	case URANUS:
		weight = weight * 0.8947;
		break;
	case NEPTUNE:
		weight = weight * 1.1794;
		break;
	case PLUTO:
		weight = weight * 0.0899;
		break;

	}

	return weight;
}