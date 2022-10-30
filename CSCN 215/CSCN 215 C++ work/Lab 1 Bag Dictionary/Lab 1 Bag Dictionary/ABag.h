#ifndef ABAG_H
#define	ABAG_H

#include "bagADT.h"

template <typename E>
class ABag : public Bag <E> { // here we are inheriting from the Bag class.
public: // From here we divide out functions into public and private classes.
	ABag() 
	{
		var = 0; // var is the variable I decided to use track the items in the bag, since its empty then its zero.
		maxsize = 10; // maxsize refers the the maximum size of the array, therefore it is 10.
		bagarray = new E[maxsize]; //We are creating a new array of size 10 with data type E sets it equal to the data type earlier.
	}

	ABag(int inputsize) //this constructor allows the user to determine the size of the bag.
	{
		var = 0;
		maxsize = inputsize;
		bagarray = new E[maxsize];

	}
	~ABag() // the destructor deletes the array after it was created. (call back from line 20)
	{
		delete[] bagarray;
	}

	// Insert a new item into the bag -- return false if fails and true if
	// successful
	bool addItem(const E& item) // Item is the new top of the bag. 
	{
		if(var >= maxsize) // Checks that the bag is full using maxsize.
		{
			return false;
		}
		else
		{
			bagarray[var] = item; // Something was placed in the bag and it sets it to the item.
			var++; // Increases the value of var.
			return true; 
		}
	}

	// Looks for 'item' in the bag and if found updates 'item' with the 
	// bag value and returns true.  Otherwise 'item' is left unchanged
	// and the method returns false.
	bool remove(E& item) 
	{
		int position = 0; // Here we initialize our position as the starting point. 
		bool remove = false; // initializes as the items as if there are no items.
		while (position < var && !remove) // functions compares the position and the does not remove.
		{
			if (bagarray[position] == item)
			{
				item = bagarray[position];
				remove = true; // Shows that there is an item present. 
				var--; // Decrease the value in the items. 
				for(int i = var; i > var; i--)
				{
					bagarray[i - 1] = bagarray[i]; // Updates to the bag value when there are items present.
				}
			} 
			position++; // Adds a value into the position function.
		}
		return remove; 
	}
	
	// Removes the top record from the bag, puts it in returnValue, and
	// returns true if the bag is not empty.  If the bag is empty the 
	// function returns false and returnValue remains unchanged.
	bool removeTop(E& returnValue)
	{
		if (var == 0) //checks that the bag is empty. 
		{
			return false; //outputs that the bag is empty
		}
		else //if there is something, then we remove one value from var. and we set return value as the array[var].
		{
			var--;
			returnValue = bagarray[var];
			return true; //therefore it is true since it is not empty.
		}
	}

	// Finds the record using returnValue and if the record is found updates
	// returnValue based on the contents of the bag and returns true.  If the
	// record is not found the function returns false.  Works just like remove()
	// except that the found record is not removed from the bag.
	bool find(E& returnValue) const 
	{
		int position = var -1; // This function tracks the var variable from the top and moves down. We have to subtract because var is starting from zero.
		bool found = false; // Set it as item not found
		while(position >= 0 && !found) // This function looks whether if the record is found and its a positive number.
		{
			if (bagarray[position] == returnValue) // Tracks the current position and compares it to the parameter return value.
			{
				returnValue = bagarray[position]; // It finds the record and updates return value to bagarray[position].
				found = true; // Set as the item as found.

			}
			position--; // Changes the position value or position -1.
		}
		return found; // Returns the found item.
	}

	// Inspect the top of the bag.  If the bag is empty return
	// false and leave 'item' unchanged; otherwise, return true and update 
	// 'item' with the contents of the bag.
	bool inspectTop(E& item) const
	{
		if(var == 0) // Inspect the top of the bag.
		{
			return false; // The bag is empty if it is false.
		}
		else
		{
			item = bagarray[var - 1]; // We are retrieving the top of the bag and setting it as the array.
			return true; // and since it is not empty it is true.
		}
	}

	// empties the bag
	void emptyBag()
	{
		var = 0; // Var tells the number of items in the bag and therefore if its 0 then it is empty.
	}

	// use the += operator to add an item to the bag
	bool operator+=(const E& addend) // Using an if statement to add an item when using the function append.
	{
		if(addItem(addend))
		{
			return true; // Adds it if it is true.
		}
		else
		{
			return false; // If it didn't work then we return false.
		}
	}

	// get the number of items in the bag
	int size() const
	{
		return var; // The function returns the number of items in the array. 
	}

	// get the capacity of the bag (size of your bag's array)
	int bagCapacity() const
	{
		return maxsize; // The function returns the size of the array. 
	}

private:
	int var; // Var is the variable that tracks the amount of items in the bag.
	int maxsize; // Maxsize is the max size of array.
	E* bagarray; // this is the pointer that specifies the array in the constructor.

};


#endif	ABAG_H