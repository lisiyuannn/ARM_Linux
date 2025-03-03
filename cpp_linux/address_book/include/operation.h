#ifndef __OPERATOR_H
#define __OPERATOR_H

#include <map>
#include "friend.h"


//通信录文件存储地址
#define FRIEND_FILE "../res/friend.txt"

/**
 * brief: 将整本通信录写入文件
 * arg: 通信录map
 * return: none
 * note: 写入失败会抛出异常
 */
void saveContacts(const map<string, Friend>&);

/**
 * brief: 从文件中读取整个通信录到内存
 * arg: 通信录map
 * return: none
 * note: 读取失败会抛出异常
 */
void loadContacts(map<string, Friend>&);

/**
 * brief: 添加联系人功能
 * arg: 通信录map
 * return: none
 * note: 写入失败会打印提示信息
 */
void addContacts(map<string, Friend>&);

/**
 * brief: 删除联系人功能
 * arg: 通信录map
 * return: none
 * note: 删除失败会打印提示信息
 */
void deleteContacts(map<string, Friend>&);

/**
 * brief: 根据手机号查找联系人信息
 * arg: 通信录map
 * return: none
 * note: 
 */
void searchContacts(map<string, Friend>&);

#endif