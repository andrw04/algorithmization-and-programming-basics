#include "pch.h"
#include <gtest/gtest.h>
#include <iostream>
#include <string>

using namespace std;

int proverka(string s, string t)
{
	bool index = false;
	string tmp = t;
	for (int i = 0; i < size(t); i++)
	{
		tmp[i] = 0;
	}

	for (int i = 0; i < size(s); i++)
	{
		if (s[i] == t[0])
		{
			int j = 1;
			int metka = i;
			tmp[0] = t[0];
			while (j < size(t) && metka < size(s))
			{
				if (s[metka + 1] == t[j])
				{
					metka++;
					tmp[j] = t[j];
					j++;
				}
				else
					break;
			}
			while (j < size(t) && metka > 0)
			{
				if (s[metka - 1] == t[j])
				{
					metka--;
					tmp[j] = t[j];
					j++;
				}
				else
					break;
			}
			if (tmp == t)
				index = true;
			else
				for (int j = 0; j < size(t); j++)
					tmp[i] = 0;

		}
	}
	if (index)
		return 1;
	else
		return 0;
}



long int f(int number) // factorial
{
	if (number == 0)
		return 1;
	else if (number == 1)
		return 1;
	else
		return number * f(number - 1);

}


int perestanovka(char* str, int size)
{
	int* pov = new int[size];
	bool index;
	int number = 0;
	int answer;
	for (int i = 0; i < size; i++)
	{
		index = false;
		number = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			if (str[i] == str[j])
				index = true;
		}
		if (index)
		{
			pov[i] = 0;
			continue;
		}
		for (int j = i; j < size; j++)
		{
			if (str[i] == str[j])
				number++;
		}
		pov[i] = number;
	}
	answer = f(size);
	for (int i = 0; i < size; i++)
	{
		answer /= f(pov[i]);
	}
	delete[] pov;
	return answer;
}





int max(string str)
{
	for (int k = 0; k < size(str); k++)
	{
		for (int i = 0; i < size(str) / 2; i++)
		{
			if (size(str) >= i + 1 + k)
			{
				if (str[i] != str[size(str) - i - 1 - k])
				{
					return size(str) - i - k;
				}
			}
		}
	}
	return -1;
}



int f(char* s1, char* s2, int L, int m)
{
	int same = 0;
	int sum1 = 0;
	int sum2 = 0;
	int k = 0;
	int difference;
	for (int i = 0; i < strlen(s1); i++)
	{
		if (s1[i] == s2[0])
		{
			for (int j = 0; j < strlen(s1) - i; j++)
			{
				if (s1[i + j] == s2[j])
				{
					k++;
					if (k >= same);
					same = k;
				}
				else
				{
					k = 0;
					same = 0;
					break;
				}
			}
		}
	}
	difference = L - strlen(s1) - (strlen(s2) - same);
	if (difference < 0)
		sum1 = 0;
	else if (difference == 0)
		sum1 = pow(26, 0);
	else
		sum1 = pow(26, L - strlen(s1) - (strlen(s2) - same));
	k = 0, same = 0;
	for (int i = 0; i < strlen(s2); i++)
	{
		if (s2[i] == s1[0])
		{
			for (int j = 0; j < strlen(s2) - i; j++)
			{
				if (s2[i + j] == s1[j])
				{
					k++;
					if (k >= same);
					same = k;
				}
				else
				{
					k = 0;
					same = 0;
					break;
				}
			}
		}
	}
	difference = L - strlen(s1) - (strlen(s2) - same);
	if (difference < 0)
		sum2 = 0;
	else if (difference == 0)
		sum2 = pow(26, 0);
	else
		sum2 = pow(26, L - strlen(s1) - (strlen(s2) - same));
	return (sum1 + sum2) % m;
}



