// Лабораторная работа 7, задача 2. Выполнена:Сивый А.А.
/*Перевести числа. Предусмотреть ввод положительных и
отрицательных чисел..
Вариант 9) Из естественной формы в прямой код.
*/
#include <iostream>

using namespace std;

string bin(int N) {
	string num;
	if (N > 0)
		num = "00000000000000000000000000000000";
	else if(N <= 0)
		num = "10000000000000000000000000000000";
	for (int i = 31; i > 0; i--){
		num[i] = abs(N) % 2 + 48;
		N /= 2;
	}
	return num;
}
int main()
{
	setlocale(LC_ALL, "ru");
	int N;
	cout << "Введите число N\n";
	while (!(cin >> N || N > 2000000000 || N < 2000000000)) {
		cout << "Введите корректное значение\n";
		cin.clear();
		cin.ignore(10000, '\n');
	}
	cout << bin(N);
	return 0;
}