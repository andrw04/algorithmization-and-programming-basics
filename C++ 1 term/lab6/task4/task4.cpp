// Лабораторная работа 6, задача 4. Выполнена:Сивый А.А.
/*1 апреля 20?? года будет проведена реформа английского языка,
позволяющая облегчить его освоение иностранцами и английскими
школьниками. Во-первых, из алфавита уберут четыре буквы C, Q, W и X (на
клавиатуре компьютера вместо них будут клавиши, вызывающие программы
Word, eXcel и другие). Вместо c перед буквами e, i, y нужно будет писать
букву s, а в остальных случаях – букву k. Вместо буквы q нужно будет писать
букву k, вместо сочетания qu –
kv, вместо x – ks, а вместо w – v. Во-вторых, сочетание букв ph будет
записываться как f, you и oo – как u, ee – как i, th – как z. Кроме того, все
двойные согласные (включая образовавшиеся после замен), вызывающие
большие трудности у учащихся, станут одинарными, например, apple после
реформы нужно писать как aple.
В связи с реформой нужно переработать огромное количество текстов.
Напишите программу, выполняющую эту работу. */
#include <iostream>
#include <string>
#include <stdio.h>


using namespace std;



void reforma(string &str)
{
	string cqwx = "CQWX";
	for (int i = 0; i < size(str);i++)
	{
		for(int j = 0; j < size(cqwx);j++)
			if(str[i] == cqwx[j])
				str.erase(i, 1);
	}
	int k = 0;
	while (k < size(str)*5) {
		for (int i = 0; i < size(str); i++)
		{
			if (str[i] == 'c' && (str[i + 1] == 'e' || str[i + 1] == 'i' || str[i + 1] == 'y') && i < size(str) - 1)
			{
				str[i] = 's';
			}
			if (str[i] == 'q' && str[i + 1] == 'u' && i < size(str) - 1)
			{
				str.replace(i, 2, "kv");
			}
			if (str[i] == 'c')
			{
				str[i] = 'k';
			}
			if (str[i] == 'w')
			{
				str[i] = 'v';
			}
			if (str[i] == 'q')
			{
				str[i] = 'k';
			}
			if (str[i] == 'x')
			{
				str.replace(i, 1, "k");
				str.insert(i + 1, "s", 0, 2);
			}
			if (str[i] == 'p' && str[i + 1] == 'h' && i < size(str) - 1)
			{
				str.replace(i, 1, "f");
				str.erase(i + 1, 1);
			}
			if (str[i] == 'P' && str[i + 1] == 'h' && i < size(str) - 1)
			{
				str.replace(i, 1, "F");
				str.erase(i + 1, 1);
			}
			if (str[i] == 'o' && str[i + 1] == 'o' && i < size(str) - 1)
			{
				str.replace(i, 1, "u");
				str.erase(i + 1, 1);
			}
			if (str[i] == 'O' && str[i + 1] == 'o' && i < size(str) - 1)
			{
				str.replace(i, 1, "U");
				str.erase(i + 1, 1);
			}
			if (str[i] == 'e' && str[i + 1] == 'e' && i < size(str) - 1)
			{
				str.replace(i, 1, "i");
				str.erase(i + 1, 1);
			}
			if (str[i] == 'E' && str[i + 1] == 'e' && i < size(str) - 1)
			{
				str.replace(i, 1, "I");
				str.erase(i + 1, 1);
			}
			if (str[i] == 't' && str[i + 1] == 'h' && i < size(str) - 1)
			{
				str.replace(i, 1, "z");
				str.erase(i + 1, 1);
			}
			if (str[i] == 'T' && str[i + 1] == 'h' && i < size(str) - 1)
			{
				str.replace(i, 1, "Z");
				str.erase(i + 1, 1);
			}
			if (str[i] == str[i + 1] && i < size(str) - 1)
			{
				str.erase(i + 1, 1);
			}
			if (str[i] == 'y' && str[i + 1] == 'o' && str[i + 2] == 'u' && i < size(str) - 2)
			{
				str.erase(i, 2);
			}
			if (str[i] == 'Y' && str[i + 1] == 'o' && str[i + 2] == 'u' && i < size(str) - 2)
			{
				str.erase(i, 2);
				str.replace(i, 1, "Y");
			}
		}
		k++;
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	string str;
	string text;
	cout << "Введите текст\n";
	char n;
	while (n = cin.peek() != EOF)
	{
		getline(cin, str);
		text += str;
		text += ' ';
	}
	for (int i = 0; i < 100; i++)
	{
		cout << "*";
	}
	reforma(text);
	cout << endl << text;
	return 0;
}