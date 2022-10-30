#include <iostream>
#include "CountSelfOrderedList.h"
#include "MoveToFrontSelfOrderedList.h"
#include "TransposeSelfOrderedList.h"
#include <fstream>

using namespace std;

int main() {

    // First test

    // Here the arrays are created for the char values
    char adds[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
    int addsLength = 8;

    char finds[] = { 'G', 'H', 'G', 'H', 'E', 'C', 'E', 'H', 'G', 'A', 'D', 'C', 'F'};
    int findsLength = 13;

    // Count heuristic
    std::cout << "Count Heuristic" << std::endl;

    // set the function that holds the list for Count
    CountSelfOrderedList<char>* clist = new CountSelfOrderedList<char>();
    for (int i = 0; i < addsLength; i++) {
        clist->add(adds[i]);
    }
    for (int i = 0; i < findsLength; i++) {
        clist->find(finds[i]);
    }
    // output formatting
    std::cout << "Number of Compares: " << clist->getCompares() << std::endl;
    std::cout << "List Size: " << clist->size() << std::endl;
    std::cout << "Final List Structure: " << std::endl;
    clist->printlist();

    std::cout << std::endl << std::endl;

    // Move-to-Front heuristic
    std::cout << "Move-To-Front Heuristic" << std::endl;

    // set the function that holds the list for Move-to-Front
    MoveToFrontSelfOrderedList<char>* mtflist = new MoveToFrontSelfOrderedList<char>();
    for (int i = 0; i < addsLength; i++) {
        mtflist->add(adds[i]);
    }
    for (int i = 0; i < findsLength; i++) {
        mtflist->find(finds[i]);
    }
    // output formatting 
    std::cout << "Number of Compares: " << mtflist->getCompares() << std::endl;
    std::cout << "List Size: " << mtflist->size() << std::endl;
    std::cout << "Final List Structure: " << std::endl;
    mtflist->printlist();

    std::cout << std::endl << std::endl;

    // Transpose heuristic
    std::cout << "Transpose Heuristic" << std::endl;

    // set the function that holds the list for Transpose
    TransposeSelfOrderedList<char>* tlist = new TransposeSelfOrderedList<char>();
    for (int i = 0; i < addsLength; i++) {
        tlist->add(adds[i]);
    }
    for (int i = 0; i < findsLength; i++) {
        tlist->find(finds[i]);
    }
    // output formatting
    std::cout << "Number of Compares: " << tlist->getCompares() << std::endl;
    std::cout << "List Size: " << tlist->size() << std::endl;
    std::cout << "Final List Structure: " << std::endl;
    tlist->printlist();

    std::cout << std::endl << std::endl;

    // Second test
    // creates similar functions that hold the lists but named differently
    CountSelfOrderedList<string>* cSlist = new CountSelfOrderedList<string>();
    MoveToFrontSelfOrderedList<string>* mtfSlist = new MoveToFrontSelfOrderedList<string>();
    TransposeSelfOrderedList<string>* tSlist = new TransposeSelfOrderedList<string>();
    
    // open the file and make sure when it opens it performs the following functions

    fstream filename;
    filename.open("test.txt");
    string HoldWord;
    if (filename.is_open())
    {
        while (filename)
        {
            filename >> HoldWord;
            cSlist->find(HoldWord);
            mtfSlist->find(HoldWord);
            tSlist->find(HoldWord);
        }
        // similar logic but uses different variables
        std::cout << "Count Heuristic" << std::endl;
        std::cout << "Number of Compares: " << cSlist->getCompares() << std::endl;
        std::cout << "List Size: " << cSlist->size() << std::endl;
        std::cout << "Final List Structure: " << std::endl;
        cSlist->printlist(10); //the output only is for 10 items

        std::cout << std::endl << std::endl;

        // similar logic but uses different variables
        std::cout << "Move-To-Front Heuristic" << std::endl;
        std::cout << "Number of Compares: " << mtfSlist->getCompares() << std::endl;
        std::cout << "List Size: " << mtfSlist->size() << std::endl;
        std::cout << "Final List Structure: " << std::endl;
        mtfSlist->printlist(10); //the output only is for 10 items

        std::cout << std::endl << std::endl;

        // similar logic but uses different variables
        std::cout << "Transpose Heuristic" << std::endl;
        std::cout << "Number of Compares: " << tSlist->getCompares() << std::endl;
        std::cout << "List Size: " << tSlist->size() << std::endl;
        std::cout << "Final List Structure: " << std::endl;
        tSlist->printlist(10); //the output only is for 10 items

        std::cout << std::endl << std::endl;
    }
    
    system("pause");
    return 0;
}