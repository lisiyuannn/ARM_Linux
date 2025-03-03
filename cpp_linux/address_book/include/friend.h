#ifndef __FRIEND_H
#define __FRIEND_H

#include <string>
using namespace std;

class Friend
{
private:
    std::string name;
    std::string phone;
    std::string address;
public:

    void setName(string name);
    string getName() const;

    void setPhone(string phone);
    string getPhone() const;
    
    void setAddress(string address);
    string getAddress() const;
    
};

#endif