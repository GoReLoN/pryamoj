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
	for (int i = 0; i < str.size() - substr.size(); ++i)
	{
		for (int j = 0; j < substr.size(); ++j)
		{

		}
	}

	return 0;
}