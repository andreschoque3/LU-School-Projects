#include "SelfOrderedListADT.h"
#include "link.h"
#include <iostream>
#include "llist.h"

template <typename E>
class CountSelfOrderedList : public SelfOrderedListADT<E> {
private:
    LList<E> mainList;
    int compares;
    
public:
    CountSelfOrderedList() {
        compares = 0;
    }
    ~CountSelfOrderedList() {

    }

    //Look for 'it'.  If found return true and execute the self-ordering
    //heuristic used for ordering the list: count, move-to-front, or transpose.
    //Increments the compare instance variable every time it compares 'it' to
    //other members of the list. Returns true if 'it' is found.

    // find function that moves the it value to the start and check if it is found
    bool find(const E& it)
    {
        bool isFound = false;
        mainList.moveToStart();
        while (mainList.currPos() < mainList.length() && !isFound) {
            compares++;
            if (mainList.getValue() == it) {
                isFound = true;
                mainList.IcremFreqofCurr();
                this->reorder();
                break;
            }
            mainList.next();
        }
        if (!isFound) {
            add(it);
            this->reorder();
        }
        return isFound; 
    }

    //Called by find if 'it' is not in the list. Adds the new 'it' to the list
    //Can also be called independently when initially loading the list with
    //unique values and when you want to load the list in the order 'it' is 
    //read without your re-order method being called (or the number of compares
    //being incremented.

    // add function that appends 'it' and moves it to the position behind and sets the frequency
    void add(const E& it)  //Add new 'it' to the list
    {
        mainList.append(it);
        mainList.moveToPos(mainList.length() - 1);
        mainList.setfrequency(0);
    }

    // simple return statements for compares and length of mainlist
    int getCompares() const   //Returns the number of accumulated compares
    {
        return compares;
    }

    int size() const        //Returns the size of the list
    {
        return mainList.length();
    }

    //Print the list
    //In order print of the list.  printlist() prints the entire list
    //whereas printlist(n) prints n nodes.

    // first printlist that moves the item to the front and checks if the current position is less than length
    void printlist()
    {
        mainList.moveToStart();
        while (mainList.currPos() < mainList.length())
        {
            cout << mainList.getValue() << "-" << mainList.getfrequency() << " ";
            mainList.next(); 
        }
    }

    // second printlist that does all the same functions as above but passes the node into the functions
    void printlist(int n)
    {
        mainList.moveToStart();
        while (mainList.currPos() < n)
        {
            cout << mainList.getValue() << "-" << mainList.getfrequency() << " ";
            mainList.next();
        }
    }

    // reorder function for Count, it checks if the length is greater than 1, tempfrq is equal to zero, and if it
    // not the case then it moves it to start, sets the temporary values and found as false
    void reorder() {
        if (mainList.length() > 1)
        {
            int tempfrq = mainList.getfrequency(); //temporary values
            E tempval = mainList.remove(); 
            bool found = true;
            if (tempfrq == 0)
            {
                mainList.moveToEnd();
                mainList.insert(tempval);
                mainList.setfrequency(tempfrq);
            }
            else
            {
                mainList.moveToStart();
                while (found)
                {
                    if (tempfrq > mainList.getfrequency())
                    {
                        mainList.insert(tempval);
                        mainList.setfrequency(tempfrq);
                        found = false;
                    }
                    mainList.next();
                }
            }
        }
        

    }
};
