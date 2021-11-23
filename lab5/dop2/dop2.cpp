// Лабораторная работа 5, дополнительная задача 2. Выполнена: Сивый А.А.
/*Рекурсивная функция задана следующим образом:
f(0,0) = 1;
f(n,k) = f(n - 1, r - 0) + ... f(n - 1, r - (k-1) when [(n>0) and ( 0 <= k < n(k-1) + 1)]
f(n,k) = 0 otherwise
Вычислить значение x = (f(n, 0) + ... + f(n, n(k-1))) mod m , где m = 10^t.
*/
#include <iostream>
#include <cmath>
using namespace std;

long long func(long long k, long long n, long long m)
{
if (!n) return 1 % m;

if (n % 2) return (k * func(k, n - 1, m)) % m;

return func((k * k) % m, n / 2, m);

}
int main()
{
	cout << "Введите k, n и t\n";
	int k, n, t;
	while (!(cin >> k >> n >> t))
	{
		cout << "Введите корректные значения\n";
		cin.clear();
		cin.ignore(10000, '\n');
	}
	int m = pow(10, t);
	int res = func(k, n, m);
	cout << res << endl;
	return 0;
}