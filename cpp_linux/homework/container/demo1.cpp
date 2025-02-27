#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void myPrint(int num)
{
	cout << num << " ";
}

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	v.push_back(3);
	v.push_back(3);

	for(auto i:v)
	{
		cout << i << " ";
	}
	cout << endl;

	set<int> s(v.begin(), v.end());
	for_each(s.begin(), s.end(), myPrint);
	cout << endl;
	
	return 0;
}
