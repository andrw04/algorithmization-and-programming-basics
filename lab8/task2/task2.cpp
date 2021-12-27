//Лабораторная работа 8, задача 2. Выполнена:Сивый А.А.
/*
Разработать программу в соответствии с вариантом,
реализующую работу с файлами в консольном приложении.
Информация, обрабатываемая программой, должна храниться
в файле, результат работы занести в другой файл и отобразить на экране.
Использовать динамический массив структур, содержащий поля согласно
варианту индивидуального задания. Выделение памяти реализовать через
calloc.
Программа должна содержать необходимые комментарии.
Следует предусмотреть простейший вывод на экран входных и выходных
данных. В каждом варианте задания реализовать следующие функции
для работы со структурой: инициализации данных, добавления,
удаления, корректировки и просмотра записей файла.
 Вариант 9) Для книг, хранящихся в библиотеке, задаются: регистрационный
номер книги, автор, название, год издания, издательство, количество
страниц. Вывести список книг с фамилиями авторов в алфавитном порядке,
изданных после заданного года.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>


using namespace std;


struct factory {
	int RegNumber;
	char Author[10];
	char Name[10];
	int year;
	char published[10];
	int pages;
};

factory* AddStruct(factory* Obj, int& OldSize, int& NewSize) { // выделить память для структуры
	if (OldSize == 0) {
		Obj = (factory*)calloc(NewSize,sizeof(factory));
	}
	else {
		factory* temp_Obj = (factory*)calloc(NewSize,sizeof(factory));
		for (int i = 0; i < OldSize; i++) {
			temp_Obj[i] = Obj[i];
		}
		free(Obj);
		Obj = temp_Obj;
	}
	return Obj;
}

void SetData(factory* Obj, int& OldSize, int &NewSize) { // ввод данный в структуру
	int index;
	cout << "Выберите, как ввести данные(1 - заполнить всю память, 2 - заполнить до определённого элемента\n";
	while (!(cin >> index)) {
		cout << "Введите корректное значение\n";
		cin.clear();
		cin.ignore(10000, '\n');
	}
	if (index == 1) {
		for (int i = OldSize; i < NewSize; i++) {
			printf("Введите регистрационный номер\n");
			rewind(stdin);
			while (!(cin >> Obj[i].RegNumber)) {
				cout << "Введите корректное значение\n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
			printf("Введите автора\n");
			rewind(stdin);
			cin.getline(Obj[i].Author, '\n');
			printf("Введите название книги\n");
			rewind(stdin);
			cin.getline(Obj[i].Name, '\n');
			printf("Введите год издания\n");
			while (!(cin >> Obj[i].year)) {
				cout << "Введите корректное значение\n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
			printf("Введите издательство\n");
			rewind(stdin);
			cin.getline(Obj[i].published, '\n');
			printf("Введите число страниц\n");
			while (!(cin >> Obj[i].pages)) {
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
		while (!(cin >> count)) {
			cout << "Введите корректное значение\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		string value;
		cout << "Введите значение\n";
		while (!(cin >> value)) {
			cout << "Введите корректное значение\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		for (int i = OldSize; i < NewSize; i++) {
			printf("Введите регистрационный номер\n");
			rewind(stdin);
			while (!(cin >> Obj[i].RegNumber)) {
				cout << "Введите корректное значение\n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
			if (count == 1 && (to_string(Obj[i].RegNumber) == value)) {
				break;
			}
			printf("Введите автора\n");
			while (!(cin >> Obj[i].Author)) {
				cout << "Введите корректное значение\n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
			if (count == 2 && (Obj[i].Author == value)) {
				break;
			}
			printf("Введите название книги\n");
			while (!(cin >> Obj[i].Name)) {
				cout << "Введите корректное значение\n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
			if (count == 3 && (Obj[i].Name == value)) {
				break;
			}
			printf("Введите год издания\n");
			while (!(cin >> Obj[i].year)) {
				cout << "Введите корректное значение\n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
			if (count == 4 && (to_string(Obj[i].year) == value)) {
				break;
			}
			printf("Введите издательство\n");
			while (!(cin >> Obj[i].published)) {
				cout << "Введите корректное значение\n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
			if (count == 5 && (Obj[i].published == value)) {
				break;
			}
			printf("Введите число страниц\n");
			while (!(cin >> Obj[i].pages)) {
				cout << "Введите корректное значение\n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
			if (count == 6 && (to_string(Obj[i].pages) == value)) {
				break;
			}
		}
	}
}

void ShowData(factory* Obj, int NewSize) { // вывести структуру
		for (int i = 0; i < NewSize; i++) {
			cout << Obj[i].RegNumber << endl;
			cout << Obj[i].Author << endl;
			cout << Obj[i].Name << endl;
			cout << Obj[i].year << endl;
			cout << Obj[i].published << endl;
			cout << Obj[i].pages << endl;
			cout << "===============\n";
		}
}
void OutputData(factory* Obj, int NewSize) {
	ofstream fout;
	fout.open("task2-output.txt");
	if (!fout.is_open()) {
		cout << "Ошибка открытия файла!\n";
	}
	else {
		for (int i = 0; i < NewSize; i++) {
			fout << Obj[i].RegNumber << endl;
			fout << Obj[i].Author << endl;
			fout << Obj[i].Name << endl;
			fout << Obj[i].year << endl;
			fout << Obj[i].published << endl;
			fout << Obj[i].pages << endl;
		}
	}
	fout.close();
}
void InputData(factory* Obj,int &OldSize, int &NewSize) {
	ifstream fin;
	fin.open("task2-input.txt");
	if (!fin.is_open()) {
		cout << "Ошибка открытия файла!\n";
	}
	else {
		for (int i = OldSize; i < NewSize; i++) {
			fin >> Obj[i].RegNumber;
			fin >> Obj[i].Author;
			fin >> Obj[i].Name;
			fin >> Obj[i].year;
			fin >> Obj[i].published;
			fin >> Obj[i].pages;
		}
	}
	fin.close();
	OldSize = NewSize;
}

void FindData(factory* Obj, int NewSize) { // поиск по элементу
	int N;
	cout << "Выберите элемент для поиска(1 - рег номер, 2 - автор, 3 - название, 4 - год, 5 - издательсво , 6 - страницы)\n";
	while (!(cin >> N)) {
		cout << "Введите корректное значение\n";
		cin.clear();
		cin.ignore(10000, '\n');
	}
	if (N == 1) {
		int k;
		cout << "Введите заначение\n";
		while (!(cin >> k)) {
			cout << "Введите корректное значение\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		for (int i = 0; i < NewSize; i++) {
			if (Obj[i].RegNumber > k) {
				cout << Obj[i].RegNumber << endl;
				cout << Obj[i].Author << endl;
				cout << Obj[i].Name << endl;
				cout << Obj[i].year << endl;
				cout << Obj[i].published << endl;
				cout << Obj[i].pages << endl;
				cout << "===============\n";
			}
		}
	}
	else if (N == 2) {
		string k;
		cout << "Введите значение\n";
		while (!(cin >> k)) {
			cout << "Введите корректное значение\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		for (int i = 0; i < NewSize; i++) {
			if (Obj[i].Author > k) {
				cout << Obj[i].RegNumber << endl;
				cout << Obj[i].Author << endl;
				cout << Obj[i].Name << endl;
				cout << Obj[i].year << endl;
				cout << Obj[i].published << endl;
				cout << Obj[i].pages << endl;
				cout << "===============\n";
			}
		}
	}
	else if (N == 3) {
		string k;
		cout << "Введите значение\n";
		while (!(cin >> k)) {
			cout << "Введите корректное значение\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		for (int i = 0; i < NewSize; i++) {
			if (Obj[i].Name > k) {
				cout << Obj[i].RegNumber << endl;
				cout << Obj[i].Author << endl;
				cout << Obj[i].Name << endl;
				cout << Obj[i].year << endl;
				cout << Obj[i].published << endl;
				cout << Obj[i].pages << endl;
				cout << "===============\n";
			}
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
		for (int i = 0; i < NewSize; i++) {
			if (Obj[i].year > k) {
				cout << Obj[i].RegNumber << endl;
				cout << Obj[i].Author << endl;
				cout << Obj[i].Name << endl;
				cout << Obj[i].year << endl;
				cout << Obj[i].published << endl;
				cout << Obj[i].pages << endl;
				cout << "===============\n";
			}
		}
	}
	else if (N == 5) {
		string k;
		cout << "Введите значение\n";
		while (!(cin >> k)) {
			cout << "Введите корректное значение\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		for (int i = 0; i < NewSize; i++) {
			if (Obj[i].published > k) {
				cout << Obj[i].RegNumber << endl;
				cout << Obj[i].Author << endl;
				cout << Obj[i].Name << endl;
				cout << Obj[i].year << endl;
				cout << Obj[i].published << endl;
				cout << Obj[i].pages << endl;
				cout << "===============\n";
			}
		}
	}
	else if (N == 6) {
		int k;
		cout << "Введите значение\n";
		while (!(cin >> k)){
			cout << "Введите корректное значение\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		for (int i = 0; i < NewSize; i++) {
			if (Obj[i].pages == k) {
				cout << Obj[i].RegNumber << endl;
				cout << Obj[i].Author << endl;
				cout << Obj[i].Name << endl;
				cout << Obj[i].year << endl;
				cout << Obj[i].published << endl;
				cout << Obj[i].pages << endl;
				cout << "===============\n";
			}
		}
	}
}
factory* DeleteStruct(factory* Obj, int& Size) { // удаление/изменение структуры
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
		factory* temp_Obj = (factory*)calloc(Size - 1, 3 * sizeof(string) + 3 * sizeof(int));
		for (int i = 0; i < Size; i++) {
			if (i != m - 1) {
				temp_Obj[j] = Obj[i];
				j++;
			}
			else
				continue;
		}
		Size--;
		free(Obj);
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
		printf("Введите регистрационный номер\n");
		rewind(stdin);
		while (!(cin >> Obj[m].RegNumber)) {
			cout << "Введите корректное значение\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		printf("Введите автора\n");
		while (!(cin >> Obj[m].Author)) {
			cout << "Введите корректное значение\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		printf("Введите название книги\n");
		while (!(cin >> Obj[m].Name)) {
			cout << "Введите корректное значение\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		printf("Введите год издания\n");
		while (!(cin >> Obj[m].year)) {
			cout << "Введите корректное значение\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		printf("Введите издательство\n");
		while (!(cin >> Obj[m].published)) {
			cout << "Введите корректное значение\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		printf("Введите количество страниц\n");
		while (!(cin >> Obj[m].pages)) {
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
	cout << "Выберите, по какому элементу сортировать(1 - рег номер, 2 - автор, 3 - название, 4 - год, 5 - издательсво , 6 - страницы)\n";
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
				if (Obj[i].RegNumber > Obj[i + 1].RegNumber) {
					temp = Obj[i];
					Obj[i] = Obj[i + 1];
					Obj[i + 1] = temp;
					swapped = true;
				}
			}
			else if (index == 2) {
				if (Obj[i].Author[0] > Obj[i + 1].Author[0]) {
					temp = Obj[i];
					Obj[i] = Obj[i + 1];
					Obj[i + 1] = temp;
					swapped = true;
				}
			}
			else if (index == 3) {
				if (Obj[i].Name[0] > Obj[i + 1].Name[0]) {
					temp = Obj[i];
					Obj[i] = Obj[i + 1];
					Obj[i + 1] = temp;
					swapped = true;
				}
			}
			else if (index == 4) {
				if (Obj[i].year > Obj[i + 1].year) {
					temp = Obj[i];
					Obj[i] = Obj[i + 1];
					Obj[i + 1] = temp;
					swapped = true;
				}
			}
			else if (Obj[i].published[0] > Obj[i + 1].published[0]) {
				temp = Obj[i];
				Obj[i] = Obj[i + 1];
				Obj[i + 1] = temp;
				swapped = true;
			}
			else if (Obj[i].pages > Obj[i + 1].pages) {
				temp = Obj[i];
				Obj[i] = Obj[i + 1];
				Obj[i + 1] = temp;
				swapped = true;
			}
		right--;
		for (int i = right; i > left; i--) {
			if (index == 1) {
				if (Obj[i].RegNumber < Obj[i - 1].RegNumber) {
					temp = Obj[i];
					Obj[i] = Obj[i - 1];
					Obj[i - 1] = temp;
					swapped = true;
				}
			}
			else if (index == 2) {
				if (Obj[i].Author[0] < Obj[i - 1].Author[0]) {
					temp = Obj[i];
					Obj[i] = Obj[i - 1];
					Obj[i - 1] = temp;
					swapped = true;
				}
			}
			else if (index == 3) {
				if (Obj[i].Name[0] < Obj[i - 1].Name[0]) {
					temp = Obj[i];
					Obj[i] = Obj[i - 1];
					Obj[i - 1] = temp;
					swapped = true;
				}
			}
			else if (index == 4) {
				if (Obj[i].year < Obj[i - 1].year) {
					temp = Obj[i];
					Obj[i] = Obj[i - 1];
					Obj[i - 1] = temp;
					swapped = true;
				}
			}
			else if (Obj[i].published[0] < Obj[i - 1].published[0]) {
				temp = Obj[i];
				Obj[i] = Obj[i - 1];
				Obj[i - 1] = temp;
				swapped = true;
			}
			else if (Obj[i].pages < Obj[i - 1].pages) {
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
		cout << "Выберите действие(1 - создать массив структур, 2 - показать данные,3 - найти по элементу,4 - сортировать(по возрастанию), 5 - удалить/изменить,\n";
		cout << "6 - записать в файл, 7 - записать из файла, 8 - очистить консоль, 0 - выход\n";
		while (!(cin >> sw) || sw > 8) {
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
			if (factories != 0)
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
		else if (sw == 8) {
			system("cls");
		}
		else if (sw == 6) {
			OutputData(factories, NewSize);
		}
		else if (sw == 7) {
			printf("Введите размер массива\n");
			scanf_s("%d", &NewSize);
			factories = AddStruct(factories, OldSize, NewSize);
			InputData(factories,OldSize, NewSize);
		}
		else if (sw == 0) {
			break;
		}
	} while (true);
	return 0;
}