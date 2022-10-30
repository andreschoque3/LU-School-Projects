#ifndef BDICTIONARYADT_H
#define BDICTIONARYADT_H

#include "dictionaryADT.h"
#include "ABag.h"
#include "kvpair.h"
#include <memory>

template <typename Key, typename E>
class BDictionary : public Dictionary <Key, E> { // Here we are inheriting from the Dictionary class
public: // Again we divide the classes into public and private. 
	BDictionary()
	{
		bag = std::make_unique<ABag<KVpair<Key, E>>>; // Implementing smart pointer calling it from private section.
	}
	BDictionary(int size)
	{
		bag = std::make_unique<ABag<KVpair<Key, E>>>(size); // Implementing smart pointer also calling it from private section.
	}
	~BDictionary()
	{
	// the delete function is no longer needed since smart pointer took care of it.
	}

	// Reinitialize dictionary
	void clear()
	{
		bag->emptyBag(); // It empties the bag and it starts clean.
	}

	// Insert a record
	// k: The key for the record being inserted.
	// e: The record being inserted.
	// Return true if insert is successful and false otherwise
	bool insert(const Key& k, const E& e)
	{
		if(bag->size() != bag->bagCapacity()) // Calls the functions to "size" and "bag capacity" and it checks when can we insert it
		{
			KVpair<Key, E> kvpair(k, e); 
			if(bag->addItem(kvpair)) // Calls the function "add item" to add a record.
			{
				return true; // updates the return to reflect that.
			}
		}
		return false; // Otherwise it does not add any record.
	}

	// Looks for a record using the key and if found does the following:
	// - updates the E& rtnVal
	// - removes the record from the dictionary
	// - returns true
	// If the record is not found the function returns false.
	bool remove(const Key& k, E& rtnVal)
	{
		if (bag->size() != 0) // Calls the function "size" and makes sure it does not equal to zero
		{
			KVpair<Key, E> kvpair(k, rtnVal); // Similar to the insert function above but instead it check when we can remove. 
			if (bag->remove(kvpair))
			{
				rtnVal = kvpair.value(); // Here we update the return value to the kvpair value and removes the item.
				return true; // The return is going to be true since we are removing an item.
			}
		} 
		return false; // If not, then it outputs false.  
	}

	// Takes an arbitrary record from the dictionary and does the following:
	// - updates the E& returnValue
	// - removes the record from the dictionary
	// - returns true
	// If the dictionary is empty the function returns false.
	bool removeAny(E& returnValue)
	{
		KVpair<Key, E> kvpair;
		if (bag->inspectTop(kvpair)) //We use bag 
		{
			bag->removeTop(kvpair); // We use bag to call the function "removetop" from ABag to perfrom work and to pass in kvpair 
			returnValue = kvpair.value(); // Update the return value in order to remove the record.
			return true; // Updates return so that it reflects that.
		}
		return false; // The dictionary is empty
	}

	// Looks for a record using the key and if found does the following:
	// - updates the E& returnValue
	// - returns true
	// If the record is not found the function returns false.
	bool find(const Key& k, E& returnValue) const
	{
		KVpair<Key, E> kvpair(k, returnValue); //giving parameters k, returnValue to kvpair.
		if(bag->size() !=0) // uses the "size" function to check that it is not zero.
		{
			if(bag->find(kvpair)) //uses "find" function  to update the values and kvpair.
			{
				returnValue = kvpair.value(); //upates the return value to the kvpair.
				return true; // Ouputs the value to reflect change.
			}
		}
		return false; // function is not found.
	}

	// Return the number of records in the dictionary.
	int size()
	{
		return bag->size(); //Using the "size" function in order to determine the number of records. 
	}

private:
	std::unique_ptr<ABag<KVpair<Key, E>>> bag; // This is where I decided to implement my smart pointer. 
	// creating a unique pointer object that also affects the constructor
	
};

#endif BDICTIONARY_H