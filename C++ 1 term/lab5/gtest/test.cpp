#include "pch.h"
#include <gtest\gtest.h>
#include <iostream>

int F(int n)
{
	if (n % 10 > 0)
	{
		return n % 10;
	}
	else if (n == 0)
	{
		return 0;
	}
	else
	{
		return F(n / 10);
	}
}



int S(int p, int q)
{
	int S = 0;
	for (int i = p; i <= q; i++)
	{
		S += F(i);
	}
	return S;
}
int fn(int n)
{
	if (n % 2 == 0)
		fn(n / 2);
	else
		return n;
}



int sum(int n)
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
		sum += fn(i);
	return sum;

}
long long func(long long k, long long n, long long m)
{
	if (!n) return 1 % m;

	if (n % 2) return (k * func(k, n - 1, m)) % m;

	return func((k * k) % m, n / 2, m);

}
TEST(dop1,input1)
{
	EXPECT_EQ(46,S(1,10));
	EXPECT_TRUE(true);
}
TEST(dop1,input2)
{
	EXPECT_EQ(48,S(10,20));
	EXPECT_TRUE(true);
}
TEST(dop1,input3)
{
	EXPECT_EQ(52,S(30,40));
	EXPECT_TRUE(true);
}
TEST(dop1,input4)
{
	EXPECT_EQ(NULL,S(-1,-1));
	EXPECT_TRUE(true);
}
TEST(dop2,input1)
{
	EXPECT_EQ(736,func(1234,1234,pow(10,4)));
	EXPECT_TRUE(true);
}
TEST(dop2,input2)
{
	EXPECT_EQ(39087387,func(2323,99999999999,pow(10,8)));
	EXPECT_TRUE(true);
}
TEST(dop2, input3)
{
	EXPECT_EQ(494777344,func(4, 99999, pow(10,9)));
	EXPECT_TRUE(true);
}
TEST(dop2,input4)
{
	EXPECT_EQ(91255296,func(888, 888, pow(10,8)));
	EXPECT_TRUE(true);
}
TEST(dop2, input5)
{
	EXPECT_EQ(0,func(0,0,pow(10,0)));
	EXPECT_TRUE(true);
}
TEST(dop3, input1)
{
	EXPECT_EQ(21,sum(7));
	EXPECT_TRUE(true);
}
TEST(dop3, input2)
{
	EXPECT_EQ(1,sum(1));
	EXPECT_TRUE(true);
}
TEST(dop3, input3)
{
	EXPECT_EQ(201537,sum(777));
	EXPECT_TRUE(true);
}