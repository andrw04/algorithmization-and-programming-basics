// Лабораторная работа 5, задача 3.2. Выполнена:Сивый А.А.
/*Создать двумерный динамический массив вещественных чисел. Определить,
встречаются ли среди них элементы с нулевым значением. Если встречаются такие
элементы, то определить их индексы и общее количество. Переставить элементы этого
массива в обратном порядке и вывести на экран.
Использовать функции.*/

#include <iostream>

using namespace std;

void Obr(double** arr, int n, int m)
{
	int number = n * m / 2, temp;
	if (number % 2)
		number = number + 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			--number;
			if (number < 0)
				continue;
			temp = arr[i][j];
			arr[i][j] = arr[n - i - 1][m - j - 1];
			arr[n - i - 1][m - j - 1] = temp;
		}
	}
}

void OutputArr(double** arr, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}
void InputArr(double** arr, int n, int m)
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
	int N, M, count = 0;
	cout << "Введите размеры массива N и M\n";
	cin >> N >> M;
	double** A = new double * [N];
	for (int i = 0; i < N; i++)
	{
		A[i] = new double[M];
	}
	InputArr(A, N, M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (A[i][j] == 0)
			{
				cout << "Индексы нулевого элемента: i =" << i << " j =" << j << endl;
				++count;
			}
		}
	}
	double** B = new double* [N];
	for (int i = 0; i < N; i++)
	{
		B[i] = new double[M];
	}
	Obr(A, N, M);
	OutputArr(A, N, M);
	for (int i = 0; i < N; i++)
	{
		delete[] A[i];
		delete[] B[i];
	}
	delete[] A;
	delete[] B;
	return 0;
}