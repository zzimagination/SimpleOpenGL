// TestConsoleApplication.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <vector>
#include <iostream>

using namespace std;
class MyClass
{
public:
	MyClass(){}
	~MyClass(){}

	int v;


private:

};
int main()
{
	MyClass* m1 = new MyClass();
	m1->v = 10;
	MyClass* m2 = new MyClass();
	m2->v = 10;
	MyClass* m3 = new MyClass();
	m3->v = 10;
	vector<MyClass*> a = { m1,m2,m3 };

	for (vector<MyClass*>::iterator it = a.begin(); it != a.end(); it++)
	{
		MyClass* i = *it;
		cout << i->v << endl;
	}

	int l;
	std::cin >> l;
	return 0;
}

