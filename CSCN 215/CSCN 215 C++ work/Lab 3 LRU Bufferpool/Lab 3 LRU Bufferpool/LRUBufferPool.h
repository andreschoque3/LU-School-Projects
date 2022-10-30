#include "BufferPoolADT.h"
#include "BufferBlock.h"
#include "constants.h"
#include <iostream>
#include <fstream>

class LRUBufferPool : public BufferPoolADT
{
private:
	std::fstream file;
	BufferBlock pool[5];
public:
	// Again using the functions of BufferPoolADT we instantiate the new functions and use constants.h to call functions
	LRUBufferPool() {}
	LRUBufferPool(string filename, int poolSize = 5, int blockSize = 4096)
	{
		file.open(filename.c_str(), fstream::in | fstream::binary); // Here I use the file.open function to open the .txt file and read from it
		for (int i = 0; i < poolSize; i++)
		{
			pool[i].setID(i);
			char* data = new char[blockSize];
			file.read(data, blockSize);
			pool[i].setBlock(data);
		}
	}

	~LRUBufferPool() { // to make the code more efficient I close the file in the destructor and use the delete funcition
		file.close();
		delete[] pool;
	}

	void getBytes(char* space, int sz, int pos) {
		int id = pos / BLOCKSIZE;
		int newpos = pos % BLOCKSIZE;
		BufferBlock* block;
		// find block
		int index = -1;
		for (int i = 0; i < POOL_SIZE; i++) {
			if (pool[i].getID() == id) {
				index = i;
			}
		}
		// Here we are moving the block into the zero position
		if (index >= 0) {
			BufferBlock temp = pool[index];
			for (int i = index; i > 0; i--)
			{
				pool[i] = pool[i - 1];

			}
			pool[0] = temp;
		}
		else {
			char* data = new char[BLOCKSIZE]; //reading the file
			file.seekg(id * BLOCKSIZE); //uses seekg to reorder the pool by multiplying it to the block size
			file.read(data, BLOCKSIZE); //uses read to read in the data and block size
			pool[4].setID(id); //set the id of the fourth element
			pool[4].setBlock(data); //set the block as the data in fourth element
			BufferBlock temp = pool[4];
			for (int i = 4; i > 0; i--) {
				pool[i] = pool[i - 1];
			}
			pool[0] = temp;
		}
		pool[0].getData(newpos, sz, space); // only if the block does not appear in the pool
	}

		void printBufferBlockOrder() { //shows and prints the blocks in order using the main function as well
			cout << "My buffer block order from most recently used to LRU is: ";
			for (int i = 0; i < POOL_SIZE; i++)
			{
				cout << pool[i].getID() << ", ";

			}
			cout << endl;
		}

		int getLRUBlockID() { //reads in the id of the foruth block
			return pool[4].getID();
		}

	
};
