#include "pch.h"
#include <gtest/gtest.h>
#include <iostream>
#include <string>

using namespace std;

string Array(int Sum)
{
	int k = Sum;
	int rank = 1;
	do
	{
		k = k / 10;
		rank++;
	} while (k >= 10);
	string arr;
	for (int i = rank - 1; i >= 0; i--) // перевод в одиннадцатеричную
	{
		k = Sum % 11;
		if (k == 10)
			arr += 'A';
		else
			arr += k + 48;
		Sum = Sum / 11;
	}
	char tmp;
	for (int i = 0; i < rank / 2; i++) {
		tmp = arr[i];
		arr[i] = arr[rank - i - 1];
		arr[rank - i - 1] = tmp;
	}
	return arr;
}
string bin(int N) {
	string num;
	if (N > 0)
		num = "00000000000000000000000000000000";
	else if (N <= 0)
		num = "10000000000000000000000000000000";
	for (int i = 31; i > 0; i--) {
		num[i] = abs(N) % 2 + 48;
		N /= 2;
	}
	return num;
}
int S(int x)
{
	if (x < 10)
		return x;
	else if (x >= 10)
		return x % 10 + S(x / 10);
}

TEST(Task1, Input1) {
	string a = "23";
  EXPECT_EQ(a, Array(25));
  EXPECT_TRUE(true);
}
TEST(Task1, Input2) {
	string a = "25";
	EXPECT_EQ(a, Array(27));
	EXPECT_TRUE(true);
}
TEST(Task1, Input3) {
	string a = "01";
	EXPECT_EQ(a, Array(1));
	EXPECT_TRUE(true);
}
TEST(Task1, Input4) {
	string a = "0A";
	EXPECT_EQ(a, Array(10));
	EXPECT_TRUE(true);
}
TEST(Task1, Input5) {
	string a = "11";
	EXPECT_EQ(a, Array(12));
	EXPECT_TRUE(true);
}
TEST(Task1, Input6) {
	string a = "102";
	EXPECT_EQ(a, Array(123));
	EXPECT_TRUE(true);
}
TEST(Task1, Input7) {
	string a = "275160";
	EXPECT_EQ(a, Array(431431));
	EXPECT_TRUE(true);
}
TEST(Task1, Input8) {
	string a = "192";
	EXPECT_EQ(a, Array(222));
	EXPECT_TRUE(true);
}
TEST(Task1, Input9) {
	string a = "556";
	EXPECT_EQ(a, Array(666));
	EXPECT_TRUE(true);
}
TEST(Task1, Input10) {
	string a = "374";
	EXPECT_EQ(a, Array(444));
	EXPECT_TRUE(true);
}
TEST(Task2, Input1) {
	string a = "00000000000000000000001000101011";
	EXPECT_EQ(a, bin(555));
	EXPECT_TRUE(true);
}
TEST(Task2, Input2) {
	string a = "10000000000000000000001000101011";
	EXPECT_EQ(a, bin(-555));
	EXPECT_TRUE(true);
}
TEST(Task2, Input3) {
	string a = "00000000000000000000000000000010";
	EXPECT_EQ(a, bin(2));
	EXPECT_TRUE(true);
}
TEST(Task2, Input4) {
	string a = "10000000000000000000000000000010";
	EXPECT_EQ(a, bin(-2));
	EXPECT_TRUE(true);
}
TEST(Task2, Input5) {
	string a = "00000000000000000010011100010000";
	EXPECT_EQ(a, bin(10000));
	EXPECT_TRUE(true);
}
TEST(Task2, Input6) {
	string a = "10000000000000000010011100010000";
	EXPECT_EQ(a, bin(-10000));
	EXPECT_TRUE(true);
}
TEST(Task2, Input7) {
	string a = "00000111010101101011010110110011";
	EXPECT_EQ(a, bin(123123123));
	EXPECT_TRUE(true);
}
TEST(Task2, Input8) {
	string a = "10000111010101101011010110110011";
	EXPECT_EQ(a, bin(-123123123));
	EXPECT_TRUE(true);
}
TEST(Task2, Input9) {
	string a = "01110111001101011001001111111111";
	EXPECT_EQ(a, bin(1999999999));
	EXPECT_TRUE(true);
}
TEST(Task2, Input10) {
	string a = "11110111001101011001001111111111";
	EXPECT_EQ(a, bin(-1999999999));
	EXPECT_TRUE(true);
}
TEST(Task6, Input1) {
	EXPECT_EQ(1 , S(10));
	EXPECT_TRUE(true);
}
TEST(Task6, Input2) {
	EXPECT_EQ(2, S(20));
	EXPECT_TRUE(true);
}
TEST(Task6, Input3) {
	EXPECT_EQ(6, S(42));
	EXPECT_TRUE(true);
}
TEST(Task6, Input4) {
	EXPECT_EQ(6, S(123));
	EXPECT_TRUE(true);
}
TEST(Task6, Input5) {
	EXPECT_EQ(21, S(777));
	EXPECT_TRUE(true);
}
TEST(Task6, Input6) {
	EXPECT_EQ(12, S(228));
	EXPECT_TRUE(true);
}
TEST(Task6, Input7) {
	EXPECT_EQ(1, S(10000));
	EXPECT_TRUE(true);
}
TEST(Task6, Input8) {
	EXPECT_EQ(27, S(999));
	EXPECT_TRUE(true);
}
TEST(Task6, Input9) {
	EXPECT_EQ(27, S(999));
	EXPECT_TRUE(true);
}
TEST(Task6, Input10) {
	EXPECT_EQ(2, S(101));
	EXPECT_TRUE(true);
}
TEST(Task6, Input11) {
	EXPECT_EQ(8, S(2222));
	EXPECT_TRUE(true);
}
TEST(Task6, Input12) {
	EXPECT_EQ(15, S(12345));
	EXPECT_TRUE(true);
}
TEST(Task6, Input13) {
	EXPECT_EQ(15, S(54321));
	EXPECT_TRUE(true);
}
TEST(Task6, Input14) {
	EXPECT_EQ(0, S(000));
	EXPECT_TRUE(true);
}
TEST(Task6, Input15) {
	EXPECT_EQ(1, S(0001));
	EXPECT_TRUE(true);
}

