#include "func.h"
#include <iostream>

using namespace std;

void Transp(int** A, int** B, int n) // транспонирование матрицы
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			B[i][j] = A[j][i];
		}
	}
}

void Sum(int** A, int n, int k) // находим сумму строк и столбцов
{
	for (int i = 0; i < n; i++)
	{
		int sumROWS = 0;
		for (int j = 0; j < n; j++)
		{
			cout << A[i][j] << "\t";
			sumROWS += A[i][j];
		}
		if (i % 2 == k)
		{
			cout  << "Sum = " << sumROWS << "\t";
		}
		cout << endl;
	}
	for (int j = 0; j < n; j++)
	{
		int sumCOLUMS = 0;
		for (int i = 0; i < n; i++)
		{
			sumCOLUMS += A[i][j];
		}
		if (j % 2 == abs(k - 1))
			cout << sumCOLUMS << "\t";
		else
			cout << "\t";
	}
	cout << "Sum Colums";
	cout << endl;
}