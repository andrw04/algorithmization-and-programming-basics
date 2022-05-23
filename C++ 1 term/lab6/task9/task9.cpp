// Лабораторная работа 6, задача 9. Выполнена: Сивый А.А.
/*Сумма чисел в строке
В заданной строке, состоящей из букв, цифр и прочих символов, найдите
сумму всех чисел.*/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;


double numberSum(string line) {

    long double sum = 0, tmp;
    int i = 0, k, ex;
    bool minus, exMinus;

    while (i < line.length()) {
        minus = false;

        if (isdigit(line[i])) {
            if (i != 0 && line[i - 1] == '-')
            {
                tmp = line[i] - '0';

                minus = true;
            }
            else {
                tmp = line[i] - '0';
            }

            ++i;

            while (isdigit(line[i])) {
                tmp = tmp * 10 + (line[i] - '0');

                ++i;
            }

            k = 1;

            if (line[i] == '.' && isdigit(line[i + 1])) {
                ++i;

                while (isdigit(line[i])) {
                    k *= 10;

                    tmp = tmp + (long double)(line[i] - '0') / k;

                    ++i;
                }
            }

            if ((line[i] == 'e' || line[i] == 'E') && (isdigit(line[i + 1]) || (line[i + 1] == '+' && isdigit(line[i + 2])) || (line[i + 1] == '-' && isdigit(line[i + 2])))) {
                exMinus = false;

                ++i;

                if (line[i] == '-') {
                    exMinus = true;
                    ++i;
                }
                else if (line[i] == '+') {
                    ++i;
                }

                ex = line[i] - '0';

                ++i;

                while (isdigit(line[i])) {
                    ex = ex * 10 + (line[i] - '0');
                    ++i;
                }

                if (exMinus) {
                    ex *= -1;
                }

                tmp *= pow(10, ex);
            }

            if (minus) {
                tmp *= -1;
            }


            sum += tmp;
        }

        ++i;
    }

    return sum;
}
int main()
{
    setlocale(LC_ALL, "ru");
    string line;
    cout << "Введите строку\n";
    cin >> line;
    cout << numberSum(line);
    return 0;
}