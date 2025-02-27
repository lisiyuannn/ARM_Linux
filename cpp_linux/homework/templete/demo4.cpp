#include <iostream>
using namespace std;

template<typename T>
class MyList
{
    private:
        T* data;
        size_t size;
        size_t capacity;

        //扩容函数
        void reserve(size_t new_capacity)
        {
            T* new_data = new T[new_capacity];
            for (size_t i = 0; i < size; ++i) 
            {
                new_data[i] = data[i];
            }
            
            delete[] this->data;
            data = new_data;
            this->capacity = new_capacity;
        }
    public:
        MyList(): data(nullptr), size(0), capacity(0){};
        //拷贝构造函数，注意需要深拷贝
        MyList(const MyList& other)
            : data(nullptr), size(other->size), capacity(other->capacity)
        {
            reserve(other.capacity_);
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }

        MyList& operator=(const MyList& other)
        {
            if (this != &other) {
                delete[] data;
                capacity = 0;
                size = 0;
                reserve(other.capacity);
                this->size = other.size;
                this->capacity = other.capacity;
                for (size_t i = 0; i < this->size; ++i) {
                    data[i] = other.data[i];
                }
            }
            return *this;
        }

        ~MyList()
        {
            delete[] this->data;
        }

        //尾部添加元素
        void push_back(const T& newData)
        {
            if(this->size >= this->capacity)
            {
                this->reserve(capacity+100);
            }
            this->data[size++] = newData;
        }

        //删除指定位置元素
        void erase(int i)
        {
            if((i < 0)||(i > size))
            {
                cout << "erase error" << endl;
            }
            else
            {
                for(int j = i; j < size-1; ++j)
                {
                    data[j] = data[j+1];
                }
            }
            size--;
        }

        //修改指定下标元素
        void alter(int i, const T& newData)
        {
            if((i < 0)||(i >= size))
            {
                cout << "alter error" << endl;
            }
            else
            {
                data[i] = newData;
            }
        }

        //查找指定元素，找到返回下标，否则返回-1
        int find(const T& value)
        {
            if(size <= 0)
            {
                return -1;
            }
            else
            {
                for(int i = 0; i < size; ++i)
                {
                    if(data[i] == value) return i;
                }
                return -1;
            }
        }

        //获取size
        int getSize()
        {
            return this->size;
        }

        //获取capacity
        int getCapacity()
        {
            return this->capacity;
        }

        void myPrint()
        {
            if(size <= 0)
            {
                cout << "No data!";
            }
            for(int i = 0; i < size; ++i)
            {
                cout << data[i] << " ";
            }
            cout << endl;
        }
};

int main()
{
    
    MyList<int> list;
    list.push_back(1);
    list.push_back(12);
    list.push_back(3);
    list.push_back(6);
    list.push_back(2);

    list.myPrint();
    cout << list.getSize() << endl;
    cout << list.getCapacity() << endl;

    list.erase(2);
    list.myPrint();

    int newvalue = 999;
    list.alter(4, newvalue);
    list.alter(3, 999);
    list.myPrint();

    cout << list.find(3) << endl;
    return 0;
}
