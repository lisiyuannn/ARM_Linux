#ifndef __ACCOUNT_H
#define __ACCOUNT_H

#include <pthread.h>
#include <semaphore.h>

typedef struct
{
    int id;
    double balance;
    //pthread_mutex_t mutex;
    sem_t sem;
}Account;

//创建账户
extern Account* account_creat(int id, double balance);

//销毁账户
extern int account_destroy(Account* a);

//取款
extern double withdraw(Account *a, double amount);

//存款
extern double deposit(Account *a, double amount);

//查看账户余额
extern double get_balance(Account *a);

#endif
