#include <string>
#include "friend.h"
using namespace std;

void Friend::setName(string name)
{
    this->name = name;
}
string Friend::getName() const
{
    return this->name;
}

void Friend::setPhone(string phone)
{
    this->phone = phone;
}
string Friend::getPhone() const
{
    return this->phone;
}

void Friend::setAddress(string address)
{
    this->address = address;
}
string Friend::getAddress() const
{
    return this->address;
}