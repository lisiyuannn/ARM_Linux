#include <iostream>
#include "polymorphic.h"
using namespace std;

//定义角色攻击函数
void roleAttack(Role& role)
{
    //调用攻击类成员函数
    role.attack();
}

int main()
{
    //创建战士类和魔法师类实例
    Warrior w{};
    Enchanter e{};

    //分别传入角色攻击函数进行测试
    roleAttack(w);
    roleAttack(e);
    
    return 0;
}