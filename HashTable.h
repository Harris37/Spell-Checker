#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include<string>
#include<fstream>

using namespace std;
 

class HashTable
{
private:
protected:
	struct node
	{
		string key;
		node * next;
	};
	static const int tablesize = 20;
	node * hashptr[tablesize];
public:
	
	HashTable();
	~HashTable();
	node** get_ptr()
	{
		return hashptr;
	}
	int HashIndex(string); 
	void InsertNode(string);
	int NumOfNodesInIndex(int);
	void Print();
	int length(string);
};

#endif