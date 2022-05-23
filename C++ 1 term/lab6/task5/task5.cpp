// Лабораторная работа 6, задча 5. Выполнена:Сивый А.А.
/*Во многих прикладных задачах, таких как поиск в сети или расшифровка
генома, требуется совершать некоторые действия со строками. Например,
часто требуется по некоторым данным о строке восстановить ее саму.
Вам даны две строки S1 и S2. Известно, что одна из них была суффиксом
искомой строки S, а другая — ее префиксом. Также известна длина искомой
строки L, а также то, что строка S состояла только из строчных букв
латинского алфавита.
Необходимо определить число строк, удовлетворяющих этим
ограничениям. Так как это число может быть достаточно большим, то
необходимо вывести его по модулю m.*/
#include <iostream>
#include <cmath>


using namespace std;



int f(char* s1, char* s2,int L, int m)
{
	int same = 0;
	int sum1 = 0;
	int sum2 = 0;
	int k = 0;
	int difference;
	for (int i = 0; i < strlen(s1); i++)
	{
		if (s1[i] == s2[0])
		{
			for (int j = 0; j < strlen(s1) - i; j++)
			{
				if (s1[i + j] == s2[j])
				{
					k++;
					if(k >= same);
					    same = k;
				}
				else
				{
					k = 0;
					same = 0;
					break;
				}
			}
		}
	}
	difference = L - strlen(s1) - (strlen(s2) - same);
	if (difference < 0)
		sum1 = 0;
	else if (difference == 0)
		sum1 = pow(26,0);
	else
		sum1 = pow(26, L - strlen(s1) - (strlen(s2) - same));
	k = 0, same = 0;
	for (int i = 0; i < strlen(s2); i++)
	{
		if (s2[i] == s1[0])
		{
			for (int j = 0; j < strlen(s2) - i; j++)
			{
				if (s2[i + j] == s1[j])
				{
					k++;
					if(k >= same);
						same = k;
				}
				else
				{
					k = 0;
					same = 0;
					break;
				}
			}
		}
	}
	difference = L - strlen(s1) - (strlen(s2) - same);
	if (difference < 0)
		sum2 = 0;
	else if (difference == 0)
		sum2 = pow(26, 0);
	else
		sum2 = pow(26, L - strlen(s1) - (strlen(s2) - same));
	return (sum1 + sum2) % m;
}

int main()
{
	setlocale(LC_ALL, "ru");
	int t,L,m;
	char *s1 = new char[200];
	char* s2 = new char[200];
	cout << "Введите количество наборов данных t\n";
	while (!(cin >> t))
	{
		cout << "Введите корректное значение\n";
		cin.clear();
		cin.ignore(10000, '\n');
	}
	for (int i = 0; i < t; i++)
	{
		cout << "Введите числа L и m\n";
		while (!(cin >> L >> m))
		{
			cout << "Введите корректное значение\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		cout << "Введите строки s1 и s2\n";
		while (!(cin >> s1 >> s2))
		{
			cout << "Введите корректное значение\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		cout << "Число строк: " << f(s1, s2, L, m) << endl;
	}
	delete[] s1;
	delete[] s2;
	return 0;
}