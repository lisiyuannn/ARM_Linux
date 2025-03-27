#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <unistd.h>
using namespace std;

class ReaderWriter
{
private:
    int data;   //存放要读写的数据
    int writer_wait;
    int reader_wait;
    mutex w_mutex;
    mutex r_mutex;
    condition_variable w_cond;
    condition_variable r_cond;

    mutex mtx;  //保护要读写的数据
private:
    void write_data(int value)
    {
        unique_lock<mutex> lock(mtx);
        data = value;
        cout << "write_data: " << data << endl;  
        //离开作用域时会自动解锁，无需手动释放锁
    }

    int read_data()
    {
        unique_lock<mutex> lock(mtx);
        cout << "read_data: " << data << endl;
        return data;
        //离开作用域时会自动解锁，无需手动释放锁
    }

public:
    ReaderWriter():data(0), writer_wait(0), reader_wait(0)
    {
        //mutex和condition_variable的构造函数是默认构造函数，不需要额外操作
    }
    
    //析构函数会自动生成

    //写线程函数
    void writer()
    {
        for(int i = 0; i < 100; ++i)
        {
            //首先写数据
            write_data(i+100);
            cout << "writer: " << i+100 << endl;
            usleep(100000);     //模拟线程其他操作
            //唤醒所有读线程
            r_mutex.lock();
            while(!reader_wait)
            {
                r_mutex.unlock();
                usleep(100000);
                r_mutex.lock();
            }
            //程序走到这里说明有读线程已经准备好，唤醒它
            r_cond.notify_one();
            reader_wait = 0;
            r_mutex.unlock();
            //自己进入等待队列
            {
                unique_lock<mutex> w_lock(w_mutex);
                writer_wait = 1;
                w_cond.wait(w_lock, [this]{return!writer_wait;});
            }
        }
    }

    //读线程函数
    void reader()
    {
        for(int i = 0; i < 100; ++i)
        {
            //先表示自己已经准备好读数据，然后进入等待队列等待被唤起
            {
                unique_lock<mutex> r_lock(r_mutex);
                reader_wait = 1;
                r_cond.wait(r_lock, [this]{return !reader_wait;});
            }

            //程序走到这里说明读线程被唤起，已经有数据等待读取了

            cout << "reader read data : " << read_data() << endl;
            usleep(10000);  //模拟线程其他操作

            //读完之后唤起写线程起来写数据
            w_mutex.lock();
            while(!writer_wait)
            {
                w_mutex.unlock();
                usleep(100000);
                w_mutex.lock();
            }
            //程序走到这里说明写线程已经准备好，唤醒它
            w_cond.notify_one();
            writer_wait = 0;
            w_mutex.unlock();
            
        }
    }

};


int main(int argc, char const *argv[])
{
    ReaderWriter rw;

    //创建写线程和读线程
    thread writer_thread(&ReaderWriter::writer, &rw);
    thread reader_thread(&ReaderWriter::reader, &rw);

    //等待线程结束
    writer_thread.join();
    reader_thread.join();
    return 0;
}
