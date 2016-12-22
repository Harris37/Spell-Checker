#include"HashTable.h"

int main()
{
	string word = "empty";
	HashTable Hash1;
	ifstream myfile;
	myfile.open("wordlist.txt");
	if (myfile.is_open())
	{
		cout << "File opened" << endl;
		while (!myfile.eof())
		{
			myfile >> word;
			Hash1.InsertNode(word);
		}
		Hash1.Print();
	}
	else
	{
		cout << "File failed to open" << endl;
	}
	myfile.close();
}