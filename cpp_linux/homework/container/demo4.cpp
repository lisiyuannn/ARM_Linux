#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int> test;

	test.insert(1);
	test.insert(2);
	test.insert(3);
	test.insert(1);

	cout << "1出现了" << test.count(1) << "次" << endl;

	//第一种方法
	for(auto i:test)
	{
		if(i > 1) 
		{
			cout << "第一个大于1的数是：" << i << endl;
			break;
		}
		
	}
	//第二种方法
	auto it = test.upper_bound(1);
    if (it != test.end()) {
        std::cout << "第一个大于 1 的数: " << *it << std::endl;
    } else {
        std::cout << "没有大于 1 的数。" << std::endl;
    }

	auto iter = test.find(2);
	if(iter == test.end())
	{
		cout << "没有找到" << endl;
	}
	else
	{
		test.erase(iter);
		cout << "找到了，已经删除" << endl;
	}

	auto res = test.insert(5);
	if(res.second)
	{
		cout << "成功插入" << endl;
	}
	else
	{
		cout << "插入失败" << endl;
	}



	return 0;
}
