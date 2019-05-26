#include <iostream>
#include <string>

using namespace std;

int main()
{
	// ввод строки и подстроки с клавиатуры
	string str, substr;
	cout << "Entry string: ";
	getline(cin, str); // str - строка
	cout << "Entry sub-string, witch will try to found: "; // Введите под-строку, которую будем пытатся найти
	getline(cin, substr); // substr - подстрока поиска

	//алгоритм
	int found = -1; //индекс найденого вхождения
	for (int i = 0; i < str.size() - substr.size(); ++i)
	{
		for (int j = 0; j < substr.size(); ++j)
		{
			if (str[i + j] != substr[j])
				break;
			else if (j == substr.size() - 1)
				found = i;
		}
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