// Лабораторная работа 4, задача 2. Выполнена:Сивый А.А.
/*Инициализировать при объявлении статический двумерный массив целых чисел размером NxM.
Выполнить в соответствии с номером варианта индивидуальное задание и вывести на экран исходные данные и полученный результат.
Вариант 9: Найти максимальный среди элементов, лежащих выше побочной диагонали.*/
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	const int n = 3, m = 5;
	int array[n][m], k = 1;
	cout << "Введите значения массива " << n << " на " << m << "элементов\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			while (!(cin >> array[i][j]) || array[i][j] != round(array[i][j]))
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Введите корректное значение\n";
			}
		}
	}
	cout << "Элементы массива, находящиеся выше побочной диагонали\n";
	int max = array[0][0];
	for (int i = 0; i < n; i++)
	{
		for (int j = k;  j < m; j++)
		{
			cout << array[i][j] << "\t";
			if (array[i][j] >= max)
				max = array[i][j];
		}
		if (k < m)
			k += 1;
		cout << endl;
	}
	cout << endl << "MAX = " << max << endl;
	return 0;
}
