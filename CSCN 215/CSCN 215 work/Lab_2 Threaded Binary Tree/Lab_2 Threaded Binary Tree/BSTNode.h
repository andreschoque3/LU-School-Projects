// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// This is the file to include for access to the complete binary node
// template implementation

#include "book.h"
#include "BinNode.h"

#ifndef BSTNODE_H
#define BSTNODE_H

// Simple binary tree node implementation
template <typename Key, typename E>
class BSTNode : public BinNode<E> {
private:
	Key k;                  // The node's key
	E it;                   // The node's value
	BSTNode* lc;            // Pointer to left child
	BSTNode* rc;            // Pointer to right child
	bool leftIsThread : 1;
	bool rightIsThread : 1;

public:
	// Two constructors -- with and without initial values
	BSTNode() { lc = rc = NULL; }
	BSTNode(Key K, E e, BSTNode* l = NULL, BSTNode* r = NULL)
	{
		k = K; it = e; lc = l; rc = r; leftIsThread = true; rightIsThread = true;
	}
	~BSTNode() {}             // Destructor

	// Functions to set and return the value and key
	E& element() { return it; }
	void setElement(const E& e) { it = e; }
	Key& key() { return k; }
	void setKey(const Key& K) { k = K; }

	// Functions to set and return the children
	inline BSTNode* left() const { return lc; }
	void setLeft(BinNode<E>* b, string a)
	{
		lc = (BSTNode*)b;
		if (a == "thread")
			leftIsThread = true;
		else
			leftIsThread = false;
	}
	inline BSTNode* right() const { return rc; }
	void setRight(BinNode<E>* b, string a)
	{
		rc = (BSTNode*)b;
		if (a == "thread")
			rightIsThread = true;
		else
			rightIsThread = false;
	}

	// Get/Sets for thread polarity
	void setLeftIsThread(bool x) { leftIsThread = x; }
	void setRightIsThread(bool x) { rightIsThread = x; }
	bool getLeftIsThread() { return leftIsThread; }
	bool getRightIsThread() { return rightIsThread; }


	// Return true if it is a leaf, false otherwise
	bool isLeaf() { return (leftIsThread == true) && (rightIsThread == true); }
};

#endif
