#include <iostream>
using namespace std;

extern "C" __declspec(dllexport) void inputArr(int** A, int n, int m) // ���� ��������� ���������� �������
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "������� ������� ������� [" << i << "]" << "[" << j << "]:";
			while (!(cin >> A[i][j]))
			{
				cout << "������� ���������� ��������\n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
		}
	}
}



extern "C" __declspec(dllexport) void outputArr(int** A, int n) // ����� ����������� �������
{
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << "\t";
	}
}



extern "C" __declspec(dllexport) void outputArr1(int** A, int n, int m) // ����� ���������� �������
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << A[i][j] << "\t";
		}
		cout << endl;
	}
}