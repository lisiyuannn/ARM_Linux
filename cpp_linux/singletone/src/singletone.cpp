#include "singletone.h"

Singletone* Singletone::instance = nullptr;

Singletone::Singletone()
{

}

Singletone* Singletone::getInstance()
{
    if(Singletone::instance == nullptr)
    {
        //如果没有就创建，否则直接返回
        instance = new Singletone();
    }
    return Singletone::instance;
}
