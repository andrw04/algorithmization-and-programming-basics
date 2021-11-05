// Лабораторная работа 4, задача 8. Выполнена: Сивый А.А.
/*Заменить нулями все элементы, которые находятся в ячейках между минимальным и максимальным элементами(не включая их).
Изначально все элементы в массиве различные. если после данного действия большая часть массива будет содержать нули, то удалить все
нулевые элементы из массива(с сохранением порядка следования остальных элементов)*/
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int length,zero = 0,ind_min=0,ind_max=0;
	cout << "Введите количество элементов массива\n";
	while (!(cin >> length) || length <= 2)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Введите корректное значение\n";
	}
	double* A = new double[length];
	cout << "Введите элементы массива\n";
	for (int i = 0; i < length; i++)
	{
		while (!(cin >> A[i]) || A[i] != round(A[i]))
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Введите корректное значение\n";
		}
	}

	double min = A[0];
	double max = A[0];
	for (int i = 0; i < length; i++)
	{
		if (A[i] >= max)
		{
			max = A[i];
			ind_max = i;
		}
		if (A[i] < min)
		{
			min = A[i];
			ind_min = i;
		}
	}
	if (ind_min < ind_max)
	{
		for (int i = ind_min+1; i < ind_max; i++)
		{
			A[i] = 0;
			zero += 1;
		}
	}
	else
	{
		for (int i = ind_max+1; i < ind_min; i++)
		{
			A[i] = 0;
			zero += 1;
		}
	}
	cout << "Новый массив:\n";
	for (int i = 0; i < length; i++)
		cout << A[i] << " ";
	cout << endl;
	if (zero > length / 2)
	{
		cout << "Нулей больше половины\n";
		double* B = new double[length - zero];
		int j = 0;
		for (int i = 0; i <= length; i++)
		{
			if (A[i] != 0)
			{
				B[j] = A[i];
				j += 1;
			}
		}
		for (int i = 0; i < length - zero; i++)
			cout << B[i] << " ";
		delete[] B;
	}
	delete[] A;
	return 0;
}
