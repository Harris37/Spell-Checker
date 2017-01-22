#include"EditDistance.h"

EditDistance::EditDistance()
{
	cout << "Creating EditDistance..." << endl;
}
int EditDistance::No_of_operations(const string& str1, const string& str2)
{

	int m = str1.length();
	int n = str2.length();
	int temp[15][15];
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{

			if (i == 0)
				temp[i] [j] = j;

			else if (j == 0)
				temp[i][ j] = i;

			else if (str1[i - 1] == str2[j - 1])
				temp[i][ j] = temp[i - 1][ j - 1];

			else
				temp[i][ j] = 1 + min(temp[i][ j - 1],
				temp[i - 1][ j],
				temp[i - 1][ j - 1]);
		}
	}

	return temp[m][ n];
	}

int EditDistance::min(int a, int b, int c)
{
	int minimum = a;
	if (minimum > b)
		minimum=b;
	if (minimum > c)
		minimum = c;

	return minimum;


}
EditDistance::~EditDistance()
{
	cout << endl <<"Destroying EditDistance..." << endl;
}