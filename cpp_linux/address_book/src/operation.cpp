#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <limits>
#include <map>
using namespace std;

#include "operation.h"
#include "friend.h"

void pressAnyKeyToContinue() {
    std::cout << "按任意键继续..." << std::endl;
    // 清除输入缓冲区
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // 等待用户输入一个字符
    std::cin.get();
}

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
        file << pair.second.getName() << ": " 
        << pair.second.getPhone() << ", "
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
        ss.clear();
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
    system("clear");
    string token;
    Friend f;
    cout << "请输入联系人姓名:" << "\n" << ">";
    cin >> token;
    if(token.length() > 12)
    {
        cout << "姓名过长，添加失败！" << endl;
        pressAnyKeyToContinue();
        return;
    }
    if(token.length() == 0)
    {
        cout << "姓名不能为空，添加失败！" << endl;
        pressAnyKeyToContinue();
        return;
    }
    f.setName(token);
    cout << "请输入联系人电话:" << "\n" << ">";
    cin >> token;
    if(token.length() > 11)
    {
        cout << "电话不合法，添加失败！" << endl;
        pressAnyKeyToContinue();
        return;
    }
    if(token.length() == 0)
    {
        cout << "电话不能为空，添加失败！" << endl;
        pressAnyKeyToContinue();
        return;
    }
    f.setPhone(token);
    cout << "请输入联系人地址:" << "\n" << ">";
    cin >> token;
    f.setAddress(token);

    cout << "联系人插入成功！" << endl;

    //只做插入，不做修改，如果通信录中已经存在该手机号，则报错
    auto pair = contacts.insert(make_pair(f.getPhone(), f));
    if(!pair.second)
    {
        cout << "contacts insert failed!" << endl;
    }
    pressAnyKeyToContinue();
}

void deleteContacts(map<string, Friend>& contacts)
{
    system("clear");
    string phone;
    cout << "请输入要删除的联系人电话：" << "\n" << ">";
    cin >> phone;
    if(contacts.erase(phone) == 1)
    {
        cout << "该联系人信息已经删除！" << endl;
    }
    else cout << "删除失败，联系人不存在！" << endl;
    pressAnyKeyToContinue();
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
        pressAnyKeyToContinue();
    }
    else
    {
        //找到了
        cout << "查询结果：\n";
        cout << setw(12) << it->second.getName() << ": " 
        << setw(11) << it->second.getPhone() << ", "
        << it->second.getAddress() << endl; 
    }
    //清空输入流
    cin.ignore();
    pressAnyKeyToContinue();
}

void showFriends(map<string, Friend>& contacts)
{
    system("clear");
    //打印已有的通讯录信息
    for(auto contact:contacts)
    {
        cout << setw(12) << contact.second.getName() << ": "
        << setw(11) << contact.second.getPhone() << ", "
        << contact.second.getAddress() << endl;
    }
    pressAnyKeyToContinue();
}

void modifyContacts(map<string, Friend>& contacts)
{
    system("clear");
    string phone;
    cout << "请输入想要修改的联系人号码：" << endl;
    cout << "> ";
    cin >> phone;
    auto it = contacts.find(phone);
    if(it != contacts.end())
    {
        //找到了，修改信息
        string token;
        cout << "请输入联系人姓名：" << endl;
        cout << "> ";
        cin >> token;
        if(token.length() > 12)
        {
            cout << "姓名过长，添加失败！" << endl;
            pressAnyKeyToContinue();
            return;
        }
        if(token.length() == 0)
        {
            cout << "姓名不能为空，添加失败！" << endl;
            pressAnyKeyToContinue();
            return;
        }
        it->second.setName(token);
        cout << "请输入联系人地址：" << endl;
        cout << "> ";
        cin >> token;
        it->second.setAddress(token);
        cout << "联系人信息已修改！" << endl;
    }
    else
    {
        //没找到，打印提示信息
        cout << "号码错误，请核对后重新输入！" << endl;
    }
    //清空输入流
    cin.ignore();
    pressAnyKeyToContinue();
}

