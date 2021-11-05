// Лабораторная работа 4, задача 13. Выполнена: Сивый А.А.
/*У Миши в общежитии всего лишь 1 розетка. Дабы исправить это недоразумение, миша купил N удлинителей таких, что i-й удлинитель
имеет a[i] входов. Вычислите, сколько розеток получится у Миши, если он оптимально соеднит удлинители?*/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int N;
	cout << "Введите количество удлинителей N\n";
	while (!(cin >> N) || N != round(N) || N < 1)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Введите корректное значение\n";
	}
	int* arr = new int[N];
	srand(time(0));
	for (int i = 0; i < N ;i++)
	{
		arr[i] = 1 + rand() %5;
	}
	cout << "Массив:\n";
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
	int sum = 0;
	for (int i = 0; i < N ; i++)
	{
		sum += arr[i];
	}
	int k = N - 1; // количество занятый розеток
	sum = sum - k;
	cout << endl << "Количество свободных разеток: " << sum << endl;
	delete[] arr;
	return 0;
}
