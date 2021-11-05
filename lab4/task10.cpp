// Лабораторная работа 4, задача 10. Выполнена: Сивый А.А.
/*Построить магический квадрат любого порядка, используя любой алгоритм. Выделение памяти через функции языка С.*/
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	int r1, r2, r3, r4, c1, c2, c3, c4, d, sum;
	cout << "Программа строит магический квадрат 4 - го порядка\n";
	int** arr = (int**)calloc(4, sizeof(int*));
	for (int i = 0; i < 4; i++)
	{
		arr[i] = (int*)calloc(4, sizeof(int));
	}
	do
	{
		arr[0][0] = rand() % 9;
		arr[1][1] = rand() % 9;
		arr[2][2] = rand() % 9;
		arr[3][3] = rand() % 9;
		arr[2][0] = rand() % 9;
		arr[3][0] = rand() % 9;
		arr[3][1] = rand() % 9;
		arr[0][2] = rand() % 9;
		arr[1][3] = rand() % 9;
		arr[2][3] = rand() % 9;
		sum = arr[0][0] + arr[1][1] + arr[2][2] + arr[3][3];
		arr[1][0] = abs(sum - arr[0][0] - arr[2][0] - arr[3][0]);
		arr[2][1] = abs(sum - arr[2][0] - arr[2][2] - arr[2][3]);
		arr[0][1] = abs(sum - arr[1][1] - arr[2][1] - arr[3][1]);
		arr[0][3] = abs(sum - arr[0][0] - arr[0][1] - arr[0][2]);
		arr[3][2] = abs(sum - arr[3][0] - arr[3][1] - arr[3][3]);
		arr[1][2] = abs(sum - arr[0][2] - arr[2][2] - arr[3][2]);
		r1 = arr[0][0] + arr[0][1] + arr[0][2] + arr[0][3];
		r2 = arr[1][0] + arr[1][1] + arr[1][2] + arr[1][3];
		r3 = arr[2][0] + arr[2][1] + arr[2][2] + arr[2][3];
		r4 = arr[3][0] + arr[3][1] + arr[3][2] + arr[3][3];
		c1 = arr[0][0] + arr[1][0] + arr[2][0] + arr[3][0];
		c2 = arr[0][1] + arr[1][1] + arr[2][1] + arr[3][1];
		c3 = arr[0][2] + arr[1][2] + arr[2][2] + arr[3][2];
		c4 = arr[0][3] + arr[1][3] + arr[2][3] + arr[3][3];
		d = arr[3][0] + arr[2][1] + arr[1][2] + arr[0][3];

	} while (r1 != sum || r2 != sum || r3 != sum || r4 != sum || c1 != sum || c2 != sum || c3 != sum || c4 != sum ||d != sum);
	cout << "Магический квадрат:\n";
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	for (int i = 0; i < 4; i++)
	{
		free(arr[i]);
	}
	free(arr);
	return 0;
}
