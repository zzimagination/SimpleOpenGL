// TestConsoleApplication.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <vector>
#include <iostream>

using namespace std;


class Testa {

public:
	string str;
};

int main()
{
	int nums[] = { 1,2,3,4 };
	char str[] = "asdasdasd";
	char* s = str;
	cout << *(nums+2) << endl;
	//cout <<&t1<<" " << t1->str.c_str()<<"  " << &t1->str << endl;
	//cout <<&t2<<" "<< t2->str.c_str()<<"  "<< &t2->str << endl;

	return 0;
}

