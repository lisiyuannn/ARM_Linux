#include <iostream>
#include <limits>
#include <cstdlib>
#include "operation.h"
#include "friend.h"
using namespace std;

void showMenu();

int main(int argc, char const *argv[])
{
    //打开文件，读取文件中已有的联系人信息
    map<string, Friend> contacts;
    try
    {
        loadContacts(contacts);
    }
    catch(const runtime_error& e)
    {
        cerr << e.what() << endl;
    }
    
    int choice;
    do
    {
        showMenu();
        cout << "请选择操作: " << "\n" << ">";
        if (!(cin >> choice))
        {
            cin.clear();  // 清除错误状态
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 忽略无效输入
            continue;
        }
        switch(choice)
        {
            case 1:
                addContacts(contacts);
                break;
            case 2:
                deleteContacts(contacts);
                break;
            case 3:
                modifyContacts(contacts);
                break;
            case 4:
                searchContacts(contacts);
                break;
            case 5:
                try
                {
                    saveContacts(contacts);
                }
                catch(const std::runtime_error& e)
                {
                    std::cerr << e.what() << '\n';
                }
                break;
            case 6:
                showFriends(contacts);
                break;
            case 7:
                try
                {
                    saveContacts(contacts);
                }
                catch(const std::runtime_error& e)
                {
                    std::cerr << e.what() << '\n';
                    return 0;
                }
                return 0;
                break;
            default:
                cout << "输入错误，请重新输入！" << endl;
                break;

        }
    }
    while (choice != 7);

    return 0;
}


void showMenu()
{
    system("clear");

    cout << "通讯录工具" << endl;
    cout << "1、添加好友" << endl;
    cout << "2、删除好友" << endl;
    cout << "3、修改信息" << endl;
    cout << "4、查找信息" << endl;
    cout << "5、保存信息" << endl;
    cout << "6、显示全部联系人" << endl;
    cout << "7、保存退出" << endl;
}