// Лабораторная работа 7, задача 6. Выполнена: Сивый А.А.
/*Пусть S(x) - это сумма цифр числа x, записанного в десятичной системе счисления. Например, S(5) = 5,
S(10) = 1. S(322) = 7.
Мы будем называть число x интересным, если S(x+1) < S(x). В каждом тесте вам будет дано одно число n.
Ваша задача - посчитать количество чисел x таких, что 1 <= x <= n и x - интересное.*/
#include <iostream>

using namespace std;


int S(int x)
{
	if (x < 10)
		return x;
	else if (x >= 10)
		return x % 10 + S(x / 10);
}

int main()
{
	setlocale(LC_ALL, "ru");
	int n;
	int number = 0;
	cout << "Введете число n\n";
	while (!(cin >> n))
	{
		cout << "Введите корректное значение\n";
		cin.clear();
		cin.ignore(10000, '\n');
	}
	for (int x = 1; x <= n;)
	{
		if (S(x + 1) < S(x))
		{
			number++;
		}
		x++;
	}
	cout << number << "\n";
	return 0;
}