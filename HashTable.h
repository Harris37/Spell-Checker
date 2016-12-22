#ifndef SPELLCHECKER_HASH_H
#define SPELLCHECKER_HASH_H

#include <iostream>
#include<string>
#include<fstream>

using namespace std;
 

struct node
{
	string key;
	node * next;
};
class HashTable
{
private:
	
	static const int tablesize = 26;
	node * hashptr[tablesize];
public:
	HashTable();
	int HashIndex(string); 
	void InsertNode(string);
	int NumOfNodesInIndex(int);
	void Print();
};

#endif