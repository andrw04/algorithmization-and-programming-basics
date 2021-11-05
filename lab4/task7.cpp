// Лабораторная работа 4, задача 7. Выполнена:Сивый А.А.
/*Дано натуральное число n. Требуется подсчитать количество цифр числа и определить, какая цифра стоит в разряде с номером i(разряды 
нумеруются с конца, т.е. разряд единиц имеет номер 0)*/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, number, size = 1,i;
	cout << "Введите число\n";
	while (!(cin >> n) || n < 1 || n != round(n))
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Введите корректное значение\n";
	}
	int x = n;
	do
	{
		x = n % (int)pow(10, size);
		if (x != n)
			size += 1;
			
	} while (x != n);
	cout << "Количество разрядов:" << size << endl;
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		number = (int)(n % (int)pow(10, i+1) / pow(10,i));
		arr[i] = number;
	}
	cout << "Введите разряд числа, которое хотите узнать(начиная с 0)\n";
	while (!(cin >> i) || i > size -1 || i != round(i))
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Введите корректное значение\n";
	}
	cout << arr[i] << endl;
	delete[] arr;
	return 0;
}
