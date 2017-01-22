#include "Checker.h"
Checker::Checker()

{
	cout << "Creating Checker..." << endl;
	checkptr = NULL;
}
void Checker::spellcheck(string S1)
{
	tell = false;
	for (int i = 0; i < tablesize; i++)
	{
		node*hashptrcopy = hashptr[i];
		while (hashptrcopy != NULL)
		{
			if (S1 == hashptrcopy->key)
				tell = true;
			hashptrcopy = hashptrcopy->next;
		}

	}
	if (tell == false)
	{
		if (checkptr == NULL)
		{
			checkptr = new node;
			checkptr->key = S1;
			checkptr->next = NULL;
		}
		else
		{
			node*checkptrcopy = checkptr;
			node*temp = new node;
			temp->key = S1;
			temp->next = NULL;
			while (checkptrcopy->next != NULL)
			{
				checkptrcopy = checkptrcopy->next;
			}
			checkptrcopy->next = temp;
		}
	}



}
void Checker::Suggestions()
{

	node*checkptrcopy = checkptr;
	node*hashcopy = NULL;
	bool check = false;
	EditDistance E1;
	int count = 0;
	cout << endl << "Mispelled words:" << endl;
	while (checkptrcopy != NULL)
	{
		count++;
		check = false;
		cout <<  endl<< endl << count << "." << checkptrcopy->key << endl;
		cout << "Suggestions: ";
		int num = HashIndex(checkptrcopy->key);
		for (int i = (num-2); i <= (num+2); i++)
		{
			if (i>0 && i<20)
			{
				hashcopy = hashptr[i];
				while (hashcopy != NULL)
				{
					int number = E1.No_of_operations(checkptrcopy->key, hashcopy->key);
					if (number <= 2)
					{
						cout << hashcopy->key << "  ";
						check = true;
					}
					hashcopy = hashcopy->next;
				}
			}
		}

		if (check == false)
			cout << "No suggestions found" << endl; 

		checkptrcopy = checkptrcopy->next;
		
	}
}

Checker::~Checker()
{
	cout << endl<<"Destroying Checker..." << endl;
}