#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	// ввод
	string str, substr;
	cout << "Entry string: ";
	getline(cin, str);
	cout << "Entry sub-string, witch will try to found: ";
	getline(cin, substr);
	int len = substr.length();

	vector<int> d(256, len);// таблица d, используяется таблица аски(256), и все заполняем длинное искомого слова

	for (int i = len - 2; i >= 0; --i)//насколько символ отдален от конца в искомом слове
		if (d[int(substr[i])] == len)
			d[int(substr[i])] = (len - 1) - i;

	int i = 0;
	int found = -1;

	while (i <= (str.length() - len))
	{
		for (int k = 0; k < i; ++k)//вывод искомого слова для наглядности
			cout << " ";
		cout << substr << endl;

		int j = len - 1; // начинаем с конца слова
		bool flag = false; // совпадения = нет
		while (j > 0)
		{
			if (str[i + j] != substr[j])
			{
				i += d[(int)str[i + j]]; // сдвигаемся на соответсвующий сдвиг
				flag = true;
				break;
			}
			j--; // идем влево по искомому слову
		}
		if (j == 0 && str[i] == substr[j]) // если дошли до первого искомого символа
		{
			found = i;
			break;
		}
		if (!flag) // если не было совпадений
			i++; //идем к следущему
	}

	//вывод результата
	if (found != -1)
		cout << "FOUND! ;-D " << found << endl;
	else
		cout << "NOT FOUND! :-C" << endl;
	return 0;
}