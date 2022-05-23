// Лабораторная работа 7, задача 5. Выполнена: Сивый А.А.
/*. Перевести число из арабской системы записи чисел в римскую.*/
#include <iostream>
#include <string>

using namespace std;


void convert(int N)
{
	int k = N;
	string a, b, c;
	int rank = 1;
	do
	{
		k = k / 10;
		rank++;
	} while (k >= 10);
	char* number = new char[rank];
	for (int i = 0; i < rank; i++)
	{
		k = (int)(N / pow(10, rank - i - 1));
		k = (int)(k % 10);
		number[i] = k;
	} 
	for (int i = 0; i < rank; i++)
	{
		if(i == rank - 6)
			a = "-C", b = "-D", c = "-M";
		else if (i == rank - 5)
			a = "-X", b = "-L", c = "-C";
		else if (i == rank - 4)
			a = 'M', b = "-V", c = "-X";
		else if (i == rank - 3)
			a = 'C', b = 'D', c = 'M';
		else if (i == rank - 1)
			a = 'I', b = 'V', c = 'X';
		else if (i == rank - 2)
			a = 'X', b = 'L', c = 'C';
		if (number[i] == 1 && i < 4)
			cout << a;
		else if (number[i] == 2)
			cout << a << a;
		else if (number[i] == 3)
			cout << a << a << a;
		else if (number[i] == 4)
			cout << a << b;
		else if (number[i] == 5)
			cout << b;
		else if (number[i] == 6)
			cout << b << a;
		else if (number[i] == 7)
			cout << b << a << a;
		else if (number[i] == 8)
			cout << a << a << c;
		else if (number[i] == 9)
			cout << a << c;
		}
	delete[] number;
}


int main()
{
	setlocale(LC_ALL, "ru");
	int N;
	cout << "Введите число:\n";
	cin >> N;
	convert(N);
	return 0;
}