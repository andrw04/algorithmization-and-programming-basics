// Лабораторная работа 5, задача 3.3. Выполнена:Сивый А.А.
/*Дан двумерный динамический массив целых чисел. Значения элементов данного
массива ввести с клавиатуры. Создать динамический массив из элементов,
расположенных в четных столбцах данного массива и имеющих нечетное значение.
Вычислить среднее арифметическое элементов динамического массива.
Вывести результат на экран.
Использовать функции.*/

#include <iostream>

using namespace std;

void InputArr(int** arr, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "A[" << i << "][" << j << "]: ";
			while (!(cin >> arr[i][j]))
			{
				cout << "Введите корректное значение\n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
		}
	}
}


int main()
{
	setlocale(LC_ALL, "ru");
	int n, m;
	cout << "Введите размеры массива n и m\n";
	while (!(cin >> n >> m) || n < 2)
	{
		cout << "Введите корректные значения\n";
		cin.clear();
		cin.ignore(10000, '\n');
	}
	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	InputArr(arr, n, m);
	int number = 0;
	for (int i = 1; i < n; i = i + 2)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] % 2 == 1)
			{
				++number;
			}
		}
	}
	int k = 0;
	int* arr1 = new int[number];
	for (int i = 1; i < n; i = i + 2)
	{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] % 2 == 1 && k < number)
				{
					arr1[k] = arr[i][j];
					k++;
				}
			}
	}
	cout << "Новый массив:\n";
	for (int i = 0; i < number; i++)
		cout << arr1[i] << "\t";
	int sum = 0;
	for (int i = 0; i < number; i++)
		sum += arr1[i];
	sum = sum / number;
	cout << endl << "Среднее арифметическое нового массива: " << sum << endl;
	for (int i = 0; i < n; i++)
		delete[] arr[i];
	delete[] arr;
	delete[] arr1;
	return 0;
}