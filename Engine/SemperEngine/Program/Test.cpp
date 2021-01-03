#include "Test.h"
#include <iostream>
#include "ObjectCollection.h"

using namespace std;
using namespace SemperEngine::Collection;


void Test::UnitTesting()
{
	cout << "unit test start" << endl;

	ObjectCollection<int> c;
	int *p1 = new int(1);
	int *p2 = new int(2);
	int *p3 = new int(3);
	int *p4 = new int(4);
	int *p5 = new int(5);
	int *p6 = new int(6);
	int *p7 = new int(7);
	c.Add(p1);
	c.Add(p2);
	c.Add(p3);
	c.Add(p4);
	c.Add(p5);
	c.Add(p6);
	c.Add(p7);
	while (true)
	{
		auto object = c.Next();
		if (object == nullptr)
		{
			break;
		}
		if (*object == 4)
		{
			c.Remove(p6);
		}
	}
}
