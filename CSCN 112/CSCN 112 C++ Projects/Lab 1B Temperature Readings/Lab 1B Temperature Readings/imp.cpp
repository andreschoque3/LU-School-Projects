#include "Header.h"

using namespace std;

void MonthlyReadings::addTemps(int tempFromIntMain)
{
    temps.push_back(tempFromIntMain);
}

MonthlyReadings::MonthlyReadings(string tempMonth, int tempYear)
{
    setMonth(tempMonth);
    setYear(tempYear);
}

void MonthlyReadings::setMonth(string monthFromMain)
{
    month = monthFromMain;
}

string MonthlyReadings::getMonth()
{
    return month;
}

void MonthlyReadings::setYear(int yearFromMain)
{
    year = yearFromMain;
}

int MonthlyReadings::getYear()
{
    return year;
}

void MonthlyReadings::displayTemps()
{
    sort(temps.begin(), temps.end());
    for (int t : temps)
    {
        cout << t << endl;
    }
}

float MonthlyReadings::average()
{
    float runningTotal = 0.0;
    for (int t : temps)
    {
        runningTotal = runningTotal + t;
    }
    return (runningTotal / temps.size());
}

int MonthlyReadings::min()
{
    int runningMinimum = 999;
    for (int t : temps)
    {
        if (t < runningMinimum)
            runningMinimum = t;
    }
    return runningMinimum;
}

int MonthlyReadings::max()
{
    int runningMaximum = -999;
    for (int t : temps)
    {
        if (t > runningMaximum)
            runningMaximum = t;
    }
    return runningMaximum;
}