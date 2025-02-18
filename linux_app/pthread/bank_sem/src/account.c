#include "account.h"
#include <malloc.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>

//创建账户
Account* account_creat(int id, double balance)
{
    assert(id > 0);
    assert(id <= 999999);
    assert(balance >=0 );

    Account *a = (Account *)malloc(sizeof(Account));
    assert (a != NULL);
    a->id = id;
    a-> balance = balance;

    //pthread_mutex_init(&(a->mutex), NULL);
    sem_init(&a->sem, 0, 1);

    return a;
}

//销毁账户
int account_destroy(Account* a)
{
    assert(a != NULL);
    //pthread_mutex_destroy(&(a->mutex));
    sem_destroy(&a->sem);
    free(a);
}

//取款
double withdraw(Account *a, double amount)
{
    assert(a != NULL);
    assert(amount > 0);
    //pthread_mutex_lock(&(a->mutex));
    sem_wait(&a->sem);
    assert(a->balance >= amount);
    
    double balance = a->balance;

    sleep(1);

    a->balance = balance-amount;
    //pthread_mutex_unlock(&(a->mutex));
    sem_post(&a->sem);
    return balance;
}

//存款
double deposit(Account *a, double amount)
{

}

//查看账户余额
double get_balance(Account *a)
{

}