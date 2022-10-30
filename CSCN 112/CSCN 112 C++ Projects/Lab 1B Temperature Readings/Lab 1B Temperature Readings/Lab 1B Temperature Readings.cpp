// Andres Choque Lab 1B Temperature Readings.cpp 
// The temps.txt is called "Temps.txt"

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include "Header.h"

using namespace std;

int main()
{
    string infile;
    ifstream inputStream;
    string month;
    int year;
    int temp;
    bool isInputValid = true;
    
    int numberOfTemperatures = 0;

    cout << "Enter the name of your temperature file: ";
    getline(cin, infile);
    infile = "Temps.txt";
    inputStream.open(infile);
    if (!inputStream)
    {
        // The file cannot be opened
        cout << "\nFile could not be opened...\n";
    }
    else // Correct file name
    {
        inputStream >> month;
        inputStream >> year;
        MonthlyReadings clifford(month, year);
        inputStream >> temp;
        do
        {
            if (inputStream.eof() || inputStream.fail())
                isInputValid = false;
            else
            {
                //cout << temp << endl;
                clifford.addTemps(temp);
                numberOfTemperatures++;
                inputStream >> temp;
            }
        } while (isInputValid);
        if (inputStream.fail())
        {
            cout << "Non-numeric data was found in the input file\n";
            cout << "Program will end.\n";
            system("pause");
            exit(0);
        }
        else
        {
            //cout << temp << "\n";
            clifford.addTemps(temp);
            numberOfTemperatures++;
            inputStream.close();
        }
        cout << endl << numberOfTemperatures << " Temperatures were recorded for this month.\n\n";
        cout << "Statistics: \n";
        cout << "Average: " << clifford.average() << endl;
        cout << "Lowest: " << clifford.min() << endl;
        cout << "Highest: " << clifford.max() << endl;
        cout << "The temperatures for " << month <<" " << year << " are: " << endl;
        clifford.displayTemps();

    }
}

