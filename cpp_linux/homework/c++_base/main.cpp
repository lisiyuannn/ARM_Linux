#include <iostream>
using namespace std;

int main()
{
	string name;
	cout << "What is your name? " << endl;
	cout << " > ";
	cin >> name;
	cout << "Your name is " << name << endl;

	unsigned short data = 65535;
	data++;
	cout << data << endl;
	data++;
	cout << data << endl;

	return 0;
}
