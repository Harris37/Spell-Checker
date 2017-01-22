#include"HashTable.h"
#include"Checker.h"
#include"EditDistance.h"
#include"Modify.h"

int main()

{
	char ans = 's';
	string word = "empty";
	string new_word = "empty";
	string docu_name = "name";
	Checker C1;
	ifstream myfile;
	ifstream outfile;
	myfile.open("wordlist.txt");
	if (myfile.is_open())
	{
		cout << "File opened" << endl;
		cout << "Wait for the dictionary to load....." << endl;
		while (!myfile.eof())
		{
			myfile >> word;
			C1.InsertNode(word);
		}
	}
	else
	{
		cout << "File failed to open" << endl;
	}
	cout << "Enter the name of the text document for spell checking (Please write .txt at the end of the file name )"<< endl;
	cout << "For example: Document.txt" << endl;
	getline (cin,docu_name);
	outfile.open(docu_name.c_str());
	if (outfile.is_open())
	{
		cout << endl << "File opened" << endl;
		while (outfile>>word)
		{
			outfile >> word;
			C1.spellcheck(word);
		}
		if (C1.tell == false)
			C1.Suggestions();
		else
			cout << "No misspelled words found" << endl;
	}
	else
	{
		cout << "File failed to open" << endl;
	}

		cout << "Do you want to modify dictionary?(y for yes and n for no)" << endl;
		cin >> ans;
		while (ans != 'y'&& ans != 'n')
		{
			cout << "Please enter correct keyword" << endl;
			cin >> ans;

		}
	while (ans == 'y')
	{
		cout << "Enter the word that you want to add" << endl;
		cin >> new_word;
		Modify M1;
		M1.modify_dict(new_word);
		cout << "Do you want to modify the dictionary more?(y for yes and n for no)" << endl;
		cin >> ans;
		while (ans != 'y'&& ans != 'n')
		{
			cout << "Please Enter correct keyword" << endl;
			cin >> ans;

		}

	}

	cout << "Thank you for using this spell checker" << endl;
	myfile.close();
	outfile.close();
	cout << endl;
	return 0;

}