// Лабораторная работа 4, задача 4. Выполнена: Сивый А.А.
/*Элемент матрицы называется локальным минимумом, если он строго меньше всех имеющихся у него соседей.
Соседями элемента a[i][j] в матрице назовём элементы a[k][g], где i-1 <= k <= i + 1, j - 1 <= g <= i +1, (k,g) != (i,j)
Подсчитать количество локальных минимумов заданной матрицы*/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int rows, colums, loc_min = 0;
	bool l,r,t,b;
	cout << "Введите количество строк и столбцов\n";
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
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new double[colums];
	}
	cout << "Введите элементы массива\n";
	for (int i = 0; i < rows; i++) // заполнение массива
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
	cout << "Исходный массив\n";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colums; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	for (int i = 0; i < rows; i++)
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
				if (arr[i][j] < arr[i - 1][j] && arr[i][j] < arr[i][j - 1] && arr[i][j] < arr[i + 1][j] && arr[i][j] < arr[i][j + 1])
					loc_min += 1;
			}
			else if (!t && l && b && r) // нет соседа сверху
			{
				if (arr[i][j] < arr[i][j - 1] && arr[i][j] < arr[i + 1][j] && arr[i][j] < arr[i][j + 1])
					loc_min += 1;
			}
			else if (!t && !l && b && r) // нет соседа сверху и слева
			{
				if (arr[i][j] < arr[i + 1][j] && arr[i][j] < arr[i][j + 1])
					loc_min += 1;
			}
			else if (!t && l && b && !r) // нет соседа сверху и справа
			{
				if (arr[i][j] < arr[i][j - 1] && arr[i][j] < arr[i + 1][j])
					loc_min += 1;
			}
			else if (t && !l && !b && r) // нет соседей слева и снизу
			{
				if (arr[i][j] < arr[i - 1][j] && arr[i][j] < arr[i][j + 1])
					loc_min += 1;
			}
			else if (t && l && !b && !r) // нет соседей снизу и справа
			{
				if (arr[i][j] < arr[i - 1][j] && arr[i][j] < arr[i][j - 1])
					loc_min += 1;
			}
			else if (t && !l && b && r) // нет соседей слева
			{
				if (arr[i][j] < arr[i - 1][j] && arr[i][j] < arr[i + 1][j] && arr[i][j] < arr[i][j + 1])
					loc_min += 1;
			}
			else if (t && l && !b && r) // нет соседей снизу
			{
				if (arr[i][j] < arr[i - 1][j] && arr[i][j] < arr[i][j - 1] && arr[i][j + 1])
					loc_min += 1;
			}
			else if (t && l && b && !r)// нет соседей справа
			{
				if (arr[i][j] < arr[i - 1][j] && arr[i][j] < arr[i + 1][j] && arr[i][j] < arr[i][j - 1])
					loc_min += 1;
			}
		}
	}
	for (int i = 0; i < rows; i++) // освобождение памяти
		delete[] arr[i];
	delete[] arr;
	cout << "Количество локальных минимумов:" << loc_min << endl;
	return 0;
}
