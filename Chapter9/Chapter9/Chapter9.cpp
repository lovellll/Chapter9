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

	friend std::ostream& operator << (std::ostream &out,const Fraction &fraction);
	
	friend std::istream& operator >> (std::istream &in, Fraction &fraction);


};

std::ostream& operator << (std::ostream &out,const Fraction &fraction)
{
	out << fraction.m_numerator << "/" << fraction.m_denominator;
	return out;
}


std::istream& operator >> (std::istream &in, Fraction &fraction)
{
	in >> fraction.m_numerator;
	char xiegang;
	in >> xiegang;
	in >> fraction.m_denominator;

	fraction.reduce();

	return in;
}

int main()
{
	Fraction f1;
	std::cout << "Enter fraction 1: ";
	std::cin >> f1;

	Fraction f2;
	std::cout << "Enter fraction 2: ";
	std::cin >> f2;

	//Fraction f1(2, 3);
	//Fraction f2(3, 8);

	std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n';

	

    return 0;
}

