// Лабораторная работа 4, задача 11. Выполнена: Сивый А.А.
/*Дан трёхмерный динамический массив размером n^3 целых неотрицательных чисел. Необходимо определить диагональ с наибольшей
суммой чисел.Для обхода диагоналей нельзя использовать вложенные циклы*/
#include <iostream>

using namespace std;

int main()
{
	int n, sum1 = 0, sum2 = 0, sum3 = 0,sum4 =0, x = 0, y = 0, z = 0;
	setlocale(LC_ALL, "Russian");
	cout << "Введите размер массива\n";
	while (!(cin >> n) || n != round(n) || n <= 1)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Введите корректное значение\n";
	}
	int*** arr = new int**[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int * [n];
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = new int[n];
		}
	}
	cout << "Введите элементы массива\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				cin >> arr[i][j][k];
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		x = n - i - 1;
		sum1 += arr[i][i][i];
		sum2 += arr[i][x][i];
		sum3 += arr[i][x][x];
		sum4 += arr[i][i][x];

	}
	if (sum1 >= sum2 && sum1 >= sum3 && sum1 >= sum4)
	{
		cout << "Диагональ с наибольшей суммой чисел: a[0][0][0] => a[n-1][n-1][n-1] =  " << sum1 << endl;
		if (sum1 == sum2)
			cout << "Диагональ равна диагонали a[0][n-1][0] => a[n-1][0][n-1]" << endl;
		if (sum1 == sum3)
			cout << "Диагональ равна диагонали a[0][n-1][n-1] => a[n-1][0][0]" << endl;
		if (sum1 == sum4)
			cout << "Диагональ равна диагонали a[0][0][n-1] => a[n-1][n-1][0]" << endl;
	}
	else if (sum2 >= sum1 && sum2 >= sum3 && sum2 >= sum4)
	{
		cout << "Диагональ с наибольшей суммой чисел: a[0][n-1][0] => a[n-1][0][n-1] = " << sum2 << endl;
		if (sum2 == sum1)
			cout << "Диагональ равна диагонали a[0][0][0] => a[n-1][n-1][n-1]" << endl;
		if (sum2 == sum3)
			cout << "Диагональ равна диагонали a[0][n-1][n-1] => a[n-1][0][0]" << endl;
		if (sum2 == sum4)
			cout << "Диагональ равна диагонали a[0][0][n-1] => a[n-1][n-1][0]" << endl;
	}
	else if (sum3 >= sum1 && sum3 >= sum2 && sum3 >= sum4)
	{
		cout << "Диагональ с наибольшей суммой чисел: a[0][n-1][n-1] => a[n-1][0][0] = " << sum3 << endl;
		if (sum3 == sum2)
			cout << "Диагональ равна диагонали a[0][n-1][0] => a[n-1][0][n-1]" << endl;
		if (sum3 == sum1)
			cout << "Диагональ равна диагонали a[0][0][0] => a[n-1][n-1][n-1]" << endl;
		if (sum3 == sum4)
			cout << "Диагональ равна диагонали a[0][0][n-1] => a[n-1][n-1][0]" << endl;
	}
	else
	{
		cout << "Диагональ с наибольшей суммой чисел: a[0][0][n-1] => a[n-1][n-1][0] = " << sum4 << endl;
		if (sum4 == sum2)
			cout << "Диагональ равна диагонали a[0][n-1][0] => a[n-1][0][n-1]" << endl;
		if (sum4 == sum1)
			cout << "Диагональ равна диагонали a[0][0][0] => a[n-1][n-1][n-1]" << endl;
		if (sum4 == sum3)
			cout << "Диагональ равна диагонали a[0][n-1][n-1] => a[n-1][0][0]" << endl;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			delete [] arr[i][j];
		}
		delete[] arr[i];
	}
	delete[] arr;
	return 0;
}
