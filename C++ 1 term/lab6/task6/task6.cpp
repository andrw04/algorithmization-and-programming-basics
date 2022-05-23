// Лабораторная работа 6, задача 6. Выполнена:Сивый А.А.
/*Анаграммой слова называется любая перестановка всех букв слова.
Например, из слова SOLO можно получить 12 анаграмм: SOLO, LOSO,
OSLO, OLSO, OSOL, OLOS, SLOO, LSOO, OOLS, OOSL, LOOS,
SOOL.
Напишите программу, которая выводит количество различных
анаграмм, которые могут получиться из этого слова. */
#include <iostream>
#include <string>

using namespace std;


long int f(int number) // factorial
{
	if (number == 0)
		return 1;
	else if (number == 1)
		return 1;
	else
		return number * f(number - 1);

}


int perestanovka(char*str,int size)
{
	int* pov = new int[size];
	bool index;
	int number = 0;
	int answer;
	for (int i = 0; i < size; i++)
	{
		index = false;
		number = 0;
		for (int j = i - 1; j >= 0; j--) 
		{
			if (str[i] == str[j])
				index = true;
		}
		if (index)
		{
			pov[i] = 0;
			continue;
		}
		for (int j = i; j < size; j++)
		{
			if (str[i] == str[j])
				number++;
		}
		pov[i] = number;
	}
	answer = f(size);
	for (int i = 0; i < size; i++)
	{
		answer /= f(pov[i]);
	}
	delete[] pov;
	return answer;
}



int main()
{
	setlocale(LC_ALL, "ru");
	char* str = new char[14];
	cout << "Введите строку\n";
	cin.getline(str, 14, '\n');
	cout << "Количество перестановок: " << perestanovka(str, strlen(str)) << endl;
	delete[] str;
	return 0;
}