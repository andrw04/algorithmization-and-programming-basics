// Лабораторная работа 7, задача 7. Выполнена: Сивый А.А.
/*Необходимо разработать программу, которая проверяет, делится
ли введенное пользователем число на заданное простое. Программа не
должна содержать операций умножения, деления, вычитания (в том числе
взятия остатка от деления). Рекомендуется использовать побитовые
операции. Для каждого варианта нужно проверить делимость на 3 простых
числа. Проверять можно по отдельности (сначала получить ответ для
первого, затем для второго, затем для третьего). */
#include <iostream>

using namespace std;

int diff(int x, int y) {
    while (y) {
        int b = (~x) & y;
        x = x ^ y;
        y = b << 1;
    }
    return x;
}
int inc(int i) {
    int m = 1;
    while (i & m) {
        i &= ~m;
        m <<= 1;
    }
    i |= m;
    return i;
}
int d(int n, int d) {
    int q = 0;
    while (n >= d) {
        int i = 0, temp_d = d;
        while (n >= (temp_d << 1)) {
            i = inc(i);
            temp_d <<= 1;
        }
        q |= 1 << i;
        n = diff(n, temp_d);
    }
    return q;
}
int add(int x, int y) {
    while (y) {
        int c = x & y;
        x = x ^ y;
        y = c << 1;
    }
    return x;
}
int mult(int a, int b) {
    int result = 0;
    while (b) {
        if (b & 01) result = add(result, a);
        a <<= 1; b >>= 1;
    }
    return result;
}
int mod(int a, int b) {
    int r = d(a, b);
    return diff(a, mult(r, b));
}

int main() {
    setlocale(LC_ALL, "ru");
    int N, check_d1 = 7, check_d2 = 73, check_d3 = 109;
    cout << "Введите число для проверки: " << endl;
    cin >> N;
    if (mod(N, check_d1))
        cout << N << " не делится на " << check_d1 << endl;
    else
        cout << N << " делится на " << check_d1 << endl;

    if (mod(N, check_d2))
        cout << N << " не делится " << check_d2 << endl;
    else
        cout << N << " делится " << check_d2 << endl;

    if (mod(N, check_d3))
        cout << N << " не делится " << check_d3 << endl;
    else
        cout << N << " делится " << check_d3 << endl;

    return 0;
}

