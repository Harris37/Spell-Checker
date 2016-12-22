#include "HashTable.h"


HashTable::HashTable()
{
	for (int i = 0; i < tablesize; i++)
	{
		hashptr[i] = new node;
		hashptr[i]->key = "empty";
		hashptr[i]->next = NULL;
	}
}
int HashTable::HashIndex(string nodekey)
{

	int index = 0;
	for (int i = 0; i < 26; i++)
	{
		if ((int)nodekey[0] == 97 + i)
		{
			index = i;
			break;
		}
	}
	return index;
}
void HashTable::InsertNode(string nodekey)
{
	int index = HashIndex(nodekey);
	if (hashptr[index]->key == "empty")
	{
		hashptr[index]->key = nodekey;
	}
	else
	{
		node*ptr = hashptr[index];
		node*temp = new node;
		temp->key = nodekey;
		temp->next = NULL;
		while (ptr->next != NULL)
		{
			ptr = ptr ->next;
		}
		ptr->next = temp;
	}
}

int HashTable::NumOfNodesInIndex(int index)
{
	int count = 0;
	if (hashptr[index]->key == "empty")
	{
		return count;
	}
	else
	{
		count++;
		node *ptr = hashptr[index];
		while (ptr->next != NULL)
		{
			count++;
			ptr = ptr->next;
		}
	}
	return count;
}
void HashTable::Print(){
	int node_number=0;
	for (int i = 0; i < tablesize; i++)
	{
		node_number = NumOfNodesInIndex(i);
		cout << endl <<"-----------------\n";
		cout << "index = " << i << endl;
		cout << "# of nodes = " << node_number << endl;
		node *ptr = hashptr[i];
		while (ptr!= NULL)
		{
			cout << ptr->key << "  ";
			ptr = ptr->next;
		}
		
	}
}