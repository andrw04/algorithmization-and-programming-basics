// Лабораторная работа 8, задача 1. Выполнена:Сивый А.А.
/*
  Вариант 9) 
  Разработать программу в соответствии с вариантом, реализующую
работу со структурами в консольном приложении.
  Использовать динамический массив структур, содержащий поля согласно
варианту индивидуального задания.
Программа должна содержать необходимые комментарии.
Следует ввод/вывод на экран входных и выходных данных. Для
форматированного ввода-вывода использовать scanf и printf, предусмотреть
некорректный ввод. Обрабатываемая структура должна иметь не менее пяти
полей (элементов) двух и более типов (если в задании указано меньше -
добавить). В каждом варианте задания реализовать следующие функции
для работы со структурой:
1. Функцию формирования динамического одномерного массива структур,
значения которых вводятся с клавиатуры. Предусмотреть возможность
заполнения одного поля структуры, используя известные значения других полей
структуры (придумать самим). С массивом структур работать через оператор new.
При вводе структур необходимо реализовать следующие механизмы:
• ввод заранее заданного количества структур;
• ввод до появления структуры с заданным признаком;
• диалог с пользователем о необходимости продолжать ввод.
2. Функцию просмотра содержимого динамического массива структур.
3. Функцию дополнения уже существующего массива структур новыми
структурами.
4. Функцию поиска и вывода на экран структуры (структур) с заданным
значением элемента.
5. Функции удаления и изменения элемента массива структур с заданным
значением элемента.
6. Функцию упорядочения массива структур по одному из полей
(элементов). Поле для сортировки выбрать самим. Способ указан в скобках.
Вариант 9) Различные цеха завода выпускают продукцию нескольких наименований.
Сведения о выпущенной продукции включают наименование, количество, номер
цеха. Для заданного цеха вывести количество выпущенных изделий (Шейкер
сортировка по убыванию). 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;


struct factory {
	string Name;
	int Amount;
	int Workshop;
	int day;
	int month;
	int year;
	factory() {
		Name = "-";
		Amount = 0;
		Workshop = 0;
		day = 0;
		month = 0;
		year = 0;

	}
};

factory* AddStruct(factory* Obj, int &OldSize, int &NewSize) { // освободить память для структуры
	NewSize = OldSize + NewSize;
	if (OldSize == 0) {
		Obj = new factory[NewSize];
	}
	else {
		factory *temp_Obj = new factory[NewSize];
		for (int i = 0; i < OldSize; i++) {
			temp_Obj[i] = Obj[i];
		}
		delete[] Obj;
		Obj = temp_Obj;
	}
	return Obj;
}

void SetData(factory* Obj, int &OldSize, int NewSize) { // ввод данный в структуру
	int index;
	cout << "Выберите, как ввести данные(1 - заполнить всю память, 2 - заполнить до определённого элемента\n";
	while (!(cin >> index)) {
		cout << "Введите корректное значение\n";
		cin.clear();
		cin.ignore(10000, '\n');
	}
	if (index == 1) {
		for (int i = OldSize; i < NewSize; i++) {
			printf("Введите название изделия\n");
			rewind(stdin);
			while (!(cin >> Obj[i].Name)) {
				cout << "Введите корректное значение\n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
			printf("Введите количество продукции\n");
			while (!(cin >> Obj[i].Amount)) {
				cout << "Введите корректное значение\n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
			printf("Введите номер цеха\n");
			while (!(cin >> Obj[i].Workshop)) {
				cout << "Введите корректное значение\n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
			printf("Введите день производства\n");
			while (!(cin >> Obj[i].day)) {
				cout << "Введите корректное значение\n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
			printf("Введите месяц производства\n");
			while (!(cin >> Obj[i].month) || Obj[i].month > 12) {
				cout << "Введите корректное значение\n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
			printf("Введите год производства\n");
			while (!(cin >> Obj[i].year)) {
				cout << "Введите корректное значение\n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
		}
		OldSize = NewSize;
	}
	else if (index == 2) {
		cout << "Выберите элемент(1 - наименование,2 - количество, 3 - номер цеха, 4 - день, 5 - месяц, 6 - год\n";
		int count;
		while(!(cin >> count)){
			cout << "Введите корректное значение\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		string value;
		cout << "Введите значение\n";
		while(!(cin >> value)){
			cout << "Введите корректное значение\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		for (int i = OldSize; i < NewSize; i++) {
			printf("Введите название изделия\n");
			rewind(stdin);
			while (!(cin >> Obj[i].Name)) {
				cout << "Введите корректное значение\n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
			if (count == 1 && (Obj[i].Name == value)) {
				break;
			}
			printf("Введите количество продукции\n");
			while(!(cin >> Obj[i].Amount)){
				cout << "Введите корректное значение\n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
			if (count == 2 && (to_string(Obj[i].Amount) == value)) {
				break;
			}
			printf("Введите номер цеха\n");
			while(!(cin >> Obj[i].Workshop)){
				cout << "Введите корректное значение\n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
			if (count == 3 && (to_string(Obj[i].Workshop) == value)) {
				break;
			}
			printf("Введите день производства\n");
			while(!(cin >> Obj[i].day)){
				cout << "Введите корректное значение\n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
			if (count == 4 && (to_string(Obj[i].day) == value)) {
				break;
			}
			printf("Введите месяц производства\n");
			while(!(cin >> Obj[i].month)){
				cout << "Введите корректное значение\n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
			if (count == 5 && (to_string(Obj[i].month) == value)) {
				break;
			}
			printf("Введите год производства\n");
			while(!(cin >> Obj[i].year)){
				cout << "Введите корректное значение\n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
			if (count == 6 && (to_string(Obj[i].year) == value)) {
				break;
			}
		}
	}
}

void ShowData(factory* Obj, int NewSize) { // вывести структуру
	cout << "№\t\t" << "Наименование\t" << "Количество\t" << "№ цеха\t\t" << "День\t\t" << "Месяц\t\t" << "Год\n";

	for (int i = 0; i < NewSize; i++) {
		cout << i + 1 << "\t\t" << Obj[i].Name << "\t\t" << Obj[i].Amount << "\t\t" << Obj[i].Workshop << "\t\t" << Obj[i].day << "\t\t" << Obj[i].month << "\t\t" << Obj[i].year << "\n";
	}
}

void FindData(factory* Obj, int NewSize) { // поиск по элементу
	int N;
	cout << "Выберите элемент для поиска(1 - наименованию, 2 - кол-ву продукции, 3 - номеру цеха, 4 - день, 5 - месяц, 6 - год)\n";
	cin >> N;
	if (N == 1) {
		string k;
		cout << "Введите заначение\n";
		while (!(cin >> k)) {
			cout << "Введите корректное значение\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		cout << "№\t\t" << "Наименование\t" << "Количество\t" << "№ цеха\t\t" << "День\t\t" << "Месяц\t\t" << "Год\n";
		for (int i = 0; i < NewSize; i++) {
			if (Obj[i].Name == k)
				cout << i + 1 << "\t\t" << Obj[i].Name << "\t\t" << Obj[i].Amount << "\t\t" << Obj[i].Workshop << "\t\t" << Obj[i].day << "\t\t" << Obj[i].month << "\t\t" << Obj[i].year << "\n";
		}
	}
	else if (N == 2) {
		int k;
		cout << "Введите значение\n";
		while(!(cin >> k)){
			cout << "Введите корректное значение\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		cout << "№\t\t" << "Наименование\t" << "Количество\t" << "№ цеха\t\t" << "День\t\t" << "Месяц\t\t" << "Год\n";
		for (int i = 0; i < NewSize; i++) {
			if (Obj[i].Amount == k)
				cout << i + 1 << "\t\t" << Obj[i].Name << "\t\t" << Obj[i].Amount << "\t\t" << Obj[i].Workshop << "\t\t" << Obj[i].day << "\t\t" << Obj[i].month << "\t\t" << Obj[i].year << "\n";
		}
	}
	else if (N == 3) {
		int k;
		cout << "Введите значение\n";
		while (!(cin >> k)) {
			cout << "Введите корректное значение\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		cout << "№\t\t" << "Наименование\t" << "Количество\t" << "№ цеха\t\t" << "День\t\t" << "Месяц\t\t" << "Год\n";
		for (int i = 0; i < NewSize; i++) {
			if (Obj[i].Workshop == k)
				cout << i + 1 << "\t\t" << Obj[i].Name << "\t\t" << Obj[i].Amount << "\t\t" << Obj[i].Workshop << "\t\t" << Obj[i].day << "\t\t" << Obj[i].month << "\t\t" << Obj[i].year << "\n";
		}
	}
	else if (N == 4) {
		int k;
		cout << "Введите значение\n";
		while (!(cin >> k)) {
			cout << "Введите корректное значение\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		cout << "№\t\t" << "Наименование\t" << "Количество\t" << "№ цеха\t\t" << "День\t\t" << "Месяц\t\t" << "Год\n";
		for (int i = 0; i < NewSize; i++) {
			if (Obj[i].day == k)
				cout << i + 1 << "\t\t" << Obj[i].Name << "\t\t" << Obj[i].Amount << "\t\t" << Obj[i].Workshop << "\t\t" << Obj[i].day << "\t\t" << Obj[i].month << "\t\t" << Obj[i].year << "\n";
		}
	}
	else if (N == 5) {
		int k;
		cout << "Введите значение\n";
		while (!(cin >> k)) {
			cout << "Введите корректное значение\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		cout << "№\t\t" << "Наименование\t\t" << "Количество\t\t" << "№ цеха\t\t" << "День\t\t" << "Месяц\t\t" << "Год\n";
		for (int i = 0; i < NewSize; i++) {
			if (Obj[i].month == k)
				cout << i + 1 << "\t\t" << Obj[i].Name << "\t\t" << Obj[i].Amount << "\t\t" << Obj[i].Workshop << "\t\t" << Obj[i].day << "\t\t" << Obj[i].month << "\t\t" << Obj[i].year << "\n";
		}
	}
	else if (N == 6) {
		int k;
		cout << "Введите значение\n";
		while (!(cin >> k)) {
			cout << "Введите корректное значение\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		cout << "№\t\t" << "Наименование\t\t" << "Количество\t\t" << "№ цеха\t\t" << "День\t\t" << "Месяц\t\t" << "Год\n";
		for (int i = 0; i < NewSize; i++) {
			if (Obj[i].year == k)
				cout << i + 1 << "\t\t" << Obj[i].Name << "\t\t" << Obj[i].Amount << "\t\t" << Obj[i].Workshop << "\t\t" << Obj[i].day << "\t\t" << Obj[i].month << "\t\t" << Obj[i].year << "\n";
		}
	}
}
factory* DeleteStruct(factory* Obj, int &Size) { // удаление/изменение структуры
	int k;
	cout << "1 - удалить структуру, 2 - изменить структуру\n";
	while (!(cin >> k)) {
		cout << "Введите корректное значение\n";
		cin.clear();
		cin.ignore(10000, '\n');
	}
	if (k == 1) {
		int m;
		ShowData(Obj, Size);
		cout << "Выберите элемент, который хотите удалить\n";
		while (!(cin >> m)) {
			cout << "Введите корректное значение\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		int j = 0;
		factory* temp_Obj = new factory[Size - 1];
		for (int i = 0; i < Size; i++) {
			if (i != m - 1){
				temp_Obj[j] = Obj[i];
				j++;
			}
			else
				continue;
		}
		Size--;
		delete[] Obj;
		Obj = temp_Obj;
	}
	else if (k == 2) {
		int m;
		ShowData(Obj, Size);
		cout << "Выберите элемент, который хотите изменить\n";
		while (!(cin >> m)) {
			cout << "Введите корректное значение\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		m--;
		printf("Введите название изделия\n");
		rewind(stdin);
		while (!(cin >> Obj[m].Name)) {
			cout << "Введите корректное значение\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		printf("Введите количество продукции\n");
		while (!(cin >> Obj[m].Amount)) {
			cout << "Введите корректное значение\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		printf("Введите номер цеха\n");
		while (!(cin >> Obj[m].Workshop)) {
			cout << "Введите корректное значение\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		printf("Введите день производства\n");
		while (!(cin >> Obj[m].day)) {
			cout << "Введите корректное значение\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		printf("Введите месяц производства\n");
		while (!(cin >> Obj[m].month)) {
			cout << "Введите корректное значение\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		printf("Введите год производства\n");
		while (!(cin >> Obj[m].year)) {
			cout << "Введите корректное значение\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}
	return Obj;
} 

void ShakerSort(factory* Obj, int size) { // сортирово4ка
	int left = 0, right = size - 1;
	bool swapped = true;
	cout << "Выберите, по какому элементу сортировать(1 - наименование, 2 - кол-во продукции, 3 - номер цеха, 4 - день, 5 - месяц, 6 - год\n";
	int index;
	while (!(cin >> index) || index > 6) {
		cout << "Введите корректное значение\n";
		cin.clear();
		cin.ignore(10000, '\n');
	}
	while ((left < right) && swapped) {
		swapped = false;
		factory temp;
		for (int i = left; i < right; i++)
			if (index == 1) {
				if (Obj[i].Name[0] < Obj[i + 1].Name[0]) {
					temp = Obj[i];
					Obj[i] = Obj[i + 1];
					Obj[i + 1] = temp;
					swapped = true;
				}
			}
			else if (index == 2) {
				if (Obj[i].Amount < Obj[i + 1].Amount) {
					temp = Obj[i];
					Obj[i] = Obj[i + 1];
					Obj[i + 1] = temp;
					swapped = true;
				}
			}
			else if (index == 3) {
				if (Obj[i].Workshop < Obj[i + 1].Workshop) {
					temp = Obj[i];
					Obj[i] = Obj[i + 1];
					Obj[i + 1] = temp;
					swapped = true;
				}
			}
			else if (index == 4) {
				if (Obj[i].day < Obj[i + 1].day) {
					temp = Obj[i];
					Obj[i] = Obj[i + 1];
					Obj[i + 1] = temp;
					swapped = true;
				}
			}
			else if (Obj[i].month < Obj[i + 1].month) {
				temp = Obj[i];
				Obj[i] = Obj[i + 1];
				Obj[i + 1] = temp;
				swapped = true;
			}
			else if (Obj[i].year < Obj[i + 1].year) {
				temp = Obj[i];
				Obj[i] = Obj[i + 1];
				Obj[i + 1] = temp;
				swapped = true;
			}
		right--;
		for (int i = right; i > left; i--) {
			if (index == 1) {
				if (Obj[i].Name[0] > Obj[i-1].Name[0]) {
					temp = Obj[i];
					Obj[i] = Obj[i - 1];
					Obj[i - 1] = temp;
					swapped = true;
				}
			}
			else if (index == 2) {
				if (Obj[i].Amount > Obj[i - 1].Amount) {
					temp = Obj[i];
					Obj[i] = Obj[i - 1];
					Obj[i - 1] = temp;
					swapped = true;
				}
			}
			else if (index == 3) {
				if (Obj[i].Workshop > Obj[i - 1].Workshop) {
					temp = Obj[i];
					Obj[i] = Obj[i - 1];
					Obj[i - 1] = temp;
					swapped = true;
				}
			}
			else if (index == 4) {
				if (Obj[i].day > Obj[i - 1].day) {
					temp = Obj[i];
					Obj[i] = Obj[i - 1];
					Obj[i - 1] = temp;
					swapped = true;
				}
			}
			else if (Obj[i].month > Obj[i - 1].month) {
				temp = Obj[i];
				Obj[i] = Obj[i - 1];
				Obj[i - 1] = temp;
				swapped = true;
			}
			else if (Obj[i].year > Obj[i - 1].year) {
				temp = Obj[i];
				Obj[i] = Obj[i - 1];
				Obj[i - 1] = temp;
				swapped = true;
			}
		}
		left++;
	}
}
int main() {
	setlocale(LC_ALL, "ru");
	factory* factories = 0;
	int OldSize = 0;
	int NewSize = 0;
	do {
		int sw;
		cout << "Выберите действие(1 - создать массив структур, 2 - показать данные,3 - найти по элементу,4 - сортировать(по убыванию), 5 - удалить/изменить, 6 - очистить консоль, 0 - выход\n";
		while (!(cin >> sw) || sw > 6) {
			cout << "Введите корректное значение\n";
			cin.clear();
			cin.ignore(1000, '\n');
		}
		if (sw == 1) {
			printf("Введите размер массива\n");
			scanf_s("%d", &NewSize);
			factories = AddStruct(factories, OldSize, NewSize);
			SetData(factories, OldSize, NewSize);
			OldSize = NewSize;
		}
		else if (sw == 2) {
			ShowData(factories, NewSize);
		}
		else if (sw == 3) {
			if(factories != 0)
				FindData(factories, NewSize);
		}
		else if (sw == 4) {
			if (factories != 0)
				ShakerSort(factories, NewSize);
		}
		else if (sw == 5) {
			if (factories != 0)
				factories = DeleteStruct(factories, NewSize);
		}
		else if (sw == 6) {
			system("cls");
		}
		else if (sw == 0) {
			break;
		}
	} while (true);
	return 0;
}