// Лабораторная работа 5, задача 3.1. Выполнена: Сивый А.А.
/*Дан двумерный динамический массив целых чисел А размерностью n x k .
Размерность массива (n = 5, k = 6) ввести с клавиатуры. Значения элементов массива
ввести с клавиатуры. Создать динамический массив из элементов, расположенных на
главной диагонали матрицы и имеющих четное значение. Вычислить произведение
элементов динамического массива.
Созданный массив и результат произведения вывести на экран.
Использовать функции.*/

#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	HINSTANCE load;
	load = LoadLibrary(L"DLL.dll");
	setlocale(LC_ALL, "ru");
	int n, m,count = 0,multiply = 1;
	cout << "Введите количество строк массива\n";
	while (!(cin >> n) || n < 0)
	{
		cout << "Введите корректное значение\n";
		cin.clear();
		cin.ignore(10000, '\n');
	}
	cout << "Введите количество столбцов массива\n";
	while (!(cin >> m) || m < 0)
	{
		cout << "Введите корректное значение\n";
		cin.clear();
		cin.ignore(10000, '\n');
	}
	int** A = new int* [n];
	for (int i = 0; i < n; i++)
	{
		A[i] = new int[m];
	}
	typedef void (*ar) (int**, int, int);
	ar inputArr;
	inputArr = (ar)GetProcAddress(load, "inputArr");
	inputArr(A, n, m);
	typedef void(*ar1)(int**, int, int);
	ar1 outputArr1;
	outputArr1 = (ar1)GetProcAddress(load, "outputArr1");
	outputArr1(A, n, m);
	for (int i = 0; i < n; i++)
	{
		if (A[i][i] % 2 == 0)
		{
			count += 1;
		}
	}
	int j = 0;
	int* B = new int[count];
	for (int i = 0; i < n; i++)
	{
		if (A[i][i] % 2 == 0)
		{
			B[j] = A[i][i];
			multiply *= B[j];
			j += 1;
		}
	}
	cout << "Массив:\n";
	for (int i = 0; i < count; i++)
	{
		cout << B[i] << "\t";
	}
	cout << endl << "Произведение элементов массива: " << multiply << "\n";
	for (int i = n; i < n; i++)
	{
		delete[] A[i];
	}
	delete[] A;
	delete[] B;
	return 0;
}