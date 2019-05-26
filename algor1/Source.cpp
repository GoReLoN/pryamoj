#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str, substr;
	cout << "Entry string: ";
	getline(cin, str);
	cout << "Entry sub-string, witch will try to found: ";
	getline(cin, substr);
	int found = -1;
	for (int i = 0; i < str.size() - substr.size(); ++i)
	{
		for (int j = 0; j < substr.size(); ++j)
		{
			if (str[i + j] != substr[j])
				break;
			else if (j == substr.size() - 1)
				found = i;
		}
		if (found != -1)
			break;
	}
	if (found != -1)
		cout << "FOUND! ;-D " << found << endl;
	else
		cout << "NOT FOUND! :-C" << endl;
	return 0;
}