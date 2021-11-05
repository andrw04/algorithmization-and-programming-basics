// Лабораторная работа 4, задача 9. Выполнена: Сивый А.А.
/*В качестве входных данных поступают две целочисленные матрицы А и В, которые имеют размер N и соответственно. Требуется
найти произведение матриц А*B. Выделение памяти через функции языка С*/
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
	int row1, row2, colum1, colum2;
	setlocale(LC_ALL, "Russian");
	cout << "Введите количество строк первой матрицы\n";
	while (!(cin >> row1) || row1 !=round(row1) || row1 <=1)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Введите корректное значение\n";
	}
	cout << "Введите количество столбцов первой матрицы\n";
	while (!(cin >> colum1) || colum1 != round(colum1) || colum1 <= 1)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Введите корректное значение\n";
	}
	cout << "Введите количество строк второй матрицы\n";
	while (!(cin >> row2) || row2 != round(row2) || row2 <= 1)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Введите корректное значение\n";
	}
	cout << "Введите количество столбцов второй матрицы\n";
	while (!(cin >> colum2) || colum2 != round(colum2) || colum2 <= 1)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Введите корректное значение\n";
	}
	if (colum1 == row2)
	{
		cout << "Матрицы можно перемножить\n";
	}
	else
	{
		cout << "Матрицы перемножить нельзя\n";
		return 1;
	}
	int** A = (int**)calloc(row1, sizeof(int*));
	for (int i = 0; i < row1; i++)
	{
		A[i] = (int*)calloc(colum1, sizeof(int));
	}
	int** B = (int**)calloc(row2, sizeof(int*));
	for (int i = 0; i < row2; i++)
	{
		B[i] = (int*)calloc(colum2, sizeof(int));
	}
	cout << "Введите значения матрицы A:\n";
	for (int i = 0; i < row1; i++)
	{
		for (int j = 0; j < colum1; j++)
		{
			cout << "A[" << i << "]" << "[" << j << "] = ";
			while (!(cin >> A[i][i]) || A[i][j] != round(A[i][j]))
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Введите корректное значение\n";
			}
		}
	}
	cout << "Введите значения матрицы B:\n";
	for (int i = 0; i < row2; i++)
	{
		for (int j = 0; j < colum2; j++)
		{
			cout << "B[" << i << "]" << "[" << j << "] = ";
			while (!(cin >> B[i][i]) || B[i][j] != round(A[i][j]))
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Введите корректное значение\n";
			}
		}
	}
	int** C = (int**)calloc(row1, sizeof(int*));
	for (int i = 0; i < row1; i++)
	{
		C[i] = (int*)calloc(colum2, sizeof(int));
	}
	for (int i = 0; i < row1; i++)
	{
		for (int j = 0; j < colum2; j++)
		{
			C[i][j] = 0;
			for (int k = 0; k < colum1; k++)
			{
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	cout << "Матрица С, полученная умножением матрицы А на матрицу В:\n";
	for (int i = 0; i < row1; i++)
	{
		for (int j = 0; j < colum2; j++)
		{
			cout << C[i][j] << "\t";
		}
		cout << endl;
	}
	for (int i = 0; i < row1; i++)
	{
		free(A[i]);
	}
	for (int i = 0; i < row2; i++)
	{
		free(B[i]);
	}
	for (int i = 0; i < row1; i++)
	{
		free(C[i]);
	}
	free(A);
	free(B);
	free(C);
}
