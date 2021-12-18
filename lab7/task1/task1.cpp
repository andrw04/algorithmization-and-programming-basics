// Лабораторная работа 7, задача 1. Выполнена:Сивый А.А.
/*Необходимо разработать программу для перевода чисел из
одной системы счисления в другую. Выполнить два варианта решения
задачи: без использования массивов и с помощью массивов.
Вариант 9) Из девятичной в одиннадцатеричную*/
#include <iostream>

using namespace std;

void Recursion(int Sum) // из десятичной в 11-ричную
{
	if (Sum > 11)
		Recursion(Sum/ 11);
	if (Sum % 11 == 10)
		cout << "A";
	if (Sum % 11 < 11 && Sum % 11 != 10)
		cout << Sum % 11;
}
void Array(int Sum)
{
	int k = Sum;
	int rank = 1;
	do
	{
		k = k / 10;
		rank++;
	} while (k >= 10);
	char* arr = new char[rank];
	for (int i = rank - 1; i >= 0; i--) // перевод в одиннадцатеричную
	{
		k = Sum % 11;
		if (k == 10)
			arr[i] = 'A';
		else
			arr[i] = k+48;
		Sum = Sum / 11;
	}
	for (int i = 0; i < rank; i++)
	{
		cout << arr[i];
	}
	delete[] arr;
}

int main()
{
	setlocale(LC_ALL, "ru");
	int N;
	cin >> N;
	int k = N;
	int rank = 1;
	int Sum = 0;
	do
	{
		k = k / 10;
		rank++;
	} while (k >= 10);
	for (int i = 0; i < rank; i++) // перевод в десятичную
	{
		k = (int)(N / pow(10, rank - i - 1));
		k = (int)(k % 10);
		if (k == 9)
		{
			cout << "Цифры 9 нет в девятичной системе счисления\n";
			return 1;
		}
		Sum += (int)(k * pow(9, rank - i - 1));
	}
	Recursion(Sum);
	cout << endl;
	Array(Sum);

	return 0;
}