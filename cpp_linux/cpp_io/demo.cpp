#include <iostream>
//using namespace std;

/*
******************************进制修饰符******************************
    */
// int main(int argc, char const *argv[])
// {
//     int num = 123;

//     std::cout << std::dec << num << std::endl;      //十进制
//     std::cout << std::oct << num << std::endl;      //八进制
//     std::cout << std::hex << num << std::endl;      //十六进制

//     //输出16进制，并且显示0x
//     std::cout << std::hex << std::showbase << num << std::endl;
//     return 0;
// }

/*
************************使用width控制输出宽度***************************
    */
#include <iomanip>
// int main(int argc, char const *argv[])
// {
//     double nums[] = {1.23, 2.234, 233.235, 2143.3234};
//     for(int i = 0; i < 4; ++i)
//     {
//         std::cout << '|';
//         //控制下一次输出的输出宽度
//         std::cout.width(10);
//         //数据不满足宽度的话使用字符填充
//         std::cout << std::setfill('*') << 
//         nums[i] << '|' << std::endl;    //cout最多显示6位有效数字
//     }
//     std::cout << "******************************" << std::endl;
//     for(int i = 0; i < 4; ++i)
//     {
//         std::cout << '|';
//         //控制下一次输出的输出宽度
//         std::cout.width(10);
//         //数据不满足宽度的话使用字符填充
//         std::cout << std::setfill('*') << std::setprecision(10) <<
//         nums[i] << '|' << std::endl;    //cout最多显示6位有效数字
//     }
//     return 0;
// }


/*
************************使用setw控制输出宽度***************************
    */
// int main(int argc, char const *argv[])
// {
//     double nums[] = {1.23, 2.234, 233.235, 2143.3234};
//     char name[4][10] = {"Sdgf", "Sj", "Jimme", "Bob"};

//     //设置为科学计数法输出
//     std::cout << std::setiosflags(std::ios::scientific);

//     for(int i = 0; i < 4; i++)
//     {
//         std::cout << std::setw(6) << name[i] << 
//         std::setw(6) << nums[i] << std::endl;
//     }

//     //设置为科学计数法输出
//     std::cout << std::resetiosflags(std::ios::scientific);

//     //设置和取消对其方式
//     for(int i = 0; i < 4; ++i)
//     {
//         std::cout << std::setiosflags(std::ios::left) << std::setw(6) << name[i] << 
//         std::resetiosflags(std::ios::left) << std::setw(10) << nums[i] << std::endl;
//     }
//     return 0;
// }


/*
************************文件输出流ofstream***************************
    */
// #include <fstream>

// struct Data
// {
//     int mo, da, yr;
// };

// int main(int argc, char const *argv[])
// {

//     Data dt = {6, 10, 92};
//     std::ofstream tfile("./test.txt");
//     if(tfile)
//     {
//         std::cout << "file open success" << std::endl;
//         //写入单个字符
//         tfile.put('W');
//         tfile.put('\n');

//         //使用write方法将内存的一块内容写入到一个文件输入流中
//         tfile.write((char*)&dt, sizeof(dt));
//     }
//     tfile.close();
//     return 0;
// }
   
/*
************************文件输入流ifstream***************************
    */
#include <fstream>
using namespace std;
//写入文件
void output()
{
    ofstream os("test.txt");
    string line;
    if(os)
    {
        cout << "成功打开文件" << endl;
        while(getline(cin, line))
        {
            if(line == "quit")
            {
                cout << "写入完毕" << endl;
                break;
            }
            os << line << endl;
        }
    }
    os.close();
}

void input()
{
    ifstream is("test.txt");
    string line;
    if(is)
    {
        cout << "文件打开成功" << endl;
        while(getline(is, line))
        {
            cout << line << endl;
        }
        is.close();
    }
}

int main(int argc, char const *argv[])
{
    cout << "请输入几行数据" << endl;
    output();
    input();
    return 0;
}
