#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	// ����
	string str, substr;
	cout << "Entry string: ";
	getline(cin, str);
	cout << "Entry sub-string, witch will try to found: ";
	getline(cin, substr);
	int len = substr.length();

	vector<int> d(256, len);// ������� d, ������������� ������� ����(256), � ��� ��������� ������� �������� �����

	for (int i = len - 2; i >= 0; --i)//��������� ������ ������� �� ����� � ������� �����
		if (d[int(substr[i])] == len)
			d[int(substr[i])] = (len - 1) - i;

	int i = 0;
	int found = -1;

	while (i <= (str.length() - len))
	{
		for (int k = 0; k < i; ++k)//����� �������� ����� ��� �����������
			cout << " ";
		cout << substr << endl;

		int j = len - 1; // �������� � ����� �����
		bool flag = false; // ���������� = ���
		while (j > 0)
		{
			if (str[i + j] != substr[j])
			{
				i += d[(int)str[i + j]]; // ���������� �� �������������� �����
				flag = true;
				break;
			}
			j--; // ���� ����� �� �������� �����
		}
		if (j == 0 && str[i] == substr[j]) // ���� ����� �� ������� �������� �������
		{
			found = i;
			break;
		}
		if (!flag) // ���� �� ���� ����������
			i++; //���� � ���������
	}

	//����� ����������
	if (found != -1)
		cout << "FOUND! ;-D " << found << endl;
	else
		cout << "NOT FOUND! :-C" << endl;
	return 0;
}