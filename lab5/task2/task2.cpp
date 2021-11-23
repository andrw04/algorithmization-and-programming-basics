// Лабораторная работа 5, задача 2. Выполнена:Сивый А.А.
/*Вариант 9. Для заданного одномерного массива C из N элементов найти произведение множителей,
вычисляемых по формуле sin(C[i]) - cos(C[i]). Рекурсивную функцию применять каждый раз отдельно для
первой трети массива и для основной части(2/3) массива. Рекурсивные вызовы заканчивать, когда
останется только один или два элемента.*/
#include <iostream>
#include <cmath>
#include <ctime>

double rekurs(int* array, int Size)
{
	if (Size > 1)
	{
		return (sin(array[Size-1]) - cos(array[Size-1])) * rekurs(array,Size-1);
	}
	if (Size == 1)
	{
		return sin(array[0]) - cos(array[0]);
	}
}

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int N;
	cout << "Введите количество элементов массива\n";
	while (!(cin >> N) || N < 3)
	{
		cout << "Введите корректное значение\n";
		cin.clear();
		cin.ignore(10000, '\n');
	}
	int* C = new int[N];
	cout << "Исходный массив\n";
	for (int i = 0; i < N; i++)
	{
		C[i] = rand() % 100;
		cout << C[i] << "\t";
	}
	cout << endl;
	int Size1 = N / 3, Size2 = N - Size1;
	int* arr1 = new int[Size1];
	int* arr2 = new int[Size2];
	for (int i = 0; i < Size1; i++)
	{
		arr1[i] = C[i];
	}
	for (int i = 0; i < Size2; i++)
	{
		arr2[i] = C[Size1 + i];
	}
	cout << "Произведение = " << rekurs(arr1, Size1) * rekurs(arr2, Size2);
	delete[] arr1;
	delete[] arr2;
	delete[] C;
	return 0;
}