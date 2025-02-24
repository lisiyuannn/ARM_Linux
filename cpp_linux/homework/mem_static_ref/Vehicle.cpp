#include <iostream>
#include "Vehicle.h"
using namespace std;


Vehicle::Vehicle()
{
    cout << "Vehicle()" << endl;
}

Vehicle::Vehicle(int speed, int size)
{
    if(speed < 0 || speed > 140)
    {
        cout << "speed error" << endl;
        this->speed = 0;
    }
    else this->speed = speed;
    if(size < 100 || size > 200)
    {
        cout << "size error" << endl;
        this->size = 100;
    }else this->size = size;
    cout << "Vehicle(int, int)" << endl;
}

Vehicle::~Vehicle()
{
    cout << "~Vehicle()" << endl;
}

void Vehicle::carStates()
{
    cout << "speed: " << this->speed << ", size: " << this->size << endl;
}

void Vehicle::setSpeed(int speed)
{
    if(speed < 0 || speed > 140)
    {
        cout << "speed error" << endl;
    }
    else
    {
        this->speed = speed;
    }
}

void Vehicle::setSize(int size)
{
    if(size < 100 || size > 200)
    {
        this->size = 100;
    }
    else
    {
        this->size = size;
    }
}

void Vehicle::speedUp()
{
    this->speed += 10;
    if(this->speed > 140)
    {
        this->speed = 140;
    }
    this->move();
}

void Vehicle::speedDown()
{
    if(this->speed < 10)
    {
        this->speed = 0;
    }
    else
    {
        this->speed -= 10;
    }
    this->move();
}

void Vehicle::move()
{
    if(this->speed > 0)
    {
        cout << "car is moving" << endl;
    }
    else
    {
        cout << "shutdown" << endl;
    }
}