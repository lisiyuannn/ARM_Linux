#include <iostream>
#include "operation.h"
#include "friend.h"
using namespace std;

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
    //打印已有的通讯录信息
    for(auto contact:contacts)
    {
        cout << contact.second.getName() << ": "
        << contact.second.getPhone() << ", "
        << contact.second.getAddress() << endl;
    }
    //向通讯录中添加好友信息
    int choice;
    do
    {
        cout << "通讯录工具" << endl;
        cout << "1、添加好友" << endl;
        cout << "2、删除好友" << endl;
        cout << "3、修改信息" << endl;
        cout << "4、查找信息" << endl;
        cout << "5、保存信息" << endl;
        cout << "6、重新加载" << endl;
        cout << "7、保存退出" << endl;
        cout << "请选择操作: " << "\n" << ">";
        cin >> choice;
        switch(choice)
        {
            case 1:
                addContacts(contacts);
                break;
            case 2:
                deleteContacts(contacts);
                break;
            case 3:

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
                break;
            case 7:
                saveContacts(contacts);
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
