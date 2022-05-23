// Лабораторная работа 5, дополнительная задача 1. Выпонена: Сивый А.А.
/*Определим следующую рекурсивную функцию F(n)
F(n) = n%10, if (n%10 > 0)
F(n) = 0, if n = 0
F(n) = F(n/10), Otherwise
Определим функцию S(p,q) следующим образом:
S(p,q) = F(p) + ... + F(q)*/
#include <iostream>

using namespace std;

int F(int n)
{
	if (n % 10 > 0)
	{
		return n % 10;
	}
	else if (n == 0)
	{
		return 0;
	}
	else
	{
		return F(n / 10);
	}
}



int S(int p, int q)
{
	int S = 0;
	for (int i = p; i <= q; i++)
	{
		S += F(i);
	}
	return S;
}



int main()
{
	setlocale(LC_ALL, "ru");
	int p, q;
	cout << "Введите значения p и q (p < q)\n";
	while (!(cin >> p >> q) || p < 0 || q < 0 || q < p)
	{
		cout << "Введите корректное значение\n";
		cin.clear();
		cin.ignore(10000, '\n');
	}
	cout << "S = " << S(p, q) << endl;
	return 0;
}