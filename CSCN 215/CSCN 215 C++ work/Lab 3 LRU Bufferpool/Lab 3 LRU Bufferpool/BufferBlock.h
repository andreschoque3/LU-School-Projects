#include "BufferBlockADT.h"
#include "constants.h"

#ifndef BUFFERBLOCK_H
#define	BUFFERBLOCK_H

class BufferBlock : public BufferblockADT 
{
private:
	int blockID;
	char* block;
public:
	//using the BufferblockADT.h header file we instantiate the variables and call functions from constants.h
	BufferBlock(char* data, int snz = 4096) { initializeCharArray(snz, block); }
	BufferBlock() {}
	~BufferBlock() {}

    //reads the block function from pos to pos + sz (end of block)
	void getData(int pos, int sz, char* data) {
		int end;
		if (pos + sz > getBlocksize()) {
			end = getBlocksize() - 1;
		}
		else {
			end = pos + sz;
		}
		for (int i = 0; i + pos < end; i++) {
			data[i] = block[i + pos];
		}
	}

	// Set ID function
    void setID(int id) {
		blockID = id;
	}
	// Get ID function
	int getID() const {
		return blockID;
	}
	// Get block function. This logic looks for the blocksize using the '\0' variable
	int getBlocksize() const {
		int i = 0;
		while (block[i] != '\0')
		{
			i++;
		}
		return i;
	}

    // get and return the block
	char* getBlock() const {
		return block;
	}
	// Set block function
	void setBlock(char* blk) {
		block = blk;
	}

};

#endif	/* BUFFERBLOCK_H */
