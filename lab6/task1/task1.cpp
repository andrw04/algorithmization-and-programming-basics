// Лабораторная работа 6, задача 1. Выполнена:Сивый А.А.
/*Рассмотреть строки как одномерный массив символов.
Вариант 9. Дана строка символов, состоящих из цифр, разделенных пробелами.Вывести на экран числа в порядке возрастания их значений.*/
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	char str[256];
	int count = 0;
	cout << "Введите строку\n";
	cin.getline(str,  256 , '\n');
	char temp;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
			count++;
	}
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			for (int j = i; j < strlen(str); j++)
			{
				if (str[j] >= '0' && str[j] <= '9')
				{
					if (str[j] < str[i])
					{
						temp = str[i];
						str[i] = str[j];
						str[j] = temp;
					}
				}
			}
		}
	}
	cout << "Числа в порядке возрастания их значений:\n";
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
			cout << str[i] << '\t';
	}
	return 0;
}