void reforma(string& str)
{
	string cqwx = "CQWX";
	for (int i = 0; i < size(str); i++)
	{
		for (int j = 0; j < size(cqwx); j++)
			if (str[i] == cqwx[j])
				str.erase(i, 1);
	}
	for (int i = 0; i < size(str); i++)
	{
		if (str[i] == 'c' && (str[i + 1] == 'e' || str[i + 1] == 'i' || str[i + 1] == 'y') && i < size(str) - 1)
		{
			str[i] = 's';
		}
		if (str[i] == 'q' && str[i + 1] == 'u' && i < size(str) - 1)
		{
			str.replace(i, 2, "kv");
		}
		if (str[i] == 'c')
		{
			str[i] = 'k';
		}
		if (str[i] == 'w')
		{
			str[i] = 'v';
		}
		if (str[i] == 'q')
		{
			str[i] = 'k';
		}
		if (str[i] == 'x')
		{
			str.replace(i, 1, "k");
			str.insert(i + 1, "s", 0, 2);
		}
		if (str[i] == 'p' && str[i + 1] == 'h' && i < size(str) - 1)
		{
			str.replace(i, 1, "f");
			str.erase(i + 1, 1);
		}
		if (str[i] == 'P' && str[i + 1] == 'h' && i < size(str) - 1)
		{
			str.replace(i, 1, "F");
			str.erase(i + 1, 1);
		}
		if (str[i] == 'o' && str[i + 1] == 'o' && i < size(str) - 1)
		{
			str.replace(i, 1, "u");
			str.erase(i + 1, 1);
		}
		if (str[i] == 'O' && str[i + 1] == 'o' && i < size(str) - 1)
		{
			str.replace(i, 1, "U");
			str.erase(i + 1, 1);
		}
		if (str[i] == 'e' && str[i + 1] == 'e' && i < size(str) - 1)
		{
			str.replace(i, 1, "i");
			str.erase(i + 1, 1);
		}
		if (str[i] == 'E' && str[i + 1] == 'e' && i < size(str) - 1)
		{
			str.replace(i, 1, "I");
			str.erase(i + 1, 1);
		}
		if (str[i] == 't' && str[i + 1] == 'h' && i < size(str) - 1)
		{
			str.replace(i, 1, "z");
			str.erase(i + 1, 1);
		}
		if (str[i] == 'T' && str[i + 1] == 'h' && i < size(str) - 1)
		{
			str.replace(i, 1, "Z");
			str.erase(i + 1, 1);
		}
		if (str[i] == str[i + 1] && i < size(str) - 1)
		{
			str.erase(i + 1, 1);
		}
		if (str[i] == 'y' && str[i + 1] == 'o' && str[i + 2] == 'u' && i < size(str) - 2)
		{
			str.erase(i, 2);
		}
		if (str[i] == 'Y' && str[i + 1] == 'o' && str[i + 2] == 'u' && i < size(str) - 2)
		{
			str.erase(i, 2);
			str.replace(i, 1, "Y");
		}
	}
}



