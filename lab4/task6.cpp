// Лабораторная работа 4, задача 6. Выполнена:Сивый А.А.
/*Для заданной матрицы А размерности N*M построить матрицу В такого же размера, элементы которой обладают следющим свойством:
элемент В[i,j] равен максимальному из элементов матрицы А, расположенных левее и выше позиции (i,j), включая позицию (i,j). При этом
считается, что позиция (1,1) - верхняя левая позиция матрицы.
*/
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	double max;
	int rows, colums;
	cout << "Введите количество строк и столбцов матрицы\n";
	while (!(cin >> rows) || rows <= 1 || rows != round(rows))
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Введите корректное значение\n";
	}
	while (!(cin >> colums) || colums <= 1 || colums != round(colums))
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Введите корректное значение\n";
	}
	double** A = new double*[rows]; // создаём исходный массив A
	for (int i = 0; i < rows; i++)
	{
		A[i] = new double[colums];
	}
	cout << "Введите элементы массива\n";
	for (int i = 0; i < rows; i++) // заполняем исходный массив
	{
		for (int j = 0; j < colums; j++)
		{
			while (!(cin >> A[i][j]))
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Введите корректное значение\n";
			}
		}
	}
	cout << endl << endl << "Исходный массив:" << endl << endl;
	for (int i = 0; i < rows; i++) // выводим исходный массив
	{
		for (int j = 0; j < colums; j++)
		{
			cout << A[i][j] << "\t";
		}
		cout << endl;
	}
	double** B = new double* [rows]; // создаём новый массив
	for (int i = 0; i < rows; i++)
	{
		B[i] = new double[colums];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colums; j++)
		{
			max = A[i][j];
			for (int y = i; y >= 0; y--)
			{
				for (int x = j; x >= 0; x--)
				{
					if (A[y][x] >= A[i][j] && A[y][x] >= max)
						max = A[y][x];
				}
			}
			B[i][j] = max;
		}
	}
	cout << endl << endl << "Новый массив:" << endl << endl;
	for (int i = 0; i < rows; i++) // Выводим новый массив В
	{
		for (int j = 0; j < colums; j++)
		{
			cout << B[i][j] << "\t";
		}
		cout << endl;
	}
	for (int i = 0; i < rows; i++) // освобождаем память от массива А
	{
		delete[] A[i];
	}
	delete[] A;
	for (int i = 0; i < rows; i++) // освобождаем память от массива В
	{
		delete[] B[i];
	}
	delete[] B;
	return 0;
}
