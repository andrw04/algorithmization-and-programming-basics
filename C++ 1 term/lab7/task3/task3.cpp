// Лабораторная работа 7, задача 3. Выполнена: Сивый А.А.
/*Осуществить сложение чисел. Разработать функции для
выполнения операции сложения. Предусмотреть ввод положительных и
отрицательных чисел.
Вариант 9) Найдите сумму двоичных чисел, заданных в естественной форме.
Сложение выполните в дополнительном коде. Ответ выразите в прямом
коде. */
#include <iostream>

using namespace std;

void dop(int N, int M) {
	string A,B;
	if (N > 0)
		A = "00000000000000000000000000000000";
	else if(N <= 0)
		A = "10000000000000000000000000000000";
	int k = abs(N);
	for (int i = 31; i > 0; i--) {
		A[i] = k % 2 + 48;
		k /= 2;
	}
	if (M > 0)
		B = "00000000000000000000000000000000";
	else if (M <= 0)
		B = "10000000000000000000000000000000";
	k = abs(M);
	for (int i = 31; i > 0; i--) {
		B[i] = k % 2 + 48;
		k /= 2;
	}
	if (N < 0) { // дополнительный код
		for (int i = 1; i < 32; i++) {
			if (A[i] == '1')
				A[i] = '0';
			else
				A[i] = '1';
		}
		int cu = 1, temp;
		for (int i = 31; i >= 0; i--) {
			temp = A[i] ^ cu;
			cu = A[i] & cu;
			A[i] = temp;
		}
	}
	if (M < 0) { // дополнительный код
		for (int i = 1; i < 32; i++) {
			if (B[i] == '1')
				B[i] = '0';
			else
				B[i] = '1';
		}
		int cu = 1,temp;
		for (int i = 31; i >= 0; i--) {
			temp = B[i] ^ cu;
			cu = B[i] & cu;
			B[i] = temp;
		}

	}
	int* Ai = new int[32];
	int* Bi = new int[32];
	for (int i = 0; i < 32; i++) {
		Ai[i] = A[i] - 48;
		Bi[i] = B[i] - 48;
	}
	if(N < 0 && M < 0){
		int cu = 0;
		for (int i = 31; i >= 0; i--) {
			Ai[i] += cu;
			if (Ai[i] == 2) {
				Ai[i] = 0;
				cu = 1;
			}
			else
				cu = 0;
			Ai[i] += Bi[i];
			if (Ai[i] == 2) {
				Ai[i] = 0;
				cu = 1;
			}
		}
		int temp;
		for (int i = 1; i < 32; i++) { // инверсия
			if (Ai[i] == 1)
				Ai[i] = 0;
			else
				Ai[i] = 1;
		}
		if (cu == 1) {
			for (int i = 31; i >= 0; i--) {
				Ai[i] += cu;
				if (Ai[i] > 1) {
					Ai[i] = 0;
					cu = 1;
				}
				else
					cu = 0;
			}
		}
	}
	else {
		int cu = 0;
		for (int i = 31; i >= 0; i--) {
			Ai[i] += cu;
			if (Ai[i] == 2) {
				Ai[i] = 0;
				cu = 1;
			}
			else
				cu = 0;
			Ai[i] += Bi[i];
			if (Ai[i] == 2) {
				Ai[i] = 0;
				cu = 1;
			}
		}
	}
	for (int i = 0; i < 32; i++)
		cout << Ai[i];
}



int main() {
	setlocale(LC_ALL, "ru");
	int A, B;
	cout << "Введите число A в естественной форме\n";
	while (!(cin >> A)) {
		cout << "Введите корректное значение\n";
		cin.clear();
		cin.ignore(10000, '\n');
	}
	cout << "Введите число B в естественной форме\n";
	while (!(cin >> B)) {
		cout << "Введите корректное значение\n";
		cin.clear();
		cin.ignore(10000, '\n');
	}
	dop(A,B);
	return 0;
}