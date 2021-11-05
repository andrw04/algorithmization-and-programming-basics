// Лабораторная работа 4, задача 12. Выполнена: Сивый А.А.
/*Написать функцию которая будет удалять дубликаты элементов из массива. Входные параметры: массив, длина массива. Выходрные параметры:
новый массив, новый размер.*/
#include <iostream>

using namespace std;

void func(double *&A, int &size)
{
	bool left = false;
	int n = 0;
	for (int i = 0; i < size; i++)
	{
		for(int j = i - 1; j >= 0; j--)
		{
			if (A[j] == A[i])
				left = true;
		}
		for (int k = i + 1; k < size; k++)
		{
			if (left == true)
			{
				break;
			}
			else if (A[i] == A[k])
			{
				n += 1;
			}
		}
		left = false;
	}
	cout << "n =" << n << endl;
	int NewSize = size;
	size = size - n;

	double* B = new double[size];
	n = 0;
	int x = 0;
	B[0] = A[0];
	for (int i = 0; i < NewSize; i++)
	{
		for(int j = i - 1; j >= 0; j--)
			if (B[j] == A[i])
			{
				left = true;
			}
		if (left)
		{
			left = false;
			continue;
		}
		else
		{
			if (x < size)
			{
				B[x] = A[i];
				x += 1;
			}
		}
	}
	cout << "n= " << n << endl;
	delete[] A;
	A = B;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	int size;
	cout << "Введите длину массива\n";
	while (!(cin >> size) || size != round(size) || size <= 1)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Введите корректное значение\n";
	}
	double* A = new double[size];
	for (int i = 0; i < size; i++)
		cin >> A[i];
	func(A, size);
	cout << "Новый массив\n";
	for (int i = 0; i < size; i++)
	{
		cout << A[i] << " ";
	}
	cout << "SIZE = " << size << endl;
	return 0;
}
