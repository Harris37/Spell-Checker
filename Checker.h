
#ifndef CHECKER_H
#define CHECKER_H

//
#include "HashTable.h"
#include "EditDistance.h"

class Checker : public HashTable
{
private:
	node * checkptr;
	
public:
	bool tell = false;
	Checker();
	~Checker();
	void spellcheck(string);
	void Suggestions();
};
#endif