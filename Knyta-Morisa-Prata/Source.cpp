#include <iostream>
#include <string>

using namespace std;

void pref(string, int*&); // префикс-функция

int main()
{
	// ввод
	string str, substr;
	cout << "Entry string: ";
	getline(cin, str);
	cout << "Entry sub-string, witch will try to found: ";
	getline(cin, substr);
	
	//алгоритм
	int found = -1; //индекс найденого вхождения
	int* D = nullptr;
	pref(substr, D); // массив D полученный префиксфункцией
	
	int i = 0; int j = 0;
	while (i < str.size())
	{
		if (str[i] == substr[j])
		{
			i++;
			j++;
			if (j == substr.size())
				found = i - substr.size();
		}
		else
			if (j == 0)
				i++;
			else
				j = D[j - 1];
		// если нашли подстроку - выходим из цикла
		if (found != -1)
			break;
	}

	//вывод результата
	if (found != -1)
		cout << "FOUND! ;-D " << found << endl;
	else
		cout << "NOT FOUND! :-C" << endl;
	return 0;
}

// префикс-функция
void pref(string substr, int*& D)
{
	delete D; // высвобождаем память если она была занята
	D = new int[substr.size()];
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
}