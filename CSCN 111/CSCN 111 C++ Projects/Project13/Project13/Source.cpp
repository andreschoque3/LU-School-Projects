#include <iostream>
#include <string>

using namespace std;

enum PlanetType{MERCURY, VENUS, EARTH, MOON, MARS, JUPITER, SATURN, URANUS, NEPTUNE, PLUTO};
bool ValidPlanet(string userInput, PlanetType& planet);
int main()
{
	string planetName;
	double weight;
	PlanetType planet;
	cout << "Enter your weight: ";
	cin >> weight;
	cout << "Enter planet name: ";
	cin >> planetName;
	while (!(ValidPlanet(planetName, PlanetType & planet));
	{
		cout << "Invalid planet";
		cout << "Enter a planet name: ";
		cin planetName;
	}
	return 0;
}
bool ValidPlanet(string userInput, PlanetType& planet)
{
	if (userInput == "Mercury" || userInput == "mercury" || userInput == "MERCURY")
		planet = MERCURY;
	else if (userInput )
}