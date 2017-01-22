#ifndef EDITDISTANCE_H
#define EDITDISTANCE_H
#include"Checker.h"
#include <iostream>
#include<string>
#include <vector>
using namespace std;

class EditDistance
{
private:

	
	int min(int, int, int);
public:
	EditDistance();
	~EditDistance();
	int No_of_operations(const string&, const string&);

};
#endif // !EDITDISTANCE_H
