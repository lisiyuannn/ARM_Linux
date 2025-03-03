#include <iostream>
#include <random>
using namespace std;

class Person
{
private:
    string name;
    int age;
    bool sex;
public:
    Person()
    {
        cout << "Person()" << endl;
    }
    Person(string name, int age, bool sex)
        :name(name), age(age), sex(sex)
    {
        cout << "Person(string, int, bool)" << endl;
    }
    virtual ~Person()
    {
        cout << "~Person" << endl;
    }

    void setName(const string& name)
    {
        this->name = name;
    }
    string getName() const
    {
        return this->name;
    }

    void setAge(const int& age)
    {
        this->age = age;
    }
    int getAge() const
    {
        return this->age;
    }

    void setSex(const bool& sex)
    {
        this->sex = sex;
    }
    bool getSex() const
    {
        return this->sex;
    }
};

class Runnable
{
public:
    virtual void run() = 0;
    virtual ~Runnable(){}
};

class Athlete: public Person, public Runnable
{
public:
    Athlete():Person()
    {
        cout << "Athlete()" << endl;
    }
    Athlete(string name, int age, bool sex)
        :Person(name, age, sex)
    {
        cout << "Athlete(string, int, bool)" << endl;  
    }
    ~Athlete()
    {
        cout << "~Athlete()" << endl;
    }
    virtual void run() override
    {
        //生成随机数
        random_device rd;
        mt19937 gen(rd());
        //随机数分布在20-30之间
        uniform_int_distribution<> dis(20, 30);
        int speed = dis(gen);

        cout << this->getName() << ": " << speed << endl;
    }
};

int main(int argc, char const *argv[])
{
    Person * p1 = new Athlete("Tom", 18, 1);
    Runnable * p2 = new Athlete("Jacy", 22, 0);
    /*
     * 使用p1无法调用run()函数，因为在Person类中并没有这个函数 
     */
    //p1->run();
    p2->run();
    delete p1;
    delete p2;
    return 0;
}
