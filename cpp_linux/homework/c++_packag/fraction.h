#ifndef __FRACTION_H
#define __FRACTION_H

class Fraction
{
private:
	int denominator;
	int numerator;

public:
	Fraction();
	Fraction(int, int);
	~Fraction();

	int set(int, int);
	double get();

};

#endif
