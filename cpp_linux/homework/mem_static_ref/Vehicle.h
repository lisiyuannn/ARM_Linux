#ifndef __VEHICLE_H
#define __VEHICLE_H

class Vehicle
{
private:
    int speed;
    int size;
public:
    Vehicle();
    Vehicle(int, int);
    ~Vehicle();

    void move();
    void setSpeed(int);
    void setSize(int);
    void speedUp();
    void speedDown();
    void carStates();

};

#endif