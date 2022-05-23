// Лабораторная работа 6, задача 3. Выполнена:Сивый А.А.
/*Стандартных функций работы со строками не использовать.
Вариант 9. Ввести массив строк. В функции для каждой строки проверить, является она симметричной, или нет.
(Симметричной считается строка, которая одинаково читается слева направо и справа налево).
Вывести на экран саму строку и результат её обработки.*/
#include <iostream>

using namespace std;

bool check_polindrom(char* word)
{
	int len = 0;
	for (int i = 0; i < 80; i++)
	{
		if ((word[i] <= 'Z' && word[i] >= 'A') || (word[i] <= 'z' && word[i] >= 'a'))
			len++;
	}
	for (int i = 0; i < len / 2; ++i)
	{
		if (word[i] != word[len - i - 1])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	setlocale(LC_ALL, "ru");
	int N;
	cout << "Введите количество строк\n";
	while (!(cin >> N))
	{
		cout << "Введите корректное значение\n";
		cin.clear();
		cin.ignore(10000, '\n');
	};
	char** str = new char* [N];
	for (int i = 0; i < N; i++)
	{
		str[i] = new char[80];
	}
	for (int i = 0; i < N; i++)
	{
		cout << "Введите строку\n";
		cin.ignore( );
		cin.getline(str[i], 80);
		if (check_polindrom(str[i]))
			cout << "YES\n";
		else
			cout << "No\n";
	}
	return 0;
}