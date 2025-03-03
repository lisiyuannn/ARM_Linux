#include <iostream>
using namespace std;

class Date
{
private:
    int year;
    int month;
    int day;
public:
    Date()
    {
        year = 2010;
        month = 6;
        day = 17;
        cout << "Date()" << endl;
    }
    Date(int year, int month, int day)
        :year(year), month(month), day(day)
    {
        cout << "Date(int, int, int)" << endl;
    }
    ~Date()
    {
        cout << "~Date()" << endl;
    }

    void Display()
    {
        cout << year << " 年" << month << " 月" << day << " 日" << endl;
    }

    friend ostream& operator<<(ostream& os, const Date& d);
};

ostream& operator<<(ostream& os, const Date& d)
{
    os << d.year << " /" << d.month << " /" << d.day << endl;
    return os;
}

int main(int argc, char const *argv[])
{
    Date d1;
    Date d2(2025, 3, 3);
    Date d3(d2);

    d1.Display();
    cout << d1 << endl;
    d2.Display();
    cout << d2 << endl;
    d3.Display();
    cout << d3 << endl;

    return 0;
}
