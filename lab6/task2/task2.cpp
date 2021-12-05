// Лабораторная работа 6, задача 2. Выполнена:Сивый А.А.
/*Рассматривать строки как указатель типа char.
Вариант 9. Найти, каких букв в тексте больше - гласных или согласных.*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int glas = 0, soglas = 0;
	char* str = new char[80];
	cout << "Введите строку\n";
	cin.getline(str, 80, '\n');
	char gl[] = "AEIOUYaeiouy";
	char sogl[] = "BCDFGHJKLMNPQRSTVWXZbcdfghjklmnpqrstvwxz";
	for (int i = 0; i < (int)strlen(str); i++)
	{
		for (int j = 0; j < (int)strlen(gl); j++)
		{
			if (str[i] == gl[j])
				glas++;
		}
		for (int j = 0; j < (int)strlen(sogl); j++)
		{
			if (str[i] == sogl[j])
				soglas++;
		}
	}
	if (glas > soglas)
		cout << "Гласных букв больше: " << glas << endl;
	else if (glas == soglas)
		cout << "Гласных и согласных букв поровну: " << glas << endl;
	else 
		cout << "Согласных букв больше: " << soglas << endl;
	return 0;
}