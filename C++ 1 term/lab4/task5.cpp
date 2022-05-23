// Лабораторная работа 4, задача 5. Выполнена:Сивый А.А.
/*Соседями элемента ajj в матрице назовём элементы. Соседями элемента в матрице назовём элементы a[k][g], где i-1<=k<=i+1,
j-1<=g<=j+1,(k,g) != (i,j). Операция сглаживания матрицы даёт новую матрицу того же размера, каждый элемент которой получается как
среднее арифметическое имеющихся соседей соответствующего элемента исходной матрицы. Построить результат сглаживания заданной вещественной
матрицы*/
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	double rows, colums;
	bool t, b, l, r;
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
	double** arr = new double* [rows];
	for (int i = 0; i < rows; i++) // создание массива arr
	{
		arr[i] = new double[colums];
	}
	cout << "Введите элементы массива\n";
	for (int i = 0; i < rows; i++) // заполнение исходного массива
	{
		for (int j = 0; j < colums; j++)
		{
			while (!(cin >> arr[i][j]))
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Введите корректное значение\n";
			}
		}
	}
	cout << endl << endl << "ИСХОДНЫЙ МАССИВ:" << endl << endl;
	for (int i = 0; i < rows; i++) // выводим исходный массив
	{
		for (int j = 0; j < colums; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	double** array = new double* [rows];
	for (int i = 0; i < rows; i++) // создаём новый массив array
	{
		array[i] = new double[colums];
	}
	for (int i = 0; i < rows; i++) // перебираем элементы массива arr
	{
		for (int j = 0; j < colums; j++)
		{
			t = true;
			l = true;
			b = true;
			r = true;
			if (i == 0)
				t = false;
			if (j == 0)
				l = false;
			if (i == rows - 1)
				b = false;
			if (j == colums - 1)
				r = false;

			if (t && l && b && r) // есть все соседи
			{
				array[i][j] = (arr[i - 1][j] + arr[i][j - 1] + arr[i + 1][j] + arr[i][j + 1]) / 4;
			}
			else if (!t && l && b && r) // нет соседа сверху
			{
				array[i][j] = (arr[i][j - 1] + arr[i + 1][j] + arr[i][j + 1]) / 3;

			}
			else if (!t && !l && b && r) // нет соседа сверху и слева
			{
				array[i][j] = (arr[i][j + 1] + arr[i + 1][j]) / 2;
			}
			else if (!t && l && b && !r) // нет соседа сверху и справа
			{
				array[i][j] = (arr[i + 1][j] + arr[i][j - 1]) / 2;
			}
			else if (t && !l && !b && r) // нет соседей слева и снизу
			{
				array[i][j] = (arr[i][j + 1] + arr[i - 1][j]) / 2;
			}
			else if (t && l && !b && !r) // нет соседей снизу и справа
			{
				array[i][j] = (arr[i - 1][j] + arr[i][j - 1]) / 2;
			}
			else if (t && !l && b && r) // нет соседей слева
			{
				array[i][j] = (arr[i][j + 1] + arr[i + 1][j] + arr[i - 1][j]) / 3;
			}
			else if (t && l && !b && r) // нет соседей снизу
			{
				array[i][j] = (arr[i - 1][j] + arr[i][j - 1] + arr[i][j + 1]) / 3;
			}
			else if (t && l && b && !r)// нет соседей справа
			{
				array[i][j] = (arr[i - 1][j] + arr[i + 1][j] + arr[i][j - 1]) / 3;
			}
			else
				array[i][j] = 0;
		}
	}
	cout << endl << endl << "СГЛАЖЕННЫЙ МАССИВ:" << endl << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colums; j++)
		{
			cout << fixed << setprecision(1) << array[i][j] << "\t";
		}
		cout << endl;
	}
	for (int i = 0; i < rows; i++) // освобождение памяти от массивов
	{
		delete[] arr[i];
		delete[] array[i];
	}
	delete[] arr;
	delete[] array;
	return 0;
}
