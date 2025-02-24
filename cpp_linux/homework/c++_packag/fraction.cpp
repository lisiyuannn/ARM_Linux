#include <iostream>
#include "fraction.h"

Fraction::Fraction()
{
	std::cout << "Fraction()" << std::endl;
}

Fraction::Fraction(int denominator, int numerator)
{
	if(denominator == 0)
	{
		this->denominator = 1;
		std::cout << "Division by Zero Error" << std::endl;
	}
	else
	{
		this->denominator = denominator;
	}
	this->numerator = numerator;
	std::cout << "Fraction(int, int)" << std::endl;
}

Fraction::~Fraction()
{
	std::cout << "~Fraction()" << std::endl;
}

int Fraction::set(int denominator, int numerator)
{
	if(denominator == 0)
	{
		std::cout << "Division by Zero Error" << std::endl;
		return -1;
	}

	this->denominator = denominator;
	this->numerator = numerator;
	return 0;
}

double Fraction::get()
{
	return this->numerator / denominator;
}
