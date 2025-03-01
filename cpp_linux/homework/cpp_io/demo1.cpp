/*
    文本文件a.txt中的内容复制到文本文件b.txt
*/
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[])
{
    //检车主函数参数
    if(argc < 3)
    {
        cout << "please input source_filename target_filename!" << endl;
        return 1;
    }

    //打开源文件和目标文件
    ifstream sourcefile;
    sourcefile.open(argv[1], ios_base::binary);
    if(!sourcefile)
    {
        cout << "source file open failed!" << endl;
        return 1;
    }
    ofstream targetfile;
    targetfile.open(argv[2], ios_base::binary);
    if(!targetfile)
    {
        cout << "target file open failed!" << endl;
        return 1;
    }

    //创建缓冲区
    char buff[100];
    while(sourcefile.read(buff, sizeof(buff)))
    {
        targetfile.write(buff, sourcefile.gcount());
        if (!targetfile)
        {
            cout << "write to target file failed!" << endl;
            sourcefile.close();
            targetfile.close();
            return 1;
        }
    }

    //处理剩余数据
    if (sourcefile.gcount() > 0)
    {
        targetfile.write(buff, sourcefile.gcount());
        if (!targetfile)
        {
            cout << "write to target file failed!" << endl;
            sourcefile.close();
            targetfile.close();
            return 1;
        }
    }

    sourcefile.close();
    targetfile.close();

    return 0;
}
