// Лабораторная работа 4, задача 4. Выполнена: Сивый А.А.
/*Осуществить сложение и вычитание чисел в заданной системе
счисления. В другую систему счисления не переводить. В системах
счисления больших десятичной использовать буквы по аналогии с
шестнадцатеричной системой. Разработать функции для выполнения
операции сложения и функции для выполнения операции вычитания.
Предусмотреть ввод положительных и отрицательных чисел.
Вариант 9) В одиннадцатеричной;*/
#include <iostream>

using namespace std;

void Sum(string A, string B,int size) {
		char* Sum = new char[size];
		int cu = 0; // перенос в новый разряд
		int temp = 0;
		for (int i = size - 1; i >= 0; i--) {
			if (A[i] == 'A')
				temp += 10;
			else 
				temp = A[i] - 48;
			if (B[i] == 'A')
				temp += 10;
			else
				temp += B[i] - 48;
			temp += cu;
			cu = 0;
			if (temp - 11 == 10) {
				Sum[i] = 'A';
			}
			else if (temp > 10) {
				cu += 1;
				Sum[i] = (char)temp - 11 + 48;
			}
			else if (temp < 10) {
				Sum[i] = (char)temp + 48;
			}
			temp = 0;
		}
		for (int i = 0; i < size; i++)
			cout << Sum[i];
		delete[] Sum;
}
void diff(string A, string B, int size) {
	char* diff = new char[size];
	int cu = 0;
	int temp = 0;
	for (int i = size - 1; i >= 0; i--) {
		if (A[i] == 'A')
			temp += 10;
		else
			temp += A[i] - 48;
		if (B[i] == 'A')
			temp -= 10;
		else
			temp -= B[i] - 48;
		temp -= cu;
		cu = 0;
		if (temp < 0) {
			temp += 11;
			cu = 1;
		}
		diff[i] = temp + 48;
		temp = 0;
	}
	for (int i = 0; i < size; i++)
		cout << diff[i];
}

int main()
{
	setlocale(LC_ALL, "ru");
	string A;
	string B;
	cout << "Введите число a\n";
	cin >> A;
	for (int size_a = 0; A[size_a] != '\0'; size_a++){
		if ((A[size_a] > '9' || A[size_a] < '0') && (A[size_a] !='A')) {
			cout << "Введённого числа не существует в одиннадцатеричной системе счисления\n";
			return 1;
		}
	}
	cout << "Введите число b\n";
	cin >> B;
	for (int size_b = 0; B[size_b] != '\0'; size_b++) {
		if ((B[size_b] > '9' || B[size_b] < '0') && (B[size_b] != 'A')) {
			cout << "Введённого числа не существует в одиннадцатеричной системе счисления\n";
			return 1;
		}
	}
	int size_a = 0;
	for (size_a; A[size_a] != '\0'; size_a++);
	int size_b = 0;
	for (size_b; B[size_b] != '\0'; size_b++);
	if(size_a < size_b)
		for (size_a; size_b - size_a > 0; size_a++) {
			A = "0" + A;
		}
	else if(size_a > size_b)
		for (size_b; size_a - size_b > 0; size_b++) {
			B = "0" + B;
		}
	cout << "\nСумма: ";
	Sum(A,B,size_b);
	cout << "\nРазность: ";
	diff(A, B, size_b);

	return 0;
}