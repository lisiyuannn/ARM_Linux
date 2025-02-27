#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

class Student
{
	private:
		int id;
		string name;
	public:
		Student():id(0), name(""){}
		Student(int id, string name)
			:id(id), name(name){}
		void setId(int id)
		{
			this->id = id;
		}
		int getId()const
		{
			return id;
		}
		void setName(string name)
		{
			this->name = name;
		}
		string getName()const
		{
			return name;
		}
		//升序排列
		bool operator<(const Student &s)const
		{
			return this->id < s.id;
		}
};

ostream& operator<<(ostream& os, const Student& s)
{
    os << "ID: " << s.getId() << ", Name: " << s.getName();
    return os;
}

//降序排列
class MyCompare
{
	public:
		bool operator()(const Student& s1, const Student& s2)const
		{
			return s1.getId() > s2.getId();
		}
};

void myPrint(const pair<const Student, const double>& pair)
{
	cout << pair.first << "\t:" << pair.second << endl;
}

int main()
{
	Student s1(1, "Aoa");
	Student s2(3, "Boa");
	Student s3(2, "Coa");
	Student s4(5, "Doa");
	Student s5(4, "Eoa");

	map<Student, double> m1;
	m1.insert(pair<Student, double>(s1, 32.54));
	m1.insert(make_pair(s2, 223.3));
	m1.insert(make_pair(s3, 232.4));
	m1.insert(make_pair(s4, 33.4));
	m1.insert(make_pair(s5, 213.6));

	for_each(m1.begin(), m1.end(), myPrint);

	cout << "===============================" << endl;

	map<Student, double, MyCompare> m2;
	m2.insert(pair<Student, double>(s1, 32.54));
	m2.insert(make_pair(s2, 223.3));
	m2.insert(make_pair(s3, 232.4));
	m2.insert(make_pair(s4, 33.4));
	m2.insert(make_pair(s5, 213.6));

	for_each(m2.begin(), m2.end(), myPrint);
	return 0;
}
