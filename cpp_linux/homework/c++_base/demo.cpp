#include <iostream>
#include <string>
using namespace std;

typedef struct
{
	string name;
	int age;
	string address;
	float score;
}student;

int main()
{
	cout << "size of the struct student is " << sizeof(student) << endl;

	student s1;
	cout << "please input the student info:" <<  endl;
	cout << "name: " << endl;
	cin >> s1.name;
	cout << "age: " << endl;
	cin >> s1.age;
	cout << "address: " << endl;
	cin >> s1.address;
	cout << "score: " << endl;
	cin >> s1.score;

	cout << s1.name << " is live in " << s1.address 
	<< " " << s1.age << " years old this year, and he is live in" 
	<< s1.address << endl; 
	
	return 0;
}
