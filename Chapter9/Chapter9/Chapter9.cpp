// Chapter9.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>


class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction(int numerator=0,int denominator=1):m_numerator(numerator),m_denominator(denominator)
	{
		reduce();
	}

	void print()
	{
		std::cout << m_numerator << "/" << m_denominator << "\n";
	}

	friend Fraction operator*(const Fraction &f1, const Fraction &f2)
	{
		int numerator, denominator;
		numerator = f1.m_numerator*f2.m_numerator;
		denominator = f1.m_denominator*f2.m_denominator;
		return Fraction(numerator, denominator);
	}

	friend Fraction operator*(const Fraction &f, int x)
	{
		return Fraction(f.m_numerator*x, f.m_denominator);
	}

	friend Fraction operator*(int x, const Fraction &f)
	{
		return f*x;
	}

	static int gcd(int a, int b) {
		return (b == 0) ? (a > 0 ? a : -a) : gcd(b, a % b);
	}

	void reduce()
	{
		int gcdn = gcd(m_numerator, m_denominator);
		m_numerator = m_numerator / gcdn;
		m_denominator = m_denominator / gcdn;
	}
};


int main()
{
	Fraction f1(2, 5);
	f1.print();

	Fraction f2(3, 8);
	f2.print();

	Fraction f3 = f1 * f2;
	f3.print();

	Fraction f4 = f1 * 2;
	f4.print();

	Fraction f5 = 2 * f2;
	f5.print();

	Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
	f6.print();


    return 0;
}

