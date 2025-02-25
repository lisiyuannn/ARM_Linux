#ifndef __POLYMORPHIC_H
#define __POLYMORPHIC_H

class Role
{
public:
    virtual void attack() = 0;
};

class Warrior: public Role
{
public:
    virtual void attack() override;
};

class Enchanter: public Role
{
public:
    virtual void attack() override;
};

#endif