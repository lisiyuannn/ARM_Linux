#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <map>
using namespace std;

#include "operation.h"
#include "friend.h"

void saveContacts(const map<string, Friend>& contacts)
{
    //首先打开文件
    ofstream file(FRIEND_FILE);
    if(!file)
    {
        throw runtime_error("ofstream file open failed!");
    }
    for(auto &pair:contacts)
    {
        file << setw(12) << pair.second.getName() << ": " 
        << setw(11) << pair.second.getPhone() << ", "
        << pair.second.getAddress() << endl;                     
    }
    file.close();
}

void loadContacts(map<string, Friend>& contacts)
{
    //首先打开文件
    ifstream file(FRIEND_FILE);
    if(!file)
    {
        throw runtime_error("ifstream file open failed!");
    }
    string line;    //每次读出一行数据
    string token;   
    Friend f;       //新建对象在栈中
    stringstream ss;
    while(getline(file, line))
    {
        ss.str("");
        ss.str(line);

        //开始提取数据
        if(getline(ss, token, ':')) f.setName(token);
        //忽略下一个空格
        ss.ignore();
        if(getline(ss, token, ',')) f.setPhone(token);
        ss.ignore();
        if(getline(ss, token)) f.setAddress(token);
        
        //手机号为键值，对象为数据，插入contacts
        contacts[f.getPhone()] = f;
    }
    file.close();
}

void addContacts(map<string, Friend>& contacts)
{
    string token;
    Friend f;
    cout << "请输入联系人姓名:" << "\n" << ">";
    cin >> token;
    f.setName(token);
    cout << "请输入联系人电话:" << "\n" << ">";
    cin >> token;
    f.setPhone(token);
    cout << "请输入联系人地址:" << "\n" << ">";
    cin >> token;
    f.setAddress(token);

    //只做插入，不做修改，如果通信录中已经存在该手机号，则报错
    auto pair = contacts.insert(make_pair(f.getPhone(), f));
    if(!pair.second)
    {
        cout << "contacts insert failed!" << endl;
    }
}

void deleteContacts(map<string, Friend>& contacts)
{
    string phone;
    cout << "请输入要删除的联系人电话：" << "\n" << ">";
    cin >> phone;
    if(contacts.erase(phone) == 1)
    {
        cout << "该联系人信息已经删除！" << endl;
    }
    else cout << "删除失败，联系人不存在！" << endl;
}

void searchContacts(map<string, Friend>& contacts)
{
    string phone;
    cout << "请输入要查询的手机号：" << "\n" << ">";
    cin >> phone;
    //使用迭代器存放map查询结果
    map<string, Friend>::iterator it = contacts.find(phone);
    if(it == contacts.end())
    {
        //没有找到
        cout << "没有你要查询的手机号！" << endl;
    }
    else
    {
        //找到了
        cout << "查询结果：\n";
        cout << setw(12) << it->second.getName() << ": " 
        << setw(11) << it->second.getPhone() << ", "
        << it->second.getAddress() << endl; 
    }
}