#ifndef __CALC_H
#define __CALC_H

class Operation
{
protected:
	double numA;
	double numB;
public:
	Operation();
	Operation(double, double);
	virtual ~Operation();

	void setNumA(double);
	void setNumB(double);
	virtual double getResult() = 0;
};

class Add: public Operation
{
public:
	Add();
	Add(double, double);
	~Add();
	virtual double getResult() override;
};

class Sub: public Operation
{
public:
	Sub();
	Sub(double, double);
	~Sub();
	virtual double getResult() override;
};

class Mult: public Operation
{
public:
	Mult();
	Mult(double, double);
	~Mult();
	virtual double getResult() override;
};

class Div: public Operation
{
public:
	Div();
	Div(double, double);
	~Div();
	virtual double getResult() override;
};

class Factory
{
public:
	Operation* createOper(char);
};

#endif
