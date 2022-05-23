// Лабораторная работа 5, дополнительное задание 3. Выполнена:Сивый А.А.
/*Пусть f(n) - наибольший нечетный делитель натурального числа n. По заданному
натуральному n необходимо вычислить значение суммы f(1) + f(2) + ... + f(n).
*/
#include <iostream>

using namespace std;

int fn(int n)
{
	if (n % 2 == 0)
		fn(n / 2);
	else
		return n;
}



int sum(int n)
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
		sum += fn(i);
	return sum;

}



int main()
{
	setlocale(LC_ALL, "ru");
	int n;
	cout << "Введите натуральное n\n";
	while (!(cin >> n) || n <= 0)
	{
		cout << "Введите корректное значение\n";
		cin.clear();
		cin.ignore(10000, '\n');
	}
	cout << "Значение суммы для n = " << n << ":" << sum(n) << endl;
	return 0;
}