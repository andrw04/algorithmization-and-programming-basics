// Лабораторная работа 4, задача 3. Выполнена: Сивый А.А.
/*Память для массива выделять динамически. Выполнить в соотвествии с номером варианта индивидуальное задание и вывести на экран исходные
данные и полученный результат.
Вариант 9:Определить, является ли задананя матрица N-го порядка магическим квадратом, т.е. такой, в которой сумма элементов во всех строках
и столбцах одинакова*/
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	double sum=0,rows = 0, colums = 0, temp = 0;
	cout << "Введите порядок матрицы\n";
	while (!(cin >> n) || n < 0 || n != round(n))
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Введите корректное значение\n";
	}
	double** arr = new double* [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new double[n];
	}
	cout << endl << "Введите " << n*n << " элементов матрицы\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			while (!(cin >> arr[i][j]))
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Введите корректное значение\n";
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		sum += *arr[i];
	}
	for (int i = 0; i < n; i++) 
	{
		rows = 0;
		colums = 0;
		for (int j = 0; j < n; j++)
		{
			rows += arr[i][j];
			colums += arr[j][i];
		}
		if (sum != rows || sum != colums)
		{
			temp += 1;
		}
		else
			continue;
	}
	if (temp == 0)
		cout << "Магический квадрат\n";
	else
		cout << "Не магический квадрат\n";
	for (int i = 0; i < n; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	return 0;
}
