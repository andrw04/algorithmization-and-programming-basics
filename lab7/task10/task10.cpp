// Лабораторная работа 7, задача 10. Выполнена: Сивый А.А.
/*Патриций решил устроить праздник и для этого приготовил 240
бочек вина. Однако к нему пробрался недоброжелатель, который подсыпал
яд в одну из бочек. Недоброжелателя тут же поймали, дальнейшая его судьба
неизвестна. Про яд известно, что человек, который его выпил, умирает в
течение 24 часов. До праздника осталось два дня, то есть 48 часов. У
патриция есть пять рабов, которыми он готов пожертвовать, чтобы узнать, в
какой именно бочке яд. Каким образом можно это узнать?*/
#include <iostream>
#include <string>

using namespace std;

string reverse(string str, int size) {
    if (size == -1)
        return "";
    else
    {
        char a;
        a = str[size];
        return a + reverse(str, size - 1);
    }
}

string system3(int k) {
    string str3;
    for (int i = 4; i >= 0; i--) {
        int a = (k % 3);
        if (a == 0) str3 += '0';
        if (a == 1) str3 += '1';
        if (a == 2) str3 += '2';
        k /= 3;
    }
    str3 = reverse(str3, 5);
    return str3;
}

int main() {
    setlocale(LC_ALL, "ru");
    string barrels[240];
    for (int i = 1; i < 240; i++) {
        barrels[i] = system3(i);
    }
    int s1 = 0, s12 = 0, s123= 0, s1234 = 0,left = 0,tmp = 0;
    for (int i = 1; i < 240; i++) {
        for (int j = 0; j < 5; j++)
            if (barrels[i][j] == '0')
                tmp++;
        if (tmp == 1)
            s1++;
        if (tmp == 2)
            s12++;
        if (tmp == 3)
            s123++;
        if (tmp == 4)
            s1234++;
        tmp = 0;
    }
    int left_slaves = 0;
    cout << "Введите количество умерших рабов: " << endl;
    cin >> left_slaves;
    switch (left_slaves) {
    case 0:
        cout << "Одна из " << left / 5 << " бочек отравлена";
        break;
    case 1:
        cout << "Одна из " << s1 / 4 << " бочек отравлена";
        break;
    case 2:
        cout << "Одна из " << s12 / 3 << " бочек отравлена";
        break;
    case 3:
        cout << "Одна из " << s123 / 2 << " бочек отравлена";
        break;
    case 4:
        cout << "Одна из " << s1234 << "бочек отравлена";
        break;
    default:
        cout << "Одновременно все не могли умереть";
    }
    return 0;
}