#include <iostream>
using namespace std;

extern "C" __declspec(dllexport) void inputArr(int** A, int n, int m) // ввод элементов двумерного массива
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "¬ведите элемент массива [" << i << "]" << "[" << j << "]:";
			while (!(cin >> A[i][j]))
			{
				cout << "¬ведите корректное значение\n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
		}
	}
}



extern "C" __declspec(dllexport) void outputArr(int** A, int n) // вывод одномерного массива
{
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << "\t";
	}
}



extern "C" __declspec(dllexport) void outputArr1(int** A, int n, int m) // вывод двумерного массива
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << A[i][j] << "\t";
		}
		cout << endl;
	}
}