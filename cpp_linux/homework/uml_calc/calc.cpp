#include <iostream>
#include "calc.h"
using namespace std;

Operation::Operation()
{
	cout << "Operation()" << endl;
}

Operation::Operation(double a, double b)
	:numA{a}, numB{b}
{
	cout << "Operation(double, double)" << endl;
}

Operation::~Operation()
{
	cout << "~Operation()" << endl;
}

void Operation::setNumA(double a)
{
		this->numA = a;
}
void Operation::setNumB(double b)
{
		this->numB = b;
}

Add::Add()
{
	cout << "Add()" << endl;
}

Add::Add(double a, double b)
	:Operation(a, b)
{
	cout << "Add(double, double)" << endl;
}

Add::~Add()
{
	cout << "~Add()" << endl;
}

double Add::getResult()
{
	return this->numA + this->numB;
}

Sub::Sub()
{
	cout << "Sub()" << endl;
}

Sub::Sub(double a, double b)
	:Operation(a, b)
{
	cout << "Sub(double, double)" << endl;
}

Sub::~Sub()
{
	cout << "~Sub()" << endl;
}

double Sub::getResult()
{
	return this->numA - this->numB;
}

Mult::Mult()
{
	cout << "Mult()" << endl;
}

Mult::Mult(double a, double b)
	:Operation(a, b)
{
	cout << "Mult(double, double)" << endl;
}

Mult::~Mult()
{
	cout << "~Mult()" << endl;
}

double Mult::getResult()
{
	return this->numA * this->numB;
}

Div::Div()
{
	cout << "Div()" << endl;
}

Div::Div(double a, double b)
	:Operation(a, b)
{
	cout << "Div(double, double)" << endl;
}

Div::~Div()
{
	cout << "~Div()" << endl;
}

double Div::getResult()
{
	if(this->numB == 0) return numA;
	return this->numA / this->numB;
}

Operation* Factory::createOper(char op)
{
	Operation* oper = nullptr;
	if(op == '+')
	{
		oper = new Add; 
	}
	else if(op == '-')
	{
		oper = new Sub; 
	}
	else if(op == '/')
	{
		oper = new Div; 
	}
	else if(op == '*')
	{
		oper = new Mult; 
	}
	else
	{
		cout << "operator error, please input again" << endl;
	}
	return oper;
}