double numberSum(std::string line) {

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



bool check_polindrom(char* word)
{
	int len = 0;
	for (int i = 0; i < 80; i++)
	{
		if ((word[i] <= 'Z' && word[i] >= 'A') || (word[i] <= 'z' && word[i] >= 'a'))
			len++;
	}
	for (int i = 0; i < len / 2; ++i)
	{
		if (word[i] != word[len - i - 1])
		{
			return false;
		}
	}
	return true;
}





TEST(task8, input1) {
	string s = "abcdef";
	string t = "cdedcb";
	EXPECT_EQ(proverka(s, t), 1);
	EXPECT_TRUE(true);
}
TEST(task8, input2) {
	string s = "aaa";
	string t = "aaaaa";
	EXPECT_EQ(proverka(s, t), 1);
	EXPECT_TRUE(true);
}
TEST(task8, input3) {
	string s = "aab";
	string t = "baaa";
	EXPECT_EQ(proverka(s, t), 0);
	EXPECT_TRUE(true);
}
TEST(task8, input4) {
	string s = "ab";
	string t = "b";
	EXPECT_EQ(proverka(s, t), 1);
	EXPECT_TRUE(true);
}
TEST(task8, input5) {
	string s = "abcdef";
	string t = "abcdef";
	EXPECT_EQ(proverka(s, t), 1);
	EXPECT_TRUE(true);
}
TEST(task8, input6) {
	string s = "ba";
	string t = "baa";
	EXPECT_EQ(proverka(s, t), 0);
	EXPECT_TRUE(true);
}
TEST(task7, input1) {
	string s = "aba";
	EXPECT_EQ(max(s), 2);
	EXPECT_TRUE(true);
}
TEST(task7, input2) {
	string s = "abba";
	EXPECT_EQ(max(s), 3);
	EXPECT_TRUE(true);
}
TEST(task7, input3) {
	string s = "abbba";
	EXPECT_EQ(max(s), 4);
	EXPECT_TRUE(true);
}
TEST(task7, input4) {
	string s = "aaa";
	EXPECT_EQ(max(s), -1);
	EXPECT_TRUE(true);
}
TEST(task7, input5) {
	string s = "fff";
	EXPECT_EQ(max(s), -1);
	EXPECT_TRUE(true);
}
TEST(task7, input6) {
	string s = "ffffffff";
	EXPECT_EQ(max(s), -1);
	EXPECT_TRUE(true);
}
TEST(task7, input7) {
	string s = "fhods";
	EXPECT_EQ(max(s), 5);
	EXPECT_TRUE(true);
}
TEST(task7, input8) {
	string s = "acbd";
	EXPECT_EQ(max(s), 4);
	EXPECT_TRUE(true);
}
TEST(task7, input9) {
	string s = "kkkkk k";
	EXPECT_EQ(max(s), 6);
	EXPECT_TRUE(true);
}
TEST(task7, input10) {
	string s = "	";
	EXPECT_EQ(max(s), -1);
	EXPECT_TRUE(true);
}
TEST(task6, input1) {
	char* str = "SOLO";
	EXPECT_EQ(perestanovka(str,4), 12);
	EXPECT_TRUE(true);
}
TEST(task6, input2) {
	char* str = "proga";
	EXPECT_EQ(perestanovka(str, 5), 120);
	EXPECT_TRUE(true);
}
TEST(task6, input3) {
	char* str = "ffff";
	EXPECT_EQ(perestanovka(str, 4), 1);
	EXPECT_TRUE(true);
}
TEST(task6, input4) {
	char* str = "ffffff";
	EXPECT_EQ(perestanovka(str, 6), 1);
	EXPECT_TRUE(true);
}
TEST(task6, input5) {
	char* str = "hello";
	EXPECT_EQ(perestanovka(str, 5), 60);
	EXPECT_TRUE(true);
}
TEST(task5, input1) {
	char* s1 = "cup";
	char* s2 = "russia";
	EXPECT_EQ(f(s1,s2,14,1000), 752);
	EXPECT_TRUE(true);
}
TEST(task5, input2) {
	char* s1 = "russian";
	char* s2 = "codecup";
	EXPECT_EQ(f(s1, s2, 7, 123), 0);
	EXPECT_TRUE(true);
}
TEST(task5, input3) {
	char* s1 = "codec";
	char* s2 = "decup";
	EXPECT_EQ(f(s1, s2, 7, 15), 1);
	EXPECT_TRUE(true);
}TEST(task4, input1) {
	string str = "Too svift for Theex, too quick for Gallow, Too strong for young Prince Joseph to follow.";
	string answ = "Tu svift for Ziks, tu kvik for Galov, Tu strong for ung Prinse Josef to folov.";
	reforma(str);
	EXPECT_EQ(str,answ);
	EXPECT_TRUE(true);
}
TEST(task4, input2) {
	string str = "Apple";
	string answ = "Aple";
	reforma(str);
	EXPECT_EQ(str, answ);
	EXPECT_TRUE(true);
}
TEST(task4, input3) {
	string str = "suffer";
	string answ = "sufer";
	reforma(str);
	EXPECT_EQ(str, answ);
	EXPECT_TRUE(true);
}
TEST(task4, inpu2) {
	string str = "Appear";
	string answ = "Apear";
	reforma(str);
	EXPECT_EQ(str, answ);
	EXPECT_TRUE(true);
}
TEST(task9, input1) {
	string str = "123abc123";
	int a = numberSum(str);
	EXPECT_EQ(a, 246);
	EXPECT_TRUE(true);
}
TEST(task9, input2) {
	string str = "111";
	int a = numberSum(str);
	EXPECT_EQ(a, 111);
	EXPECT_TRUE(true); 
}
TEST(task9, input3) {
	string str = "123abc";
	int a = numberSum(str);
	EXPECT_EQ(a, 123);
	EXPECT_TRUE(true);
}
TEST(task9, input4) {
	string str = "abc123";
	int a = numberSum(str);
	EXPECT_EQ(a, 123);
	EXPECT_TRUE(true);
}
TEST(task9, input5) {
	string str = "123 123";
	int a = numberSum(str);
	EXPECT_EQ(a, 246);
	EXPECT_TRUE(true);
}