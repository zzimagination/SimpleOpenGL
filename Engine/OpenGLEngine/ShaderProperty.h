#ifndef SHADER_PROPERTY
#define SHADER_PROPERTY

#include <vector>

using namespace std;

template<class T>
class ShaderProperty
{
private:

	vector<T> data;

	vector<string> name;

public:

	void Add(string name, T value)
	{
		for (int i = 0; i < data.size(); i++)
		{
			if (this->name[i] == name)
			{
				data[i] = value;
				return;
			}
		}
		this->name.push_back(name);
		this->data.push_back(value);
	}

	void Remove(string name, T value)
	{
		for (int i = 0; i < data.size(); i++)
		{
			if (this->name[i] == name)
			{
				this->name.erase(this.name.begin() + i);
				this->data.erase(data.begin() + i);
				return;
			}
		}
		throw "don't have " + name;
	}

	string GetName(int i)
	{
		return name[i];
	}

	T GetValue(int i)
	{
		return data[i];
	}

	int Size()
	{
		if (name.size() != data.size())
		{
			throw "value error";
		}
		return (int)name.size();
	}
};

#endif // !SHADER_PROPERTY

