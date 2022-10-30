#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class MonthlyReadings
{
public:
    MonthlyReadings(string, int);
    void addTemps(int);
    void setMonth(string);
    string getMonth();
    void setYear(int);
    int getYear();
    void displayTemps();
    float average();
    int min();
    int max();
private:
    vector<int> temps;
    int year;
    string month;
};
