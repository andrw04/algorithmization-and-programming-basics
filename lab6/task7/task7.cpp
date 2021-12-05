// Лабораторная работа 6, задача 7. Выполнена:Сивый А.А.
/*В заданной строке S найти максимальную по длине подстроку, которая
не является палиндромом.*/
#include <iostream>
#include <string>


using namespace std;


int max(string str)
{
	bool palindrom = true;
	for (int k = 0; k < size(str); k++)
	{
		for (int i = 0; i < size(str) / 2; i++)
		{
			if (size(str) >= i + 1 + k)
			{
				if (str[i] != str[size(str) - i - 1 - k])
				{
					palindrom = false;
					return size(str) - i - k;
				}
			}
		}
	}
	return -1;
}



int main()
{
	setlocale(LC_ALL, "ru");
	string str;
	cout << "Введите строку\n";
	while (!(cin >> str))
	{
		cout << "Введите корректное значение\n";
		cin.clear();
		cin.ignore(10000, '\n');
	}
	cout << endl << max(str) << endl;
	return 0;
}