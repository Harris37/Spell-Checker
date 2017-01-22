#include"Modify.h"

Modify::Modify()
{
	cout << "Creating Modify..." << endl;
}
void Modify::modify_dict(string str1)
{
	ofstream myfile;
	myfile.open("wordlist.txt", ios::app);
	myfile <<endl<< str1;
	myfile.close();

}
Modify::~Modify()
{
	cout << endl<<"Destroying Modify..." << endl;
}