#include <iostream>
#include <string>

using namespace std;

int* pref(string); // префикс-функция

int main()
{
	string str, substr;
	cout << "Entry string: ";
	getline(cin, str);
	cout << "Entry sub-string, witch will try to found: ";
	getline(cin, substr);
	int found = -1;
	int* D = pref(substr);
	//
	//алгоритм
	//


	if (found != -1)
		cout << "FOUND! ;-D " << found << endl;
	else
		cout << "NOT FOUND! :-C" << endl;
	return 0;
}

// префикс-функция
int* pref(string substr)
{
	int* D = new int[substr.size()];
	D[0] = 0;
	int j = 0; int i = 1; 
	while (i < substr.size())
	{
		if (substr[j] == substr[i])
		{
			D[i] = j + 1;
			i++;
			j++;
		}
		else
			if (j == 0)
			{
				D[i] = 0;
				i++;
			}
			else
				j = D[j - 1];
	}
	return D;
}