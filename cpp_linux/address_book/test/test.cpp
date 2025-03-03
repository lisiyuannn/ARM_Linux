#include <iostream>
#include <sstream>
using namespace std;

/**
 * 从字符串中提取单词测试
 */
int main()
{
    string f("TOM: 13167729009, LIXIN");
    stringstream ss;
    string token;
    ss.str("");
    ss.str(f);
    cout << ss.str() << endl;

    getline(ss, token, ':');
    cout << "***" << token << "***" << endl;
    ss.ignore();
    getline(ss, token, ',');
    cout << "***" << token << "***" << endl;
    ss.ignore();
    getline(ss, token);
    cout << "***" << token << "***" << endl;

    return 0;
    
}
