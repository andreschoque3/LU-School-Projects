// Choque Lab_1_Loan_Payment.cpp
// Source: https://stackoverflow.com/questions/5655142/how-to-check-if-input-is-numeric-in-c 

#include <iostream>
#include <string>
#include <time.h>
#include <iomanip>
#include <math.h>
#include <regex>

using namespace std;

int getPrincipal();
int getCreditScore();
int getTerm();
bool testTerm(int);
enum CreditRating { EXCELLENT, GOOD, FAIR, BAD };
CreditRating determineCreditRating(int);
double determineInterestRate(CreditRating);
double determineMonthlyPayment(int, double, int);


int main()
{
    cout << "Andres Choque Loan -- Amortization Program \n\n";
    int principal = getPrincipal();
    int creditScore = getCreditScore();
    CreditRating creditRating = determineCreditRating(creditScore);
    int term = getTerm();
    double interestRate = determineInterestRate(creditRating);
    cout << "Your interest rate is: " << interestRate << endl;
    cout << "Your monthly payment is: " << determineMonthlyPayment(principal, interestRate, term);
}

int getPrincipal()
{
        string str;
        cout << "Enter the Principal: ";
        cin >> str;
        regex regex_pattern("-?[0-9]+");
        if (!regex_match(str, regex_pattern) || stod(str) <= 0)
        {
            do
            {
                if (!regex_match(str, regex_pattern))
                    cout << "Enter a whole number\n";
                else if (stod(str) <= 0)
                {
                    cout << "Enter a positive number\n";
                }
                cout << "Enter the Principal: ";
                cin >> str;

            } while (!regex_match(str, regex_pattern) || stod(str) <= 0);
        }
        return stod(str);
 }

int getCreditScore()
{
    string str;
    regex regex_pattern("-?[0-9]+");
    cout << "Enter the Credit Score (between 300-850): ";
    cin >> str;
    if (!regex_match(str, regex_pattern) || stod(str) > 850 || stod(str) < 300)
    {
        do
        {
            if (!regex_match(str, regex_pattern))
                cout << "Enter a whole number\n";
            else if (stod(str) <= 300)
            {
                cout << "Credit Score too low. Try again\n";
                system("pause");
                exit(0);
            }
            else if (stod(str) > 850)
            {
                cout << "Credit score too high. Try again\n";
            }
            cout << "Enter the Credit Score (between 300-850): ";
            cin >> str;
        } while (!regex_match(str, regex_pattern) || stod(str) > 850 || stod(str) < 300);
    }
    return stod(str);
}

int getTerm()
{
    string str; 
    regex regex_pattern("-?[0-9]+"); 
    cout << "Enter the Term: "; 
    cin >> str; 
    if (!regex_match(str, regex_pattern) || !testTerm(stod(str)))
    { 
        do 
        { 
            if (!regex_match(str, regex_pattern))
                cout << "Enter a whole number.\n"; 
            else
                cout << "Enter 10, 15, or 30\n"; 
            cout << "Enter the term: "; 
            cin >> str; 
        } while (!regex_match(str, regex_pattern) || !testTerm(stod(str)));
    }
    return stod(str);
}

bool testTerm(int term)
{
    if (term == 10)
        return true;
    else if (term == 15)
        return true;
    else if (term == 30)
        return true;
    else
        return false;

}

CreditRating determineCreditRating(int creditScore)
{
    if (creditScore >= 720) return EXCELLENT;
    else
        if (creditScore >= 690) return GOOD;
        else
            if (creditScore >= 630) return FAIR;
            else
                return BAD;  
}

double determineInterestRate(CreditRating creditRating)
{
    srand(time(NULL));
    double interestRate = 0.0;
    switch (creditRating)
    {
    case EXCELLENT:
        interestRate = ((rand() % 1251) + 2750.0f) / 100000.0f;
        break;
    case GOOD:
        interestRate = ((rand() % 2491) + 4010.0f) / 100000.0f;
        break;
    case FAIR:
        interestRate = ((rand() % 2241) + 6510.0f) / 100000.0f;
        break;
    case BAD:
        interestRate = ((rand() % 1741) + 8760.0f) / 100000.0f;
        break;
    } 
    return interestRate;
}

double determineMonthlyPayment(int principal,  double rate, int term)
{
    double top = principal * rate / 12.0 * pow((1 + rate / 12.0), term * 12);
    double bottom = pow((1 + rate / 12.0), term * 12) - 1;
    double monthly = top / bottom;
    return monthly;


}
